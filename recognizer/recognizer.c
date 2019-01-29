// Ian Braudaway
// Implementation file for recognizer class

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
        fprintf(stderr,"recognizer takes file as argument\n"); 
        exit(1);
    }

    FILE *fileName = fopen(argv[1], "r");

    LEXEME *token; 
    LEXER *i = newLexer(fileName);

    token = lex(i); 
    while (getType(token) != ENDofINPUT) 
    { 
        // lexeme display token
        display(token); 
        token = lex(i); 
    }

    printf("ENDofINPUT\n");

    fclose(fileName);

    return 0; 
}