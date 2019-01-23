// Ian Braudaway
// Header file for lexeme class

#ifndef __LEXEME_INCLUDED__
#define __LEXEME_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LEXEME LEXEME;

extern LEXEME *newLexeme(
    char *type,
    char token);

extern char *getType(LEXEME *);
extern void display(LEXEME *);

#endif