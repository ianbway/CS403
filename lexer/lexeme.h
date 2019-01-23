// Ian Braudaway
// Header file for lexeme class

#ifndef __LEXEME_INCLUDED__
#define __LEXEME_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lexeme LEXEME;

extern LEXEME *newLexeme(
    char *type,
    char *string,
    int integer,
    double real,

    bool isStr,
    bool isInt,
    bool isReal);

#endif