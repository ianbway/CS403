// Ian Braudaway
// Implementation file for lexer class

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lexer.h"
#include "types.h"
#include "lexeme.h"

#include "string.h"
#include "real.h"
#include "integer.h"

char PushbackCharacter;
bool CharacterHasBeenPushed = false;

struct LEXER
{
    FILE *file;
}

LEXER *
newLexer(FILE *fp)
{
    LEXER *lex = malloc(sizeof(LEXER));
    if (lex == 0) { fprintf(stderr,"out of memory\n"); exit(1); }

    lex->file = fp;
    return lex;
}

char myRead()
{
    if (CharacterHasBeenPushed)
    {
        CharacterHasBeenPushed = false;
        return PushbackCharacter;
    }
    else
        return Input.read();
}

void myPushback(ch)
{
    if (CharacterHasBeenPushed) Fatal("too many pushbacks");
    CharacterHasBeenPushed = true;
    PushbackCharacter = ch;
}

void skipWhiteSpace()
{
    char ch;
    while (isspace(ch))
        ch = Input.read();

    // the character that got us out of the loop was NOT whitespace
    // so we need to push it back so it can be read again.

    Input.pushback(ch);
}

LEXEME *lexVariableOrKeyword()
{
    char ch;
    char *token = "";
        
    ch = Input.read();
    while (isalpha(ch) || isdigit(ch))
    {
        token = token + ch; //grow the token string
        ch = Input.read();
    }

    //push back the character that got us out of the loop
    //it may be some kind of punctuation

    Input.pushback(ch);

    //token holds either a variable or a keyword, so figure it out

    if (strcmp(token,"if") != 0) 
        return newLexeme(IF);
    else if (strcmp(token,"else") != 0) 
        return newLexeme(ELSE);
    else if (strcmp(token,"while") != 0) 
        return newLexeme(WHILE);
        //more keyword testing here
    else //must be a variable!
        return newLexeme(VARIABLE,token);
}

//lexNumber

//lexString

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