#include <stdio.h>
#include <stdlib.h>

extern int yyparse(void);
extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s input.pokescript output.py\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    yyout = fopen(argv[2], "w");
    if (!yyout) {
        perror("Erro ao abrir arquivo de saída");
        fclose(yyin);
        return 1;
    }

    if (yyparse() == 0) {
        printf("Tradução concluída\n");
    }

    fclose(yyin);
    fclose(yyout);
    return 0;
}