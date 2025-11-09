all: tradutor

tradutor: lexer.l parser.y main.c
	bison -d parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c main.c -o tradutor

clean:
	rm -f tradutor lex.yy.c parser.tab.c parser.tab.h