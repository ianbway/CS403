// Ian Braudaway
// Implementation file for evaluator

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "environment.h"
#include "evaluator.h"

LEXEME *
eval(LEXEME *tree, LEXEME *env)
{
    if (getType(tree) == INTEGER)
    {
        printf("%d", getIntegerToken(tree));
    }
    else if (getType(tree) == REAL)
    { 
        printf("%f", getRealToken(tree));
    }
    else if (getType(tree) == VARIABLE)
    { 
        printf("%s", getStringToken(tree));
    }
    else if (getType(tree) == VARIABLE_EXPR)
    {
        eval(getLeft(tree), env);
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == STRING)
    { 
        printf("\"%s\"", getStringToken(tree));
    }
    else if (getType(tree) == OPEN_BRACKET)
    {
        printf("[");
        eval(getRight(tree), env);
        printf("]");
    }
    else if (getType(tree) == OPEN_BLOCK)
    {
        printf("\t:\n");
        eval(getRight(tree), env);
        printf("\t;\n");
    }
    else if (getType(tree) == UMINUS)
    {
        printf("-");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == UNOT)
    {
        printf("!");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == NOT)
    {
        eval(getLeft(tree), env);
        printf(" != ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == PLUS)
    {
        eval(getLeft(tree), env);
        printf(" + ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == MINUS)
    {
        eval(getLeft(tree), env);
        printf(" - ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == MULTIPLY)
    {
        eval(getLeft(tree), env);
        printf(" * ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == DIVIDE)
    {
        eval(getLeft(tree), env);
        printf(" / ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == LESS_THAN)
    {
        eval(getLeft(tree), env);
        printf(" < ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == LESS_THAN_EQUAL)
    {
        eval(getLeft(tree), env);
        printf(" <= ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == GREATER_THAN)
    {
        eval(getLeft(tree), env);
        printf(" > ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == GREATER_THAN_EQUAL)
    {
        eval(getLeft(tree), env);
        printf(" >= ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == EQUAL)
    {
        eval(getLeft(tree), env);
        printf(" = ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == COMPARE_EQUAL)
    {
        eval(getLeft(tree), env);
        printf(" == ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == MODULO)
    {
        eval(getLeft(tree), env);
        printf(" %% ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == OR)
    {
        eval(getLeft(tree), env);
        printf(" or ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == AND)
    {
        eval(getLeft(tree), env);
        printf(" and ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == AT)
    {
        printf("@");
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == PRINT)
    {
        printf("print");
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == IF)
    {
        printf("if ");
        printf("[");
        eval(getLeft(tree), env);
        printf("]\n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == ELSE)
    {
        printf("else \n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == WHILE)
    {
        printf("while ");
        printf("[");
        eval(getLeft(tree), env);
        printf("]\n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == RETURN)
    {
        printf("return ");
        eval(getRight(tree), env);
        printf("\n");
    }

    else if (getType(tree) == MOREPROGRAM)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == VAR)
    {
        printf("var ");
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
        printf("\n");
    }
    else if (getType(tree) == FUNC)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == FUNCDEF)
    {
        printf("func ");
        eval(getLeft(tree), env);
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == ARGLIST)
    {
        eval(getLeft(tree), env);
        printf("| ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == PARAMLIST)
    {
        eval(getLeft(tree), env);
        printf("| ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == STATEMENTS)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == IFJOIN)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == ENDofINPUT)
    {
        eval(getLeft(tree), env);
        printf("\n");
    }
    else if (getType(tree) == NULL)
    {
        
    }
    else 
    {
        printf("bad expression!\n"); 
    }  
}






