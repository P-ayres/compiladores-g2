%{
#include <stdio.h>
#include <string.h>

// função reponsável por delimitar as palavras chaves e auxiliar em sua identificação
int is_keyword(const char *word) {
    const char *keywords[] = {"if", "from","else", "destroy", "use", "kriptonita", "weak", "strong", "to"};
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}
//regras do analisador léxico delimitando suas funções para posterior análise e funcionamento, definindo o reconhecimento de número, delimitadores, espaços, funcionamento de comentários conforme definidos nesta sessão 

DIGITO      [0-9] //identifica números
LETRA       [a-zA-Z_] //indetifica letras
IDENT       {LETRA}({LETRA}|{DIGITO})* //identifica uma palavra chave ou um identificador 
OP_REL      (==|!=) //identifica operadores de relação
DELIM       [(){}'';,] //identifica delimitadores de código
ESPACO      [ \t\n]+ //identifica espaços
COMENT      "//"[^\n]* //identifica comentários
BOOL	    [TRUE|FALSE] //identifica palavra true ou false como booleanos

%%

{COMENT}            ;   //faz com que o comentário seja ignorado
{ESPACO}            ;   //faz com que o espaço seja ignorado

{IDENT}             {
                        if (is_keyword(yytext))
                            printf("PALAVRA_CHAVE\t\t%s\n", yytext);
                        else
                            printf("IDENTIFICADOR\t\t%s\n", yytext);
                    } //verifica se é uma palavra chave ou um identificador

{OP_REL}            { printf("OPERADOR_REL\t\t%s\n", yytext); }
{DELIM}             { printf("DELIMITADOR\t\t%s\n", yytext); }
{BOOL}		    {printf("BOOLEANO\t\t%s\n", yytext);}

//printa uma saida conforme operador identificado

.                   { printf("TOKEN_DESCONHECIDO\t%s\n", yytext); }
//printa na saida caso encontre um toke desconhecido

%%


int yywrap() {
    return 1;
} //defina wrapp para funcionando via msy2 no windows pois não tem embutido neste ambiente