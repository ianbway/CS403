// Ian Braudaway
// Implementation file for recognizer class

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"

LEXER *GlobalLexer;
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
operator()
{
    if (check(PLUS))
    {
        match(PLUS);
    }
    else if (check(MINUS))
    {
        match(MINUS);
    }
    else if (check(MULTIPLY))
    {
        match(MULTIPLY);
    }
    else if (check(DIVIDE))
    {
        match(DIVIDE);
    }
    else if (check(LESS_THAN))
    {
        match(LESS_THAN);
    }
    else if (check(LESS_THAN_EQUAL))
    {
        match(LESS_THAN_EQUAL);
    }
    else if (check(EQUAL))
    {
        match(EQUAL);
    }
    else if (check(NOT))
    {
        match(NOT):
        match(EQUAL);
    }
    else if (check(GREATER_THAN))
    {
        match(GREATER_THAN);
    }
    else if (check(GREATER_THAN_EQUAL))
    {
        match(GREATER_THAN_EQUAL);
    }
    else if (check(MODULO))
    {
        match(MODULO);
    }
    else if (check(OR))
    {
        match(OR);
    }
    else if (check(AND))
    {
        match(AND);
    }
    else
    {
        fprintf(stdout,"operator error \n"); 
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
    // else do nothing
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

bool
expressionPending()
{
    return check(INTEGER) || check(REAL) || varExpressionPending() || 
           check(MINUS) || check(NOT) || check(STRING) || check(OPEN_BRACKET) ||
           check(AT) || check(PRINT);
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

bool
statementPending()
{
    return check(IF) || check(WHILE) || check(FUNC) || check(VAR) || 
           check(RETURN) || expressionPending();
}

void
elses()
{
    if (check(ELSE))
    {
        if (check(IF))
        {
            ifRule();
        }
        else
        {
            block();
        }
    }
    // else do nothing
}

void
ifRule()
{
    match(IF);
    match(OPEN_BRACKET);
    expression();
    match(CLOSE_BRACKET);
    block();
    elses();
}

void
whileRule()
{
    match(WHILE);
    match(OPEN_BRACKET);
    expression();
    match(CLOSE_BRACKET);
    block();
}

void
statement()
{
    if (expressionPending())
    {
        expression();
    }
    else if (check(IF))
    {
        ifRule();
    }
    else if (check(WHILE))
    {
        whileRule();
    }
    else if (check(FUNC))
    {
        funcDef();
    }
    else if (check(VAR))
    {
        varDef();
    }
    else if (check(RETURN))
    {
        match(RETURN);
        expression();
    }
    else
    {
        fprintf(stdout,"statement error \n"); 
        exit(1);
    }
}

void
statements()
{
    statement()
    if (statementPending())
    {
        statements();
    }
}

void
block()
{
    if (check(OPEN_BRACKET))
    {
        match(OPEN_BRACKET);
        match(OPEN_BRACKET);
        statements();
        match(CLOSE_BRACKET);
        match(CLOSE_BRACKET);
    }
    else
    {
        fprintf(stdout,"block error \n"); 
        exit(1);
    }
}

void
optInit()
{
    if (check(EQUAL))
    {
        match(EQUAL);
        expression();
    }
}

void
argList()
{
    expression();
    if (check(BAR))
    {
        match(BAR);
        argList();
    }
}

void
optArgList()
{
    if (expressionPending())
    {
        argList();
    }
    // else do nothing
}

void
paramList()
{
    if (check(VARIABLE))
    {
        match(VARIABLE);
        if (check(BAR))
        {
            match(BAR);
            paramList();
        }
    }
}

void
optParamList()
{
    if (check(VARIABLE))
    {
        paramList();
    }
    // else do nothing
}

void
funcDef()
{
    match(FUNC);
    if (check(VARIABLE))
    {
        match(VARIABLE);
        match(OPEN_BRACKET);
        optParamList();
        match(CLOSE_BRACKET);
        block();
    }
}

void
varDef()
{
    match(VAR);
    if (check(VARIABLE))
    {
        match(VARIABLE);
        optInit();
    }
    else
    {
        fprintf(stdout,"varDef error \n"); 
        exit(1);
    }
}

void
def()
{
    if (check(VAR))
    {
        varDef();
    }
    else if (check(FUNC))
    {
        funcDef();
    }
    else
    {
        fprintf(stdout,"definition error \n"); 
        exit(1);
    }
}

void
program()
{
    if (check(FUNC) || check(VAR)) 
    {
       def(); 
    }
    else if (programPending())
    {
        program();
    }
    else if (statementPending())
    {
        statement();
    }
    else
    {
        fprintf(stdout,"program error \n"); 
        exit(1);
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
    CurrentLexeme = lex(GlobalLexer); 
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
        fprintf(stdout,"syntax error, expected: %s, got: %s, line number: %d \n", 
                getType(CurrentLexeme), type, getLineNumber(GlobalLexer)); 
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
    LEXER *GlobalLexer = newLexer(fileName);

    CurrentLexeme = lex(GlobalLexer); 
    program(); 
    match(ENDofINPUT);

    fclose(fileName);

    return 0; 
}