#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yyparse(void);
extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s input.pokescript output.py\n", argv[0]);
        return 1;
    }

    /* entrada */
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    /* saída: aceita "-" para stdout */
    if (strcmp(argv[2], "-") == 0) {
        yyout = stdout;
    } else {
        yyout = fopen(argv[2], "w");
        if (!yyout) {
            perror("Erro ao abrir arquivo de saída");
            fclose(yyin);
            return 1;
        }
    }

    int rc = yyparse();
    if (rc == 0) {
        fprintf(stderr, "Tradução concluída\n");
    }

    if (yyin && yyin != stdin)  fclose(yyin);
    if (yyout && yyout != stdout) fclose(yyout);
    return rc; /* 0 ok, !=0 erro de sintaxe */
}
