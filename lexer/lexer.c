// Ian Braudaway
// Implementation file for lexer class

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"
#include "types.h"
#include "lexeme.h"

LEXEME *
lex()
{
    char ch;

    skipWhiteSpace();

    ch = Input.read(); 

    if (Input.failed) return newLexeme(ENDofINPUT); 

    switch(ch) 
        { 
        // single character tokens 

        case '[': return new lexeme(OPEN_BRACKET); 
        case ']': return new lexeme(CLOSE_BRACKET); 
        case '|': return new lexeme(BAR); 
        case '+': return new lexeme(PLUS); //what about ++ and += ?
        case '*': return new lexeme(MULTIPLY); 
        case '-': return new lexeme(MINUS); 
        case '/': return new lexeme(DIVIDE); 
        case '<': return new lexeme(LESS_THAN); 
        case '>': return new lexeme(GREATER_THAN); 
        case '=': return new lexeme(EQUAL); 
        case '@': return new lexeme(AT);
        case '%': return new lexeme(MODULO);
        case '!': return new lexeme(NOT);

        //add any other cases here

        default: 
        // multi-character tokens (only numbers, 
        // variables/keywords, and strings) 
            if (isdigit(ch)) 
                { 
                Input.pushback(ch); 
                return lexNumber(); 
                } 
            else if (isalpha(ch)) 
                { 
                Input.pushback(ch); 
                return lexVariableOrKeyword();
                } 
            else if (ch == '\"') 
                { 
                return lexString(); 
                } 
            else
                return newLexeme(UNKNOWN, ch); 
        } 
}