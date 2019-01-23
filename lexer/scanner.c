// Ian Braudaway
// Implementation file for scanner class

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"

int 
main(int argc,char *argv[]) 
{
    if (argc != 2)
    {
        fprintf(stderr,"scanner takes file as argument\n"); 
        exit(1);
    }

    FILE *fileName = argv[1];

    LEXEME *token; 
    LEXER *i = newLexer(fileName);

    token = lex(); 
    while (getType(token) != ENDofINPUT) 
    { 
        // lexeme display token
        display(token); 
        token = lex(); 
    }

    return 0; 
}