// Ian Braudaway
// Implementation file for lexeme class

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lexeme.h"
#include "types.h"

#include "string.h"
#include "real.h"
#include "integer.h"

struct lexeme
{
    char *type;
    char *string;
    int integer;
    double real;

    bool isStr = false;
    bool isInt = false;
    bool isReal = false;
};

LEXEME *
newLexeme(char *type, char token)
{
    LEXEME *lexeme = malloc(sizeof(LEXEME));

    assert(lexeme != 0);

    lexeme->type = type;

    //string
    if (isalpha(token))
    {
        lexeme->string = token;
        lexeme->isStr = true;
    }

    //int
    else if (isdigit(token))
    {
        lexeme->integer = token;
        lexeme->isInt = true;
    }

    //real
    else
    {
        lexeme->real = token;
        lexeme->isReal = true;
    }

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
    if (lex->isStr == true)
    {
        printf("%s\n", lex->string);
    }

    //int
    else if (lex->isInt == true)
    {
        printf("%d\n", lex->integer);
    }

    //real
    else
    {
        printf("%f\n", lex->real);
    }
}