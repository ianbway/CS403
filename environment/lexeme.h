// Ian Braudaway
// Header file for lexeme class

#ifndef __LEXEME_INCLUDED__
#define __LEXEME_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

typedef struct LEXEME LEXEME;

extern LEXEME *newLexeme(char *, char *);
extern char *getType(LEXEME *);
extern char *getStringToken(LEXEME *);
extern LEXEME *getLeft(LEXEME *);
extern LEXEME *getRight(LEXEME *);
extern void setLeft(LEXEME *, LEXEME *);
extern void setRight(LEXEME *, LEXEME *);
extern void display(LEXEME *);
extern void displayLexemeValue(LEXEME *);

#endif