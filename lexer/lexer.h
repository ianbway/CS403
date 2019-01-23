// Ian Braudaway
// Header file for lexer class

#ifndef __LEXER_INCLUDED__
#define __LEXER_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "lexeme.h"

typedef struct LEXER LEXER;

extern LEXER *newLexer(FILE *fp);
extern char myRead();
extern void myPushback(char ch);
extern void skipWhiteSpace();
extern LEXEME *lexVariableOrKeyword();
extern LEXEME *lex();

#endif