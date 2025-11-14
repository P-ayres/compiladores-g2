%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* yyout vem do main.c (arquivo de saída) */
extern FILE* yyout;

/* ===== Helpers de string para geração de código ===== */
static char* strclone(const char* s){ if(!s) return NULL; size_t n=strlen(s); char* r=(char*)malloc(n+1); memcpy(r,s,n+1); return r; }
static char* cat2(const char* a,const char* b){ size_t na=a?strlen(a):0, nb=b?strlen(b):0; char* r=(char*)malloc(na+nb+1); if(a) memcpy(r,a,na); if(b) memcpy(r+na,b,nb); r[na+nb]='\0'; return r; }
static char* cat3(const char* a,const char* b,const char* c){ char* t=cat2(a,b); char* r=cat2(t,c); free(t); return r; }
static void append(char** base, const char* add){ char* t=cat2(*base?*base:"", add?add:""); if(*base) free(*base); *base=t; }

/* Indenta todas as linhas de s com `spaces` espaços, devolve nova string */
static char* indent_text(const char* s, int spaces){
    if(!s) return NULL;
    size_t len = strlen(s);
    /* contador de linhas para estimativa */
    size_t extra = 0;
    for(const char* q = s; *q; ++q) if(*q == '\n') extra++;
    int sp = spaces;
    /* cria prefixo */
    char* prefix = (char*)malloc(sp+1);
    for(int i=0;i<sp;i++) prefix[i]=' ';
    prefix[sp]='\0';
    /* construir resultado: à cada linha não-vazia, adicionar prefixo */
    char* out = (char*)malloc(len + extra*sp + 1 + 16);
    out[0] = '\0';
    char linebuf[4096];
    const char* start = s;
    while(*start){
        const char* nl = strchr(start, '\n');
        size_t linelen;
        if(nl) linelen = nl - start;
        else linelen = strlen(start);
        if(linelen == 0){
            /* linha vazia: apenas adiciona '\n' */
            if(nl){
                strcat(out, "\n");
                start = nl + 1;
                continue;
            } else break;
        }

        if(linelen >= sizeof(linebuf)-1) linelen = sizeof(linebuf)-2;
        memcpy(linebuf, start, linelen);
        linebuf[linelen] = '\0';
        /* concat prefix + linha + '\n' (se houver) */
        char* t = cat3(prefix, linebuf, nl ? "\n" : "");
        char* old = out;
        out = cat2(out, t);
        free(old);
        free(t);
        if(nl) start = nl + 1;
        else break;
    }
    free(prefix);
    return out;
}

/* Indentação */
static char* indent_once(const char* s){ return indent_text(s, 4); }

/* Acumulador do resultado final */
static char* G_OUT = NULL;

int yylex(void);
void yyerror(const char* s){ fprintf(stderr,"[syntax] %s\n", s); }
%}

/* ===== Tipos de valor semântico ===== */
%union {
  char* str;
  int num;
  }

/* ===== Tokens vindos do lexer.l ===== */
%token TRAINER POKEBALL BATTLE ELSE TALLGRASS JOURNEY SHOUT EVOLVE TRUE FALSE
%token <str> IDENT NUMBER STRING
%token EQ NE LE GE AND OR

/* ===== Tipos associados às regras ===== */
%type  <str> program items item
%type  <str> func_decl param_list opt_param_list
%type  <str> block var_decl stmt print if_stmt while_stmt for_stmt for_init return_stmt
%type  <str> expr call primary opt_else arg_list opt_arg_list

/* ===== Precedência ===== */
%right '='
%left  OR
%left  AND
%left  EQ NE
%left  '<' '>' LE GE
%left  '+' '-'
%left  '*' '/' '%'
%right UMINUS NOT

%%

program
  : items {
      append(&G_OUT, $1);
      if (!yyout) yyout = stdout;
      fprintf(yyout, "%s", G_OUT ? G_OUT : "");
      free(G_OUT); G_OUT = NULL;
      free($1);
    }
  ;

items
  : items item           { $$ = cat2($1, $2); free($1); free($2); }
  | item                 { $$ = $1; }
  ;

item
  : func_decl            { $$ = $1; }
  | var_decl             { $$ = $1; }
  | stmt                 { $$ = $1; }
  | ';'                  { $$ = strclone(""); }
  ;

/* trainer nome { ... } → def nome */
func_decl
  : TRAINER IDENT '(' opt_param_list ')' block
      {
        char* hdr;
        if ($4)
            hdr = cat3("def ", $2, "(");
        else
            hdr = cat3("def ", $2, "(");
        char* hdr2 = cat3(hdr, $4 ? $4 : "", "):\n");
        /* block já vem indentado uma vez */
        char* all  = cat2(hdr2, $6 ? $6 : "");
        $$ = all;
        free(hdr); free(hdr2);
        free($2); if($4) free($4); if($6) free($6);
      }
  ;

opt_param_list
  : /* vazio */          { $$ = NULL; }
  | param_list           { $$ = $1; }
  ;

param_list
  : IDENT                { $$ = $1; }
  | param_list ',' IDENT { char* t = cat3($1, ", ", $3); free($1); free($3); $$ = t; }
  ;

/* pokeball x = expr; → x = expr */
var_decl
  : POKEBALL IDENT '=' expr ';'
      { char* t = cat3($2, " = ", $4); char* u = cat3(t, "\n", ""); free(t); free($2); free($4); $$ = u; }
  ;

/* { items } | {}  -> retorna o bloco indentado */
block
  : '{' items '}'      {
        char* in = $2; 
        if (!in) {
            /* bloco vazio => pass */
            $$ = strclone("    pass\n");
        } else {
            /* indentar o conteúdo uma vez */
            char* ind = indent_once(in);
            $$ = ind;
            free(in);
        }
    }
  | '{' '}'             { $$ = strclone("    pass\n"); }
  ;

/* Statements */

stmt
  : print                 { $$ = $1; }
  | if_stmt               { $$ = $1; }
  | while_stmt            { $$ = $1; }
  | for_stmt              { $$ = $1; }
  | return_stmt           { $$ = $1; }
  | expr                  { char* t = cat3($1, "\n", ""); free($1); $$ = t; }
  | block                 { $$ = $1; }
  ;

/* shout → print */

print
  : SHOUT '(' expr ')'
      { char* t = cat3("print(", $3, ")\n"); free($3); $$ = t; }
  ;

/* battle (cond) {...} [else {...}] → if cond:\n<block>[else:\n<block>] */

if_stmt
  : BATTLE '(' expr ')' block opt_else %prec BATTLE
      {
        char* hdr = cat3("if ", $3, ":\n");
        char* body = $5 ? $5 : strclone("    pass\n");
        char* mid;
        if ($6) {
            mid = cat2(hdr, body);
            char* all = cat2(mid, $6);
            $$ = all;
            free(mid);
            free(hdr); free(body); free($3); free($5); free($6);
        } else {
            mid = cat2(hdr, body);
            $$ = mid;
            free(hdr); free(body); free($3); free($5);
        }
      }
  ;

/* opt_else -> returns 'else' or NULL */
opt_else
  : /* vazio */          { $$ = NULL; }
  | ELSE block           {
        /* $2 já vem indentado (começa com 4 espaços) - queremos:
           else:
               <conteúdo do bloco>
        */
        char* hdr = strclone("else:\n");
        char* both = cat2(hdr, $2);
        free(hdr);
        $$ = both;
        free($2);
    }
  ;

/* tallgrass {...} → while */
while_stmt
  : TALLGRASS '(' expr ')' block
      {
        char* hdr = cat3("while ", $3, ":\n");
        char* body = $5 ? $5 : strclone("    pass\n");
        char* all = cat2(hdr, body);
        $$ = all;
        free(hdr); free(body); free($3); free($5);
      }
  ;

/* journey (for_init; cond; inc) block
   → init\nwhile cond:\n    <block>
   e insere inc como última linha do bloco (indentada)
*/

for_stmt
  : JOURNEY '(' for_init ';' expr ';' expr ')' block
      {
        /* $3 = init (string sem '\n' necessariamente), $5 = cond, $7 = inc, $9 = block (indentado) */
        char* init = $3 ? cat3($3, "\n", "") : strclone("");
        char* hdr = cat3("while ", $5, ":\n");
        char* body = $9 ? $9 : strclone("    pass\n");
        /* inserir inc como última instrução do bloco, indentada mais uma vez */
        char* incline = cat3($7, "\n", "");
        char* inc_ind = indent_once(incline); /* inc_ind já com 4 espaços */
        /* body já começa com 4 espaços; concatenar inc_ind ao final de body */
        char* body_with_inc = cat2(body, inc_ind);
        char* all_mid = cat2(hdr, body_with_inc);
        char* all = cat2(init, all_mid);
        $$ = all;
        free(init); free(hdr); free(body); free(incline); free(inc_ind); free(body_with_inc);
        free($3); free($5); free($7); if($9) free($9);
      }
  ;

/* for-init: pokeball i = expr  -> "i = expr" */
for_init
  : POKEBALL IDENT '=' expr
      { char* t = cat3($2, " = ", $4); free($2); free($4); $$ = t; }
  ;

/* evolve expr → return expr */
return_stmt
  : EVOLVE expr
      { char* t = cat3("return ", $2, "\n"); free($2); $$ = t; }
  ;

/* Expressões com precedência*/
expr
  : IDENT '=' expr       { char* t = cat3($1, " = ", $3); free($1); free($3); $$ = t; }

  | expr OR expr         { char* t = cat3($1, " or ", $3); free($1); free($3); $$ = t; }
  | expr AND expr        { char* t = cat3($1, " and ", $3); free($1); free($3); $$ = t; }
  | expr EQ expr         { char* t = cat3($1, " == ", $3); free($1); free($3); $$ = t; }
  | expr NE expr         { char* t = cat3($1, " != ", $3); free($1); free($3); $$ = t; }
  | expr '<' expr        { char* t = cat3($1, " < ",  $3); free($1); free($3); $$ = t; }
  | expr '>' expr        { char* t = cat3($1, " > ",  $3); free($1); free($3); $$ = t; }
  | expr LE expr         { char* t = cat3($1, " <= ", $3); free($1); free($3); $$ = t; }
  | expr GE expr         { char* t = cat3($1, " >= ", $3); free($1); free($3); $$ = t; }
  | expr '+' expr        { char* t = cat3($1, " + ",  $3); free($1); free($3); $$ = t; }
  | expr '-' expr        { char* t = cat3($1, " - ",  $3); free($1); free($3); $$ = t; }
  | expr '*' expr        { char* t = cat3($1, " * ",  $3); free($1); free($3); $$ = t; }
  | expr '/' expr        { char* t = cat3($1, " / ",  $3); free($1); free($3); $$ = t; }
  | expr '%' expr        { char* t = cat3($1, " % ",  $3); free($1); free($3); $$ = t; }

  | '-' expr %prec UMINUS{ char* t = cat3("-", $2, ""); free($2); $$ = t; }
  | '!' expr %prec NOT   { /* !x -> not x */ char* t = cat3("not ", $2, ""); free($2); $$ = t; }

  | call                 { $$ = $1; }
  | primary              { $$ = $1; }
  ;

call
  : IDENT '(' opt_arg_list ')'
      {
        char* t = cat3($1, "(", $3 ? $3 : "");
        char* u = cat3(t, ")", "");
        $$ = u; free(t); free($1); if($3) free($3);
      }
  ;

opt_arg_list
  : /* vazio */          { $$ = NULL; }
  | arg_list             { $$ = $1; }
  ;

arg_list
  : expr                 { $$ = $1; }
  | arg_list ',' expr    { char* t = cat3($1, ", ", $3); free($1); free($3); $$ = t; }
  ;

primary
  : NUMBER               { $$ = $1; }              /* já vem como texto: 42 ou 3.14 */
  | STRING               { $$ = $1; }              /* já vem com aspas: "pikachu"   */
  | TRUE                 { $$ = strclone("True"); }
  | FALSE                { $$ = strclone("False"); }
  | IDENT                { $$ = $1; }
  | '(' expr ')'         { char* t = cat3("(", $2, ")"); free($2); $$ = t; }
  ;

%%

