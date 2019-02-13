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
    switch (getType(tree))
    {
        case INTEGER :  { printf("%d", getIntegerToken(tree));}
        case REAL :     { printf("%f", getRealToken(tree));}
        case VARIABLE : { printf("%s", getStringToken(tree));}
        case STRING :  { printf("\"%s\"", getStringToken(tree));}
        case OPAREN :
        {
            printf("(");
            prettyPrint(getRight(tree));
            printf(")");
        }
        case UMINUS :
        {
            printf("-");
            print(getRight(tree));
        }
        case PLUS :
        {
            prettyPrint(getLeft(tree));
            printf(" + ");
            prettyPrint(getRight(tree));
        }

        default :
        {
            printf("bad expression!\n"); 
        }
    }
}






