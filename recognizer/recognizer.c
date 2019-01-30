// Ian Braudaway
// Implementation file for recognizer class

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"

LEXEME *CurrentLexeme;

void 
unary() 
{ 
    if (check(INTEGER)) 
    { 
        match(INTEGER); 
    }
    else if (check(REAL))
    {
        match(REAL);
    } 
    else if (varExpressionPending()) 
    { 
        varExpression(); 
    }
    else if (check(MINUS))
    {
        match(MINUS);
        unary();
    } 
    else if (check(NOT))
    {
        match(NOT);
        unary();
    }
    else if (check(STRING))
    {
        match(STRING);
    }
    else if (check(AT))
    {
        match(AT);
        match(OPEN_BRACKET);
        optArgList();
        match(CLOSE_BRACKET);
    }
    else if (check(PRINT))
    {
        match(PRINT);
        match(OPEN_BRACKET);
        argList();
        match(CLOSE_BRACKET);
    }
    else if (check(OPEN_BRACKET))
    { 
        match(OPEN_BRACKET); 
        expression(); 
        match(CLOSE_BRACKET); 
    }
    else
    {
        fprintf(stdout,"unary error \n"); 
        exit(1);
    } 
}

void 
varExpression() 
{ 
    match(VARIABLE); 
    if (check(OPEN_BRACKET)) 
    { 
        match(OPEN_BRACKET); 
        optArgList();
        match(CLOSE_BRACKET); 
    }
    else if (check(PLUS))
    {
        match(PLUS);
        match(PLUS);
    } 
}

bool
varExpressionPending() 
{ 
    return check(VARIABLE); 
}

bool
operatorPending()
{
    return check(PLUS) || check(TIMES) || check(MULTIPLY) || check(DIVIDE) || 
           check(LESS_THAN) || check(LESS_THAN_EQUAL) || check(EQUAL) || 
           check(NOT) || check(GREATER_THAN) || check(GREATER_THAN_EQUAL) ||
           check(MODULO) || check(OR) || check(AND);
}

void 
expression() 
{ 
    unary(); 
    if (operatorPending()) 
    { 
        operator(); 
        expression(); 
    } 
}

void
program()
{
    def();
    if (programPending())
    {
        program();
    }
    else if (statementPending())
    {
        statement();
    }
}

bool 
check(char *type) 
{ 
    return getType(CurrentLexeme) == type; 
}

void 
advance() 
{ 
    CurrentLexeme = lex(); 
} 

void 
match(char *type) 
{ 
    matchNoAdvance(type); 
    advance(); 
}

void 
matchNoAdvance(char *type)
{
    if (!check(type))
    {
        fprintf(stdout,"syntax error, expected: %s, got: %s, line number: %d \n", getType(CurrentLexeme), type, ); 
        exit(1);
    }
}

int 
main(int argc,char *argv[]) 
{
    if (argc != 2)
    {
        fprintf(stderr,"recognizer takes file as argument\n"); 
        exit(1);
    }

    FILE *fileName = fopen(argv[1], "r");

    LEXEME *token; 
    LEXER *i = newLexer(fileName);

    token = lex(i); 
    while (getType(token) != ENDofINPUT) 
    { 
        token = lex(i); 
    }

    fclose(fileName);

    return 0; 
}