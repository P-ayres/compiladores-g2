%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* yyout vem do main.c (arquivo de saída) */
extern FILE* yyout;

/* ===== Helpers de string p/ “geração de código” ===== */
static char* strclone(const char* s){
    if(!s) return NULL;
    size_t n = strlen(s);
    char* r = (char*)malloc(n+1);
    memcpy(r, s, n+1);
    return r;
}

static char* cat2(const char* a,const char* b){
    size_t na = a ? strlen(a) : 0;
    size_t nb = b ? strlen(b) : 0;
    char* r = (char*)malloc(na + nb + 1);
    if(a) memcpy(r,     a,  na);
    if(b) memcpy(r+na,  b,  nb);
    r[na+nb] = '\0';
    return r;
}

static char* cat3(const char* a,const char* b,const char* c){
    char* t = cat2(a,b);
    char* r = cat2(t,c);
    free(t);
    return r;
}

static void append(char** base, const char* add){
    char* t = cat2(*base ? *base : "", add ? add : "");
    if(*base) free(*base);
    *base = t;
}

/* Indenta um bloco de código em 4 espaços por linha (para Python) */
static char* indent_block(const char* s){
    if(!s || !*s) return strclone("    pass\n"); /* bloco vazio → pass */

    size_t n = strlen(s);
    /* margem de segurança: até ~5x o tamanho original */
    char* r = (char*)malloc(n * 5 + 8);
    char* p = r;
    const char* q = s;

    /* primeira linha sempre começa indentada */
    *p++ = ' '; *p++ = ' '; *p++ = ' '; *p++ = ' ';

    for(; *q; ++q){
        *p++ = *q;
        if(*q == '\n' && *(q+1) != '\0'){
            *p++ = ' '; *p++ = ' '; *p++ = ' '; *p++ = ' ';
        }
    }

    *p = '\0';
    return r;
}

/* Acumulador do Python final */
static char* G_OUT = NULL;

int yylex(void);

/* Mensagem de erro mais “profissional”, com número da linha */
void yyerror(const char* s){
    extern int yylineno;
    fprintf(stderr,"[syntax] %s na linha %d\n", s, yylineno);
}
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
%type  <str> block var_decl stmt print if while for for_init return
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

/* Ponto de entrada: grava o Python em yyout e auto-executa main, se existir */
program
  : items {
      /* junta tudo gerado pelas regras */
      append(&G_OUT, $1);

      /* se houver uma função def main(...), adiciona auto-execução em Python */
      if (G_OUT && strstr(G_OUT, "def main(") != NULL) {
          append(&G_OUT, "\n\nif __name__ == '__main__':\n");
          append(&G_OUT, "    main()\n");
      }

      if (!yyout) yyout = stdout;
      fprintf(yyout, "%s\n", G_OUT ? G_OUT : "");
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
  ;

/* trainer nome(params) { ... } → def nome(params): ... */
func_decl
  : TRAINER IDENT '(' opt_param_list ')' block
      {
        /* $6 é o corpo sem chaves */
        char* body = indent_block($6);
        char* hdr  = cat3("def ", $2, "(");
        char* hdr2 = cat3(hdr, $4 ? $4 : "", "):\n");
        char* all  = cat2(hdr2, body);

        $$ = all;

        free(hdr);
        free(hdr2);
        free(body);
        free($2);
        if($4) free($4);
        if($6) free($6);
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
      {
        char* t = cat3($2, " = ", $4);
        char* u = cat2(t, "\n");
        free(t);
        free($2);
        free($4);
        $$ = u;
      }
  ;

/* { items } | {}  → em Python, só usamos o corpo */
block
  : '{' items '}'        { $$ = $2; }
  | '{' '}'              { $$ = NULL; }
  ;

stmt
  : print ';'            { char* t = cat2($1, "\n"); free($1); $$ = t; }
  | if                   { $$ = $1; }
  | while                { $$ = $1; }
  | for                  { $$ = $1; }
  | return ';'           { char* t = cat2($1, "\n"); free($1); $$ = t; }
  | expr ';'             { char* t = cat2($1, "\n"); free($1); $$ = t; }
  | block                { $$ = $1; }
  ;

/* shout(expr) → print(expr) */
print
  : SHOUT '(' expr ')'
      { char* t = cat3("print(", $3, ")"); free($3); $$ = t; }
  ;

/* battle (cond) {...} [else {...}] → if cond: ... [else: ...] */
if
  : BATTLE '(' expr ')' block opt_else
      {
        char* body = indent_block($5);
        char* hdr  = cat3("if ", $3, ":\n");
        char* u    = cat2(hdr, body);
        char* v    = $6 ? cat2(u, $6) : u;

        $$ = v;

        free(hdr);
        free(body);
        free($3);
        if($5) free($5);
        if($6){
          free(u);
          free($6);
        }
      }
  ;

opt_else
  : /* vazio */          { $$ = NULL; }
  | ELSE block
      {
        char* body = indent_block($2);
        char* hdr  = strclone("else:\n");
        char* all  = cat2(hdr, body);
        $$ = all;
        free(hdr);
        free(body);
        if($2) free($2);
      }
  ;

/* tallgrass (cond) {...} → while cond: ... */
while
  : TALLGRASS '(' expr ')' block
      {
        char* body = indent_block($5);
        char* hdr  = cat3("while ", $3, ":\n");
        char* all  = cat2(hdr, body);
        $$ = all;
        free(hdr);
        free(body);
        free($3);
        if($5) free($5);
      }
  ;

/* journey (init; cond; inc) { ... } →
   init
   while cond:
       body
       inc
*/
for
  : JOURNEY '(' for_init ';' expr ';' expr ')' block
      {
        /* init */
        char* init_line = cat2($3, "\n");

        /* corpo do bloco */
        char* body      = indent_block($9);

        /* incremento */
        char* inc_line  = cat2($7, "\n");
        char* inc_body  = indent_block(inc_line);

        /* while header */
        char* hdr       = cat3("while ", $5, ":\n");
        char* loop      = cat2(hdr, body);
        char* loop2     = cat2(loop, inc_body);

        /* código final: init + loop */
        char* all       = cat2(init_line, loop2);
        $$ = all;

        free(init_line);
        free(body);
        free(inc_line);
        free(inc_body);
        free(hdr);
        free(loop);
        free(loop2);

        free($3);
        free($5);
        free($7);
        if($9) free($9);
      }
  ;

/* for-init: pokeball i = expr → i = expr */
for_init
  : POKEBALL IDENT '=' expr
      {
        char* t = cat3($2, " = ", $4);
        free($2);
        free($4);
        $$ = t;
      }
  ;

/* evolve expr → return expr */
return
  : EVOLVE expr
      { char* t = cat3("return ", $2, ""); free($2); $$ = t; }
  ;

/* Expressões com precedência (atrib, lógicas, comparação, aritmética, unárias) */
expr
  : IDENT '=' expr       { char* t = cat3($1, " = ", $3); free($1); free($3); $$ = t; }

  | expr OR expr         { char* t = cat3($1, " or ",  $3); free($1); free($3); $$ = t; }
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
  | '!' expr %prec NOT   { char* t = cat3("not ", $2, ""); free($2); $$ = t; }

  | call                 { $$ = $1; }
  | primary              { $$ = $1; }
  ;

call
  : IDENT '(' opt_arg_list ')'
      {
        char* t = cat3($1, "(", $3 ? $3 : "");
        char* u = cat3(t, ")", "");
        $$ = u;
        free(t);
        free($1);
        if($3) free($3);
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
