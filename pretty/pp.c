// Ian Braudaway
// Implementation file for pretty printer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "pp.h"

void
prettyPrint(LEXEME *tree)
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
        printf("[");
        prettyPrint(getRight(tree));
        printf("]");
    }
    else if (getType(tree) == STRING)
    { 
        printf("\"%s\"", getStringToken(tree));
    }
    else if (getType(tree) == OPEN_BRACKET)
    {
        printf("[");
        prettyPrint(getRight(tree));
        printf("]");
    }
    else if (getType(tree) == OPEN_BLOCK)
    {
        printf(":");
        prettyPrint(getRight(tree));
        printf(";");
    }
    else if (getType(tree) == UMINUS)
    {
        printf("-");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == UNOT)
    {
        printf("!");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == NOT)
    {
        printf("!");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == PLUS)
    {
        prettyPrint(getLeft(tree));
        printf(" + ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == MINUS)
    {
        prettyPrint(getLeft(tree));
        printf(" - ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == MULTIPLY)
    {
        prettyPrint(getLeft(tree));
        printf(" * ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == DIVIDE)
    {
        prettyPrint(getLeft(tree));
        printf(" / ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == LESS_THAN)
    {
        prettyPrint(getLeft(tree));
        printf(" < ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == LESS_THAN_EQUAL)
    {
        prettyPrint(getLeft(tree));
        printf(" <= ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == GREATER_THAN)
    {
        prettyPrint(getLeft(tree));
        printf(" > ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == GREATER_THAN_EQUAL)
    {
        prettyPrint(getLeft(tree));
        printf(" >= ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == EQUAL)
    {
        prettyPrint(getLeft(tree));
        printf(" = ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == COMPARE_EQUAL)
    {
        prettyPrint(getLeft(tree));
        printf(" == ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == MODULO)
    {
        prettyPrint(getLeft(tree));
        printf(" %% ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == OR)
    {
        prettyPrint(getLeft(tree));
        printf(" or ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == AND)
    {
        prettyPrint(getLeft(tree));
        printf(" and ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == AT)
    {
        printf("@");
        printf("[");
        prettyPrint(getRight(tree));
        printf("]");
    }
    else if (getType(tree) == PRINT)
    {
        printf("print");
        printf("[");
        prettyPrint(getRight(tree));
        printf("]");
    }
    else if (getType(tree) == IF)
    {
        printf("if ");
        printf("[");
        prettyPrint(getLeft(tree));
        printf("]");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == ELSE)
    {
        printf("else ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == WHILE)
    {
        printf("while ");
        printf("[");
        prettyPrint(getLeft(tree));
        printf("]");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == RETURN)
    {
        printf("return ");
        prettyPrint(getRight(tree));
    }

    else if (getType(tree) == MOREPROGRAM)
    {
        prettyPrint(getLeft(tree));
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == VAR)
    {
        printf("var ");
        prettyPrint(getLeft(tree));
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == FUNC)
    {
        prettyPrint(getLeft(tree));
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == FUNCDEF)
    {
        printf("func ");
        prettyPrint(getLeft(tree));
        printf("[");
        prettyPrint(getRight(tree));
        printf("]");
    }
    else if (getType(tree) == ARGLIST)
    {
        prettyPrint(getLeft(tree));
        printf("| ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == PARAMLIST)
    {
        prettyPrint(getLeft(tree));
        printf("| ");
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == STATEMENTS)
    {
        prettyPrint(getLeft(tree));
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == IFJOIN)
    {
        prettyPrint(getLeft(tree));
        prettyPrint(getRight(tree));
    }
    else if (getType(tree) == ENDofINPUT)
    {
        prettyPrint(getLeft(tree));
        printf("\n");
    }
    else 
    {
        printf("bad expression!\n"); 
    }  
}






