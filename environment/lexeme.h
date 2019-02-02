// Ian Braudaway
// Header file for lexeme class

#ifndef __LEXEME_INCLUDED__
#define __LEXEME_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

typedef struct LEXEME LEXEME;

extern LEXEME *newLexeme(
    char *type,
    char *token);

extern char *getType(LEXEME *);

extern LEXEME *getLeft(LEXEME *lex);
extern LEXEME *getRight(LEXEME *lex);
extern void setLeft(LEXEME *lex, LEXEME *leftLex);
extern void setRight(LEXEME *lex, LEXEME *rightLex);

extern void display(LEXEME *);

#endif