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

scanner.o : scanner.c
	$(CC) $(OPTS) scanner.c

clean : 
	rm -f $(SCANNER_OBJS) ./types ./lexeme ./lexer ./scanner

test1 : 
	./scanner ./test1.e

test2 : 
	./scanner ./test2.e

test3 : 
	./scanner ./test3.e

test4 : 
	./scanner ./test4.e

test5 : 
	./scanner ./test5.e

run :
	@echo "TEST 1:"
	./scanner ./test1.e
	@echo ""
	@echo "TEST 2:"
	./scanner ./test2.e
	@echo ""
	@echo "TEST 3:"
	./scanner ./test3.e
	@echo ""
	@echo "TEST 4:"
	./scanner ./test4.e
	@echo ""
	@echo "TEST 5:"
	./scanner ./test5.e
	@echo ""