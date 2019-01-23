// Ian Braudaway
// Implementation file for lexer class

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "lexeme.h"
#include "lexer.h"
#include "types.h"

struct LEXER
{
    FILE *file;
    int lineNumber;
};

LEXER *
newLexer(FILE *fp)
{
    LEXER *lex = malloc(sizeof(LEXER));
    if (lex == 0) 
    { 
        fprintf(stderr,"out of memory\n"); 
        exit(1); 
    }

    lex->file = fp;
    lex->lineNumber = 0;

    return lex;
}

void 
skipWhiteSpace(LEXER *lex)
{
    char ch;

    ch = fgetc(lex->file);
    while (isspace(ch) || (ch == '#'))
    {
        if (ch == '\n')
        {
            lex->lineNumber = lex->lineNumber + 1;
        }

        if (ch == '#')
        {
            ch = fgetc(lex->file);
            while (ch != '#')
            {
                ch = fgetc(lex->file);
            }
            //ungetc(ch, lex->file);
        }

        ch = fgetc(lex->file);
    }

    // the character that got us out of the loop was NOT whitespace
    // so we need to push it back so it can be read again.

    ungetc(ch, lex->file);
}

LEXEME *
lexVariableOrKeyword(LEXER *lex)
{
    char ch;
    char *token = "";
        
    ch = fgetc(lex->file);
    while (isalpha(ch) || isdigit(ch))
    {
        token = token + ch; //grow the token string
        ch = fgetc(lex->file);
    }

    //push back the character that got us out of the loop
    //it may be some kind of punctuation

    ungetc(ch, lex->file);

    //token holds either a variable or a keyword, so figure it out

    if (strcmp(token,"if") == 0) 
        return newLexeme(IF, NULL);
    else if (strcmp(token,"else") == 0) 
        return newLexeme(ELSE, NULL);
    else if (strcmp(token,"while") == 0) 
        return newLexeme(WHILE, NULL);
    else if (strcmp(token,"var") == 0) 
        return newLexeme(VAR, NULL);
    else if (strcmp(token,"func") == 0) 
        return newLexeme(FUNC, NULL);
    else if (strcmp(token,"return") == 0) 
        return newLexeme(RETURN, NULL);
    else if (strcmp(token,"print") == 0) 
        return newLexeme(PRINT, NULL);
    else if (strcmp(token,"or") == 0) 
        return newLexeme(OR, NULL);
    else if (strcmp(token,"and") == 0) 
        return newLexeme(AND, NULL);
        //more keyword testing here
    else //must be a variable!
        return newLexeme(VARIABLE,token);
}

LEXEME *
lexNumber(LEXER *lex)
{
    int real = 0;
    char ch;
    char *token = "";

    ch = fgetc(lex->file);
    while ((!feof(lex->file) && (isdigit(ch))) || (ch == '.'))
    {
        token = token + ch;
        if (ch == '.' && real)
        {
            fprintf(stderr,"BAD NUMBER, line number : %d \n", lex->lineNumber); 
            exit(1);
        }

        if (ch == '.')
        {
            real = 1;
        }

        ch = fgetc(lex->file);
    }
    ungetc(ch, lex->file);

    if (real)
    {
        return newLexeme(REAL, token);
    }

    else
    {
        return newLexeme(INTEGER, token);
    }
}

LEXEME *
lexString(LEXER *lex)
{

    char ch;
    char *token = "";

    ch = fgetc(lex->file);
    while ((!feof(lex->file) && (isalpha(ch))) || (ch == '\"'))
    {
        token = token + ch;

        ch = fgetc(lex->file);
    }
    ungetc(ch, lex->file);

    return newLexeme(STRING, token);
}

LEXEME *
lex(LEXER *lex)
{
    char ch;
    char next;

    skipWhiteSpace(lex);

    ch = fgetc(lex->file); 

    if (lex->file == NULL)
    {
        return newLexeme(ENDofINPUT, NULL); 
    }

    switch(ch) 
    { 
        // single character tokens 

        case '[': 
            next = fgetc(lex->file);
            if (next == '[')
            {
                return newLexeme(OPEN_BLOCK, NULL);
            }

            else
            {
                ungetc(next, lex->file);
                return newLexeme(OPEN_BRACKET, NULL);
            }
             
        case ']': 
            next = fgetc(lex->file);
            if (next == ']')
            {
                return newLexeme(CLOSE_BLOCK, NULL);
            }

            else
            {
                ungetc(next, lex->file);
                return newLexeme(CLOSE_BRACKET, NULL);
            }
         
        case '|': return newLexeme(BAR, NULL); 
        case '+':  //what about ++ and += ?
            next = fgetc(lex->file);
            if (next == '+')
            {
                return newLexeme(PLUSPLUS, NULL);
            }

            else
            {
                ungetc(next, lex->file);
                return newLexeme(PLUS, NULL);
            }

        case '*': return newLexeme(MULTIPLY, NULL); 
        case '-': return newLexeme(MINUS, NULL); 
        case '/': return newLexeme(DIVIDE, NULL); 
        case '<': 
            next = fgetc(lex->file);
            if (next == '=')
            {
                return newLexeme(LESS_THAN_EQUAL, NULL);
            }

            else
            {
                ungetc(next, lex->file);
                return newLexeme(LESS_THAN, NULL);
            } 

        case '>': 
            next = fgetc(lex->file);
            if (next == '=')
            {
                return newLexeme(GREATER_THAN_EQUAL, NULL);
            }

            else
            {
                ungetc(next, lex->file);
                return newLexeme(GREATER_THAN, NULL);
            }

        case '=': return newLexeme(EQUAL, NULL); 
        case '@': return newLexeme(AT, NULL);
        case '%': return newLexeme(MODULO, NULL);
        case '!': return newLexeme(NOT, NULL);

        //add any other cases here

        default: 
        // multi-character tokens (only numbers, 
        // variables/keywords, and strings) 
            if (isdigit(ch)) 
            { 
                ungetc(ch, lex->file); 
                return lexNumber(lex); 
            } 
            else if (isalpha(ch)) 
            { 
                ungetc(ch, lex->file); 
                return lexVariableOrKeyword(lex);
            } 
            else if (ch == '\"') 
            { 
                return lexString(lex); 
            } 
            else
                //need line #
                fprintf(stderr,"UNKNOWN character, line number : %d \n", lex->lineNumber); 
                exit(1);  
    } 
}