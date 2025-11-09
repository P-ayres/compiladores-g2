all: tradutor

tradutor: lex.yy.c parser.tab.c main.c
	@gcc parser.tab.c lex.yy.c main.c -o tradutor -lfl

parser.tab.c parser.tab.h: parser.y
	@bison -d parser.y

lex.yy.c: lexer.l parser.tab.h
	@flex lexer.l

clean:
	@rm -f tradutor lex.yy.c parser.tab.c parser.tab.h