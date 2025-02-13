// Ian Braudaway
// Implementation file for lexeme class

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lexeme.h"
#include "types.h"

struct LEXEME
{
    char *type;
    char *string;
    int integer;
    double real;

    LEXEME *left;
    LEXEME *right;
};

LEXEME *
newLexeme(char *type, char *token)
{
    LEXEME *lexeme = malloc(sizeof(LEXEME));

    if (lexeme == 0) 
    { 
        fprintf(stderr,"out of memory\n"); 
        exit(1); 
    }

    lexeme->type = type;

    //int, convert string to integer
    if (lexeme->type == INTEGER)
    {
        lexeme->integer = atoi(token);
    }

    //real, convert string to float
    else if (lexeme->type == REAL)
    {
        lexeme->real = atof(token);
    }

    //string or variable, or anything else
    else
    {
        lexeme->string = token;
    }

    return lexeme;
}

char *
getType(LEXEME *lex)
{
    if (lex != NULL) 
    {
        return lex->type;
    }

    else
    {
        return NULL;
    }
}

char *
getStringToken(LEXEME *lex)
{
    if ((lex != NULL) && (lex->string != NULL)) 
    {
        return lex->string;
    }

    else
    {
        return NULL;
    }
}

int
getIntegerToken(LEXEME *lex)
{
    if ((lex != NULL)) 
    {
        return lex->integer;
    }

    else
    {
        return 1;
    }
}

double
getRealToken(LEXEME *lex)
{
    if ((lex != NULL)) 
    {
        return lex->real;
    }

    else
    {
        return 1.0;
    }
}

LEXEME *
getLeft(LEXEME *lex)
{
    if ((lex != NULL) && (lex->left != NULL))
    {
        return lex->left;
    }
    
    else
    {
        return NULL;
    }
}

LEXEME *
getRight(LEXEME *lex)
{
    if ((lex != NULL) && (lex->right != NULL))
    {
        return lex->right;
    }
    
    else
    {
        return NULL;
    }
}

void
setLeft(LEXEME *lex, LEXEME *leftLex)
{
    lex->left = leftLex;
}

void
setRight(LEXEME *lex, LEXEME *rightLex)
{
    lex->right = rightLex;
}

void
display(LEXEME *lex)
{
    fprintf(stdout, "%s ", lex->type);

    //string
    if (lex->type == STRING)
    {
        fprintf(stdout, "\"%s\"\n", lex->string);
    }

    //variable
    else if (lex->type == VARIABLE)
    {
        fprintf(stdout, "%s\n", lex->string);
    }

    //int
    else if (lex->type == INTEGER)
    {
        fprintf(stdout, "%d\n", lex->integer);
    }

    //real
    else if (lex->type == REAL)
    {
        fprintf(stdout, "%f\n", lex->real);
    }

    //no token
    else
    {
        fprintf(stdout, "\n");
    }
}

void
displayLexemeValue(LEXEME *lex)
{

    //int
    if (lex->type == INTEGER)
    {
        fprintf(stdout, "%d\n", lex->integer);
    }

    //real
    else if (lex->type == REAL)
    {
        fprintf(stdout, "%f\n", lex->real);
    }

    //string
    else
    {
        fprintf(stdout, "%s\n", lex->string);
    }

}