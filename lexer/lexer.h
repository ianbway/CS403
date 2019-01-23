// Ian Braudaway
// Header file for lexer class

#ifndef __LEXEME_INCLUDED__
#define __LEXEME_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "lexeme.h"

typedef struct lexer LEXER;

extern LEXER *newLexer(FILE *);
extern LEXEME *lex();

#endif