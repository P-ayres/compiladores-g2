%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== Utils de string para codegen ===== */
static char* strclone(const char* s){ if(!s) return NULL; size_t n=strlen(s); char* r=(char*)malloc(n+1); memcpy(r,s,n+1); return r; }
static char* cat2(const char* a,const char* b){ size_t na=a?strlen(a):0, nb=b?strlen(b):0; char* r=(char*)malloc(na+nb+1); if(a) memcpy(r,a,na); if(b) memcpy(r+na,b,nb); r[na+nb]='\0'; return r; }
static char* cat3(const char* a,const char* b,const char* c){ char* t=cat2(a,b); char* r=cat2(t,c); free(t); return r; }
static void append(char** base, const char* add){ char* t=cat2(*base?*base:"", add?add:""); if(*base) free(*base); *base=t; }

/* Saída acumulada do programa */
static char* G_OUT = NULL;

int yylex(void);
void yyerror(const char* s){ fprintf(stderr,"[syntax] %s\n", s); }
%}

/* ===== Tipos ===== */
%union { char* str; }

%token TRAINER POKEBALL BATTLE ELSE TALLGRASS JOURNEY SHOUT EVOLVE TRUE FALSE
%token IDENT NUMBER STRING
%token EQ NE LE GE AND OR

%type  <str> program items item func_decl param_list opt_param_list
%type  <str> block var_decl stmt print if while for for_init return expr call primary
%type  <str> opt_else arg_list opt_arg_list

/* ===== Precedência ===== */
%right '='
%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right UMINUS NOT

%%

program
  : items                { /* imprime e libera */ append(&G_OUT, $1); printf("%s\n", G_OUT?G_OUT:""); free(G_OUT); }
  ;

items
  : items item           { $$ = cat2($1,$2); free($1); free($2); }
  | item                 { $$ = $1; }
  ;

item
  : func_decl            { $$ = $1; }
  | var_decl             { $$ = $1; }
  | stmt                 { $$ = $1; }
  ;

func_decl
  : TRAINER IDENT '(' opt_param_list ')' block
      {
        char* hdr = cat3("function ", $2, "(");
        char* hdr2 = cat3(hdr, $4?$4:"", ")");
        char* all = cat2(hdr2, $6);
        $$ = all;
        free(hdr); free(hdr2);
        free($2); if($4) free($4); free($6);
      }
  ;

opt_param_list
  : /* vazio */          { $$ = NULL; }
  | param_list           { $$ = $1; }
  ;

param_list
  : IDENT                { $$ = $1; }
  | param_list ',' IDENT { char* t=cat3($1,", ",$3); free($1); free($3); $$=t; }
  ;

var_decl
  : POKEBALL IDENT '=' expr ';'
      { char* t=cat3("let ", $2, " = "); char* u=cat3(t, $4, ";\n"); free(t); free($2); free($4); $$=u; }
  ;

block
  : '{' items '}'        { char* in = $2; char* t=cat3("{\n", in?in:"", "}\n"); free(in); $$=t; }
  | '{' '}'              { $$ = strclone("{\n}\n"); }
  ;

stmt
  : print ';'            { char* t=cat2($1,";\n"); free($1); $$=t; }
  | if                   { $$=$1; }
  | while                { $$=$1; }
  | for                  { $$=$1; }
  | return ';'           { char* t=cat2($1,";\n"); free($1); $$=t; }
  | expr ';'             { char* t=cat2($1,";\n"); free($1); $$=t; }
  | block                { $$=$1; }
  ;

print
  : SHOUT '(' expr ')'
      { char* t=cat3("console.log(", $3, ")"); free($3); $$=t; }
  ;

if
  : BATTLE '(' expr ')' block opt_else
      {
        char* t = cat3("if (", $3, ") ");
        char* u = cat2(t, $5);
        char* v = $6? cat2(u,$6) : u;
        $$ = v;
        free(t); if($6) free(u);
        free($3); free($5); if($6) free($6);
      }
  ;

opt_else
  : /* vazio */          { $$ = NULL; }
  | ELSE block           { $$ = cat3(" else ", $2, ""); free($2); }
  ;

while
  : TALLGRASS '(' expr ')' block
      {
        char* t=cat3("while (", $3, ") ");
        char* u=cat2(t,$5);
        $$=u; free(t); free($3); free($5);
      }
  ;

for
  : JOURNEY '(' for_init ';' expr ';' expr ')' block
      {
        /* for (init; cond; update) block */
        char* head = cat3("for (", $3, "; ");
        char* head2= cat3(head, $5, "; ");
        char* head3= cat3(head2, $7, ") ");
        char* all  = cat2(head3, $9);
        $$=all;
        free(head); free(head2); free(head3);
        free($3); free($5); free($7); free($9);
      }
  ;

for_init
  : POKEBALL IDENT '=' expr
      { char* t=cat3("let ", $2, " = "); char* u=cat2(t, $4); free(t); free($2); free($4); $$=u; }
  ;

return
  : EVOLVE expr
      { char* t=cat3("return ", $2, ""); free($2); $$=t; }
  ;

expr
  : IDENT '=' expr       { char* t=cat3($1, " = ", $3); free($1); free($3); $$=t; }

  | expr OR expr         { char* t=cat3($1, " || ", $3); free($1); free($3); $$=t; }
  | expr AND expr        { char* t=cat3($1, " && ", $3); free($1); free($3); $$=t; }
  | expr EQ expr         { char* t=cat3($1, " == ", $3); free($1); free($3); $$=t; }
  | expr NE expr         { char* t=cat3($1, " != ", $3); free($1); free($3); $$=t; }
  | expr '<' expr        { char* t=cat3($1, " < ",  $3); free($1); free($3); $$=t; }
  | expr '>' expr        { char* t=cat3($1, " > ",  $3); free($1); free($3); $$=t; }
  | expr LE expr         { char* t=cat3($1, " <= ", $3); free($1); free($3); $$=t; }
  | expr GE expr         { char* t=cat3($1, " >= ", $3); free($1); free($3); $$=t; }
  | expr '+' expr        { char* t=cat3($1, " + ",  $3); free($1); free($3); $$=t; }
  | expr '-' expr        { char* t=cat3($1, " - ",  $3); free($1); free($3); $$=t; }
  | expr '*' expr        { char* t=cat3($1, " * ",  $3); free($1); free($3); $$=t; }
  | expr '/' expr        { char* t=cat3($1, " / ",  $3); free($1); free($3); $$=t; }
  | expr '%' expr        { char* t=cat3($1, " % ",  $3); free($1); free($3); $$=t; }

  | '-' expr %prec UMINUS{ char* t=cat3("-", $2, ""); free($2); $$=t; }
  | '!' expr %prec NOT   { char* t=cat3("!", $2, ""); free($2); $$=t; }

  | call                 { $$=$1; }
  | primary              { $$=$1; }
  ;

call
  : IDENT '(' opt_arg_list ')'
      {
        char* t=cat3($1, "(", $3?$3:"");
        char* u=cat3(t, ")", "");
        $$=u; free(t); free($1); if($3) free($3);
      }
  ;

opt_arg_list
  : /* vazio */          { $$=NULL; }
  | arg_list             { $$=$1; }
  ;

arg_list
  : expr                 { $$=$1; }
  | arg_list ',' expr    { char* t=cat3($1, ", ", $3); free($1); free($3); $$=t; }
  ;

primary
  : NUMBER               { $$= $1; }
  | STRING               { $$= $1; }
  | TRUE                 { $$= strclone("true"); }
  | FALSE                { $$= strclone("false"); }
  | IDENT                { $$= $1; }
  | '(' expr ')'         { char* t=cat3("(", $2, ")"); free($2); $$=t; }
  ;

%%
