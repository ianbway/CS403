# Ian Braudaway
# makefile for pretty printer

DPL_OBJS = types.o lexeme.o lexer.o recognizer.o evaluator.o main.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : dpl

dpl : $(DPL_OBJS)
	$(CC) $(LOPTS) $(DPL_OBJS) -o dpl

types.o : types.c types.h
	$(CC) $(OPTS) types.c

lexeme.o : lexeme.c lexeme.h
	$(CC) $(OPTS) lexeme.c

lexer.o : lexer.c lexer.h
	$(CC) $(OPTS) lexer.c

recognizer.o : recognizer.c recognizer.h
	$(CC) $(OPTS) recognizer.c

evaluator.o : evaluator.c evaluator.h
	$(CC) $(OPTS) evaluator.c

main.o : main.c
	$(CC) $(OPTS) main.c

clean : 
	rm -f $(DPL_OBJS) ./types ./lexeme ./lexer ./recognizer ./evaluator

test1 : pp
	@echo ""
	@echo Original file:
	@cat test1.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test1.e > test1.pp.1
	@cat test1.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test1.pp.1 > test1.pp.2
	@cat test1.pp.2
	diff -s -q test1.pp.1 test1.pp.2

test2 : pp
	@echo ""
	@echo Original file:
	@cat test2.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test2.e > test2.pp.1
	@cat test2.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test2.pp.1 > test2.pp.2
	@cat test2.pp.2
	diff -s -q test2.pp.1 test2.pp.2

test3 : pp
	@echo ""
	@echo Original file:
	@cat test3.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test3.e > test3.pp.1
	@cat test3.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test3.pp.1 > test3.pp.2
	@cat test3.pp.2
	diff -s -q test3.pp.1 test3.pp.2

run : pp
	@echo ""
	@echo "TEST 1: "
	@echo Original file:
	@cat test1.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test1.e > test1.pp.1
	@cat test1.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test1.pp.1 > test1.pp.2
	@cat test1.pp.2
	diff -s -q test1.pp.1 test1.pp.2
	@echo ""
	@echo "TEST 2: "
	@echo Original file:
	@cat test2.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test2.e > test2.pp.1
	@cat test2.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test2.pp.1 > test2.pp.2
	@cat test2.pp.2
	diff -s -q test2.pp.1 test2.pp.2
	@echo ""
	@echo "TEST 3: "
	@echo Original file:
	@cat test3.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test3.e > test3.pp.1
	@cat test3.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test3.pp.1 > test3.pp.2
	@cat test3.pp.2
	diff -s -q test3.pp.1 test3.pp.2

test : pp
	@echo ""
	@echo "TEST 1: "
	@echo Original file:
	@cat test1.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test1.e > test1.pp.1
	@cat test1.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test1.pp.1 > test1.pp.2
	@cat test1.pp.2
	diff -s -q test1.pp.1 test1.pp.2
	@echo ""
	@echo "TEST 2: "
	@echo Original file:
	@cat test2.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test2.e > test2.pp.1
	@cat test2.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test2.pp.1 > test2.pp.2
	@cat test2.pp.2
	diff -s -q test2.pp.1 test2.pp.2
	@echo ""
	@echo "TEST 3: "
	@echo Original file:
	@cat test3.e
	@echo ""
	@echo ""
	@echo Pretty Printed version of the original:
	@./pp test3.e > test3.pp.1
	@cat test3.pp.1
	@echo ""
	@echo ""
	@echo Pretty Printed version of the pretty printed version:
	@./pp test3.pp.1 > test3.pp.2
	@cat test3.pp.2
	diff -s -q test3.pp.1 test3.pp.2