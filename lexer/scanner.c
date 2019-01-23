// Ian Braudaway
// Implementation file for scanner class

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "lexer.h"
#include "lexeme.h"
#include "types.h"

// #include "string.h"
// #include "real.h"
// #include "integer.h"

struct SCANNER
{
    FILE *file;
};

SCANNER *
newScanner(FILE *fp)
{
    SCANNER *scan = malloc(sizeof(SCANNER));
    if (scan == 0) 
    { 
        fprintf(stderr,"out of memory\n"); 
        exit(1); 
    }

    scan->file = fp;
    return scan;
}

// this is main. dont need struct, newscanner
void 
scanner(SCANNER *s) 
{ 
    FILE *fileName = s->file;

    LEXEME *token; 
    LEXER *i = newLexer(fileName);

    token = lex(); 
    while (getType(token) != ENDofINPUT) 
    { 
        // lexeme display token
        display(token); 
        token = lex(); 
    } 
}