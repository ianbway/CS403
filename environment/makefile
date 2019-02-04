# Ian Braudaway
# makefile for environment

ENVIRONMENT_OBJS = types.o lexeme.o environment.o main.o
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

environment.o : environment.c environment.h
	$(CC) $(OPTS) environment.c

main.o : main.c
	$(CC) $(OPTS) main.c

clean : 
	rm -f $(ENVIRONMENT_OBJS) ./types ./lexeme ./environment

run :
	@echo "MAKE RUN"
	-./environment
	@echo ""

test :
	@echo "MAKE TEST"
	-./environment
	@echo ""