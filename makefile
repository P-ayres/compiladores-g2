
CC = gcc
CFLAGS = -Wall -g

# Ferramentas
LEX = flex
YACC = bison
YFLAGS = -d -v  

# Arquivos fonte
C_SRC   = main.c
YACC_SRC = parser.y
LEX_SRC = lexer.l

# Arquivos gerados
LEX_C   = lex.yy.c
YACC_C  = parser.tab.c
YACC_H  = parser.tab.h
PARSER_OUTPUT = parser.output

# Executável final
TARGET = translator

# Regra padrão
all: $(TARGET)

# Compila o executável
$(TARGET): $(C_SRC) $(YACC_C) $(LEX_C)
	$(CC) $(CFLAGS) -o $@ $^

# Bison: gera parser.tab.c e parser.tab.h
$(YACC_C) $(YACC_H) $(PARSER_OUTPUT): $(YACC_SRC)
	$(YACC) $(YFLAGS) $<

# Flex: gera lex.yy.c
$(LEX_C): $(LEX_SRC) $(YACC_H)
	$(LEX) $<

# Limpeza de arquivos gerados
clean:
	rm -f $(TARGET) $(LEX_C) $(YACC_C) $(YACC_H) $(PARSER_OUTPUT)

# Recompila do zero
rebuild: clean all

# Garante que regras especiais não colidam com arquivos
.PHONY: all clean rebuild
