// Ian Braudaway
// Implementation file for recognizer class

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"

LEXER *GlobalLexer;
LEXEME *CurrentLexeme;

static void unary();
static void operator();
static void varExpression();
static bool operatorPending();
static bool expressionPending();
static void expression();
static bool statementPending();
static void elses();
static void ifRule();
static void whileRule();
static void statement();
static void statements();
static void block();
static void optInit();
static void argList();
static void optArgList();
static void paramList();
static void optParamList();
static void funcDef();
static void varDef();
static void def();
static void program();
static bool check(char *);
static void advance();
static void match(char *);
static void matchNoAdvance(char *);

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
    else if (check(VARIABLE)) 
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
    else
    { 
        match(OPEN_BRACKET); 
        expression(); 
        match(CLOSE_BRACKET); 
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
    else if (check(COMPARE_EQUAL))
    {
        match(COMPARE_EQUAL);
    }
    else if (check(NOT))
    {
        match(NOT);
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
    else
    {
        match(AND);
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
}

bool
operatorPending()
{
    return check(PLUS) || check(MINUS) || check(MULTIPLY) || check(DIVIDE) || 
           check(LESS_THAN) || check(LESS_THAN_EQUAL) || check(EQUAL) || 
           check(NOT) || check(GREATER_THAN) || check(GREATER_THAN_EQUAL) ||
           check(MODULO) || check(OR) || check(AND) || check(COMPARE_EQUAL);
}

bool
expressionPending()
{
    return check(INTEGER) || check(REAL) || check(VARIABLE) || 
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
        match(ELSE);
        if (check(IF))
        {
            ifRule();
        }
        else
        {
            block();
        }
    }
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
    else
    {
        match(RETURN);
        expression();
    }
}

void
statements()
{
    statement();
    if (statementPending())
    {
        statements();
    }
}

void
block()
{
    match(OPEN_BLOCK);
    statements();
    match(CLOSE_BLOCK);
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
}

void
funcDef()
{
    match(FUNC);
    match(VARIABLE);
    match(OPEN_BRACKET);
    optParamList();
    match(CLOSE_BRACKET);
    block();
}

void
varDef()
{
    match(VAR);
    match(VARIABLE);
    optInit();
}

void
def()
{
    if (check(VAR))
    {
        varDef();
    }
    else
    {
        funcDef();
    }
}

void
program()
{
    if (check(FUNC) || check(VAR)) 
    {
        def();
        if (!check(ENDofINPUT))
        { 
            program();
        }
        match(ENDofINPUT);
    }
    else
    {
        statement();
        match(ENDofINPUT);
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
        fprintf(stdout," illegal\n current lexeme: %s\n recognize error: %s\n line number: %d\n", 
                getType(CurrentLexeme), type, getLineNumber(GlobalLexer)); 
        exit(1);
    }
}

void
recognize(FILE *fileName)
{
    GlobalLexer = newLexer(fileName);

    CurrentLexeme = lex(GlobalLexer); 
    program(); 
    //match(ENDofINPUT);

    printf(" legal\n");
}