// Ian Braudaway
// Implementation file for scanner class

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "types.h"
#include "lexeme.h"

void scanner(filename) 
{ 
    LEXEME *token; 
    LEXER *i = newLexer(fileName);

    token = i.lex(); 
    while (token.type != ENDofINPUT) 
    { 
        Lexeme.display(token); 
        token = i.lex(); 
    } 
}