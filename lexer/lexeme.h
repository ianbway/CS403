// Ian Braudaway
// Header file for lexeme class

#include <stdio.h>
#include <stdlib.h>

typedef struct lexeme LEXEME;

extern LEXEME *newLexeme(
    char *type,
    char token);