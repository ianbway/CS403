# Ian Braudaway
# makefile for lexer

SCANNER_OBJS = types.o lexeme.o lexer.o scanner.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : scanner

scanner : $(SCANNER_OBJS)
	$(CC) $(LOPTS) $(SCANNER_OBJS) -o scanner

types.o : types.c types.h
	$(CC) $(OPTS) types.c

lexeme.o : lexeme.c lexeme.h
	$(CC) $(OPTS) lexeme.c

lexer.o : lexer.c lexer.h
	$(CC) $(OPTS) lexer.c

scanner.o : scanner.c scanner.h
	$(CC) $(OPTS) scanner.c

clean : 
	rm -f $(SCANNER_OBJS) ./types ./lexeme ./lexer ./scanner

test1 : 
	./scanner ./test1.txt

test2 : 
	./scanner ./test2.txt

test3 : 
	./scanner ./test3.txt

test4 : 
	./scanner ./test4.txt

test5 : 
	./scanner ./test5.txt