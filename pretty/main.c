// Ian Braudaway
// Main method for pretty printer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "environment.h"

int 
main(int argc,char *argv[]) 
{
    if (argc != 2)
    {
        fprintf(stderr,"pretty printer takes file as argument\n"); 
        exit(1);
    }

    FILE *fileName = fopen(argv[1], "r");

    assert(fileName != 0);

    pp(fileName);

    fclose(fileName);

    return 0; 
}