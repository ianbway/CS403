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

static LEXEME *unary();
static LEXEME *operator();
static LEXEME *varExpression();
static bool operatorPending();
static bool expressionPending();
static LEXEME *expression();
static bool statementPending();
static LEXEME *elses();
static LEXEME *ifRule();
static LEXEME *whileRule();
static LEXEME *statement();
static LEXEME *statements();
static LEXEME *block();
static LEXEME *optInit();
static LEXEME *argList();
static LEXEME *optArgList();
static LEXEME *paramList();
static LEXEME *optParamList();
static LEXEME *funcDef();
static LEXEME *varDef();
static LEXEME *def();
static LEXEME *program();
static bool check(char *);
static void advance();
static LEXEME *match(char *);
static void matchNoAdvance(char *);

LEXEME *
cons(char *type, LEXEME *left, LEXEME *right)
{
    LEXEME *consLex = newLexeme(type, NULL);
    setLeft(consLex, left);
    setRight(consLex, right);
    return consLex;
}

LEXEME *
unary() 
{ 
    LEXEME *tree;

    if (check(INTEGER)) 
    { 
        return match(INTEGER); 
    }
    else if (check(REAL))
    {
        return match(REAL);
    } 
    else if (check(VARIABLE)) 
    { 
        return varExpression(); 
    }
    else if (check(MINUS))
    {
        match(MINUS);
        tree = unary();
        return cons("MINUS", NULL, tree);
    } 
    else if (check(NOT))
    {
        match(NOT);
        tree = unary();
        return cons("NOT", NULL, tree);
    }
    else if (check(STRING))
    {
        return match(STRING);
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

LEXEME *
operator()
{
    if (check(PLUS))
    {
        return match(PLUS);
    }
    else if (check(MINUS))
    {
        return match(MINUS);
    }
    else if (check(MULTIPLY))
    {
        return match(MULTIPLY);
    }
    else if (check(DIVIDE))
    {
        return match(DIVIDE);
    }
    else if (check(LESS_THAN))
    {
        return match(LESS_THAN);
    }
    else if (check(LESS_THAN_EQUAL))
    {
        return match(LESS_THAN_EQUAL);
    }
    else if (check(EQUAL))
    {
        return match(EQUAL);
    }
    else if (check(COMPARE_EQUAL))
    {
        return match(COMPARE_EQUAL);
    }
    else if (check(NOT))
    {
        match(NOT);
        match(EQUAL);
    }
    else if (check(GREATER_THAN))
    {
        return match(GREATER_THAN);
    }
    else if (check(GREATER_THAN_EQUAL))
    {
        return match(GREATER_THAN_EQUAL);
    }
    else if (check(MODULO))
    {
        return match(MODULO);
    }
    else if (check(OR))
    {
        return match(OR);
    }
    else
    {
        return match(AND);
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

LEXEME * 
expression() 
{ 
    LEXEME *tree;
    LEXEME *temp;

    tree = unary(); 
    if (operatorPending()) 
    { 
        temp = operator();
        setLeft(temp, tree);
        setRight(temp, expression()); 
        tree = temp; 
    }

    return tree; 
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
        return expression();
    }
    else if (check(IF))
    {
        return ifRule();
    }
    else if (check(WHILE))
    {
        return whileRule();
    }
    else if (check(FUNC))
    {
        return funcDef();
    }
    else if (check(VAR))
    {
        return varDef();
    }
    else
    {
        match(RETURN);
        return expression();
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

LEXEME *
argList()
{
    LEXEME *tree;
    LEXEME *temp;

    tree = expression();
    if (check(BAR))
    {
        temp = match(BAR);
        setLeft(temp, tree);
        setRight(temp, argList());
        tree = temp;
    }

    return tree;
}

LEXEME *
optArgList()
{
    if (expressionPending())
    {
        return argList();
    }
    else
    {
        return NULL;
    }
}

void
paramList()
{
    LEXEME *tree;
    LEXEME *temp;

    if (check(VARIABLE))
    {
        tree = match(VARIABLE);
        if (check(BAR))
        {
            temp = match(BAR);
            setLeft(temp, tree);
            setRight(temp, paramList());
            tree = temp;
        }
    }

    return tree;
}

LEXEME *
optParamList()
{
    if (check(VARIABLE))
    {
        return paramList();
    }
    else
    {
        return NULL;
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

LEXEME *
def()
{
    if (check(VAR))
    {
        return varDef();
    }
    else
    {
        return funcDef();
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

LEXEME * 
match(char *type) 
{ 
    matchNoAdvance(type); 
    advance(); 

    matchLex = newLexeme(type, NULL);
    return matchLex;
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

LEXEME *
recognize(FILE *fileName)
{
    GlobalLexer = newLexer(fileName);

    CurrentLexeme = lex(GlobalLexer); 
    LEXEME *tree = program(); 

    printf(" legal\n");

    return tree;
}