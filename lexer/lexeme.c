// Ian Braudaway
// Implementation file for lexeme class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lexeme.h"
#include "types.h"

struct LEXEME
{
    char *type;
    char *string;
    int integer;
    double real;
};

LEXEME *
newLexeme(char *type, char *token)
{
    LEXEME *lexeme = malloc(sizeof(LEXEME));

    if (lexeme == 0) 
    { 
        fprintf(stderr,"out of memory\n"); 
        exit(1); 
    }

    lexeme->type = type;

    //string
    if (lex->type == STRING)
    {
        lexeme->string = token;
    }

    //int, convert string to integer
    else if (lex->type == INTEGER)
    {
        lexeme->integer = atoi(token);
    }

    //real, convert string to float
    else if (lex->type == REAL)
    {
        lexeme->real = atof(token);
    }

    //no token otherwise, the string integer and real fields remain null

    return lexeme;
}

char *
getType(LEXEME *lex)
{
    return lex->type;
}

void
display(LEXEME *lex)
{
    printf("%s ", lex->type);

    //string
    if (lex->type == STRING)
    {
        printf("%s\n", lex->string);
    }

    //int
    else if (lex->type == INTEGER)
    {
        printf("%d\n", lex->integer);
    }

    //real
    else if (lex->type == REAL)
    {
        printf("%f\n", lex->real);
    }

    //no token
    else
    {
        printf("\n");
    }
}