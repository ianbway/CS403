// Ian Braudaway
// Header file for lexer class

#ifndef __LEXER_INCLUDED__
#define __LEXER_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include "lexeme.h"

typedef struct LEXER LEXER;

extern LEXER *newLexer(FILE *fp);
extern char myRead(LEXER *lex);
extern void myPushback(LEXER *lex, char ch);
extern void skipWhiteSpace(LEXER *lex);
extern LEXEME *lexVariableOrKeyword(LEXER *lex);
extern LEXEME *lex(LEXER *lex);

#endif