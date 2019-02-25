# Ian Braudaway
# makefile for dpl

DPL_OBJS = types.o lexeme.o lexer.o recognizer.o environment.o evaluator.o main.o
OPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g
CC = gcc

all : dpl

dpl : $(DPL_OBJS)
	$(CC) $(LOPTS) $(DPL_OBJS) -o dpl -lm

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

evaluator.o : evaluator.c evaluator.h
	$(CC) $(OPTS) evaluator.c

main.o : main.c
	$(CC) $(OPTS) main.c

clean : 
	rm -f $(DPL_OBJS) ./types ./lexeme ./lexer ./recognizer ./environment ./evaluator ./dpl

problem : 
	@echo ""
	@cat testSum.e
	@echo ""
	@echo ""

problemx : dpl
	@echo ""
	@./dpl testSum.e
	@echo ""
	@echo ""

arrays : 
	@echo ""
	@cat arrays.e
	@echo ""
	@echo ""

arraysx : dpl
	@echo ""
	@./dpl arrays.e
	@echo ""
	@echo ""

conditionals :
	@echo ""
	@cat conditionals.e
	@echo ""
	@echo ""

conditionalsx : dpl
	@echo ""
	@./dpl conditionals.e
	@echo ""
	@echo ""

recursion :
	@echo ""
	@cat recursion.e
	@echo ""
	@echo ""

recursionx : dpl
	@echo ""
	@./dpl recursion.e
	@echo ""
	@echo ""

iteration :
	@echo ""
	@cat iteration.e
	@echo ""
	@echo ""

iterationx : dpl
	@echo ""
	@./dpl iteration.e
	@echo ""
	@echo ""

functions :
	@echo ""
	@cat functions.e
	@echo ""
	@echo ""

functionsx: dpl
	@echo ""
	@./dpl functions.e
	@echo ""
	@echo ""

lambda :
	@echo ""
	@cat lambda.e
	@echo ""
	@echo ""

lambdax : dpl
	@echo ""
	@./dpl lambda.e
	@echo ""
	@echo ""

objects :
	@echo ""
	@cat objects.e
	@echo ""
	@echo ""

objectsx : dpl
	@echo ""
	@./dpl objects.e
	@echo ""
	@echo ""

run : dpl
	@echo ""
	@echo Original file:
	@cat testSum.e
	@echo ""
	@echo ""
	@echo DPL:
	@./dpl testSum.e

test : dpl
	@echo ""
	@echo Original file:
	@cat testSum.e
	@echo ""
	@echo ""
	@echo DPL:
	@./dpl testSum.e