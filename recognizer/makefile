# Ian Braudaway
# makefile for recognizer / parser

RECOGNIZER_OBJS = types.o lexeme.o lexer.o recognizer.o main.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : recognizer

recognizer : $(RECOGNIZER_OBJS)
	$(CC) $(LOPTS) $(RECOGNIZER_OBJS) -o recognizer

types.o : types.c types.h
	$(CC) $(OPTS) types.c

lexeme.o : lexeme.c lexeme.h
	$(CC) $(OPTS) lexeme.c

lexer.o : lexer.c lexer.h
	$(CC) $(OPTS) lexer.c

recognizer.o : recognizer.c recognizer.h
	$(CC) $(OPTS) recognizer.c

main.o : main.c
	$(CC) $(OPTS) main.c

clean : 
	rm -f $(RECOGNIZER_OBJS) ./types ./lexeme ./lexer ./recognizer

test1 :
	@echo "TEST 1:"
	./recognizer ./test1.e

test2 :
	@echo "TEST 2:" 
	./recognizer ./test2.e

test3 : 
	@echo "TEST 3:"
	./recognizer ./test3.e

test4 : 
	@echo "TEST 4:"
	./recognizer ./test4.e

test5 : 
	@echo "TEST 5:"
	./recognizer ./test5.e

run :
	@echo "TEST 1:"
	-./recognizer ./test1.e
	@echo ""
	@echo "TEST 2:"
	-./recognizer ./test2.e
	@echo ""
	@echo "TEST 3:"
	-./recognizer ./test3.e
	@echo ""
	@echo "TEST 4:"
	-./recognizer ./test4.e
	@echo ""
	@echo "TEST 5:"
	-./recognizer ./test5.e
	@echo ""

test :
	@echo "TEST 1:"
	-./recognizer ./test1.e
	@echo ""
	@echo "TEST 2:"
	-./recognizer ./test2.e
	@echo ""
	@echo "TEST 3:"
	-./recognizer ./test3.e
	@echo ""
	@echo "TEST 4:"
	-./recognizer ./test4.e
	@echo ""
	@echo "TEST 5:"
	-./recognizer ./test5.e
	@echo ""