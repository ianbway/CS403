// Ian Braudaway
// Implementation file for lexeme class

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lexeme.h"
#include "types.h"

struct lexeme
{
    char *type;
    char *string;
    int integer;
    double real;
};

static LEXEME *
newLexeme(char *type, char token)
{
    LEXEME *lexeme = malloc(sizeof(LEXEME));

    assert(lexeme != 0);

    lexeme->type = type;

    if (isdigit(token))
    {
        if (fmod(token,1) != 0)
        {
            lexeme->real = token;
        }

        else
        {
            lexeme->integer = token;
        }
    }

    else
    {
        lexeme->string = token;
    }

    return lexeme;
}