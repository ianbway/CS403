# Ian Braudaway
# makefile for pretty printer

PP_OBJS = types.o lexeme.o lexer.o recognizer.o environment.o main.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : pp

pp : $(PP_OBJS)
	$(CC) $(LOPTS) $(PP_OBJS) -o pp

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
	rm -f $(PP_OBJS) ./types ./lexeme ./lexer ./recognizer ./environment ./pp

test1 :
	@echo "TEST 1:"
	cat ./test1.e
	@echo ""
	@echo ""
	./pp ./test1.e

test2 :
	@echo "TEST 2:" 
	cat ./test2.e
	@echo ""
	@echo ""
	./pp ./test2.e

test3 : 
	@echo "TEST 3:"
	cat ./test3.e
	@echo ""
	@echo ""
	./pp ./test3.e

run :
	@echo "MAKE RUN"
	@echo "TEST 1:"
	cat ./test1.e
	@echo ""
	@echo ""
	-./pp ./test1.e
	@echo "TEST 2:" 
	cat ./test2.e
	@echo ""
	@echo ""
	-./pp ./test2.e
	@echo "TEST 3:"
	cat ./test3.e
	@echo ""
	@echo ""
	-./pp ./test3.e
	@echo ""

test :
	@echo "MAKE RUN"
	@echo "TEST 1:"
	cat ./test1.e
	@echo ""
	@echo ""
	-./pp ./test1.e
	@echo "TEST 2:" 
	cat ./test2.e
	@echo ""
	@echo ""
	-./pp ./test2.e
	@echo "TEST 3:"
	cat ./test3.e
	@echo ""
	@echo ""
	-./pp ./test3.e
	@echo ""
