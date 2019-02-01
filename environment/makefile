# Ian Braudaway
# makefile for environment

ENVIRONMENT_OBJS = types.o lexeme.o lexer.o recognizer.o environment.o main.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : environment

environment : $(ENVIRONMENT_OBJS)
	$(CC) $(LOPTS) $(ENVIRONMENT_OBJS) -o environment

types.o : types.c types.h
	$(CC) $(OPTS) types.c

lexeme.o : lexeme.c lexeme.h
	$(CC) $(OPTS) lexeme.c

lexer.o : lexer.c lexer.h
	$(CC) $(OPTS) lexer.c

recognizer.o : recognizer.c recognizer.h
	$(CC) $(OPTS) recognizer.c

environment.o : environment.c environment.h
	$(CC) $(OPTS) environment.c

main.o : main.c
	$(CC) $(OPTS) main.c

clean : 
	rm -f $(ENVIRONMENT_OBJS) ./types ./lexeme ./lexer ./recognizer ./environment

test1 :
	@echo "TEST 1:"
	./environment ./test1.e

test2 :
	@echo "TEST 2:" 
	./environment ./test2.e

test3 : 
	@echo "TEST 3:"
	./environment ./test3.e

test4 : 
	@echo "TEST 4:"
	./environment ./test4.e

test5 : 
	@echo "TEST 5:"
	./environment ./test5.e

run :
	@echo "TEST 1:"
	-./environment ./test1.e
	@echo ""
	@echo "TEST 2:"
	-./environment ./test2.e
	@echo ""
	@echo "TEST 3:"
	-./environment ./test3.e
	@echo ""
	@echo "TEST 4:"
	-./environment ./test4.e
	@echo ""
	@echo "TEST 5:"
	-./environment ./test5.e
	@echo ""

test :
	@echo "TEST 1:"
	-./environment ./test1.e
	@echo ""
	@echo "TEST 2:"
	-./environment ./test2.e
	@echo ""
	@echo "TEST 3:"
	-./environment ./test3.e
	@echo ""
	@echo "TEST 4:"
	-./environment ./test4.e
	@echo ""
	@echo "TEST 5:"
	-./environment ./test5.e
	@echo ""