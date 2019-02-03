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
#include "environment.h"
#include "pp.h"

void
prettyPrint(LEXEME *tree)
{
    switch (getType(tree))
    {
        case INTEGER  { print(tree.ival);}
        case REAL     { print(tree.rval);}
        case VARIABLE { print(tree.sval); }
        case STRING   { print('\"', tree.sval, '\"'); }
        case OPAREN
        {
            print("(");
            prettyPrint(tree.right);
            print(")");
        }
        case UMINUS
        {
            print("-");
            print(tree.right);
        }
        case PLUS
        {
            prettyPrint(tree.left);
            print(" + ");
            prettyPrint(tree.right);
        }

        else 
        { 
                print("bad expression!"); 
        }
    }
}