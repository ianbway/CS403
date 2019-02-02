// Ian Braudaway
// Header file for environment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"

extern LEXEME *create();
extern LEXEME *lookup(LEXEME *, LEXEME *);
extern void update(LEXEME *, LEXEME *, LEXEME *);
extern LEXEME *insert(LEXEME *, LEXEME *, LEXEME *);
extern LEXEME *extend(LEXEME *, LEXEME *, LEXEME *);