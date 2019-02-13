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
        printf("[[");
        prettyPrint(getRight(tree));
        printf("]]");
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
    else if (getType(tree) == PLUS)
    {
        prettyPrint(getLeft(tree));
        printf(" + ");
        prettyPrint(getRight(tree));
    }

    else 
    {
        printf("bad expression!\n"); 
    }  
}






