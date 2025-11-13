%option noyywrap nodefault yylineno

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"   /* tokens do Bison */
extern YYSTYPE yylval;
extern FILE *yyout;

/* Util p/ strings (se quiser usar em debug) */
static char* xstrdup(const char* s){
    if(!s) return NULL;
    size_t n = strlen(s);
    char* p = (char*)malloc(n+1);
    memcpy(p, s, n+1);
    return p;
}
%}

/* ======= Padrões ======= */
WS        [ \t\r\n]+
ID        [A-Za-z_][A-Za-z0-9_]*
NUM       ([0-9]+\.[0-9]+|[0-9]+)
%x COMMENT
/* strings com escapes em C: "..." */
STR       \"([^\"\\]|\\.)*\"

/* ======= Regras ======= */
%%
{WS}                  ;                       /* ignora espaço/branco */


"//".*                ;
"/*"                  { BEGIN(COMMENT); }
<COMMENT>{
    "*/"              { BEGIN(INITIAL); }
    .|\n             ;                 
}

"trainer"             { return TRAINER; }
"pokeball"            { return POKEBALL; }
"battle"              { return BATTLE; }
"else"                { return ELSE; }
"tallgrass"           { return TALLGRASS; }
"journey"             { return JOURNEY; }
"shout"               { return SHOUT; }
"evolve"              { return EVOLVE; }
"true"                { return TRUE; }
"false"               { return FALSE; }


"=="                  { return EQ; }
"!="                  { return NE; }
"<="                  { return LE; }
">="                  { return GE; }
"&&"                  { return AND; }
"||"                  { return OR;  }


"="                   { return '='; }
"<"                   { return '<'; }
">"                   { return '>'; }
"+"                   { return '+'; }
"-"                   { return '-'; }
"*"                   { return '*'; }
"/"                   { return '/'; }
"%"                   { return '%'; }
"!"                   { return '!'; }
";"                   { return ';'; }
","                   { return ','; }
"("                   { return '('; }
")"                   { return ')'; }
"{"                   { return '{'; }
"}"                   { return '}'; }


{STR}                 { yylval.str = xstrdup(yytext); return STRING; }
{NUM}                 { yylval.str = xstrdup(yytext); return NUMBER; }
{ID}                  { yylval.str = xstrdup(yytext); return IDENT;  }

.                     { fprintf(stderr, "[lex] caractere inesperado: %s\n", yytext); }
%%
