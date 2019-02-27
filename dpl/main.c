// Ian Braudaway
// Main method for designer programming language

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

int countCL;
char **argsCL;

int 
main(int argc,char *argv[]) 
{
    countCL = argc;
    argsCL = argv;

    if (argc < 2)
    {
        fprintf(stderr,"Needs file as argument\n"); 
        exit(1);
    }

    FILE *fileName = fopen(argv[1], "r");

    assert(fileName != 0);

    LEXEME *tree = recognize(fileName);
    LEXEME *env = create();
    eval(tree, env);

    printf("\n");
    printf("ENVIRONMENT DISPLAY IN MAIN\n");
    displayEnvironment(env, false);

    fclose(fileName);

    return 0; 
}