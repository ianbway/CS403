// Ian Braudaway
// Implementation file for evaluator

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "environment.h"
#include "evaluator.h"

LEXEME *
eval(LEXEME *tree, LEXEME *env)
{
    if (getType(tree) == INTEGER)
    {
        return tree;
    }
    else if (getType(tree) == REAL)
    { 
        return tree;
    }
    else if (getType(tree) == VARIABLE)
    { 
        return lookup(tree, env);
    }
    else if (getType(tree) == VARIABLE_EXPR)
    {
        eval(getLeft(tree), env);
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == STRING)
    { 
        return tree;
    }
    else if (getType(tree) == OPEN_BRACKET)
    {
        return eval(getRight(tree), env);
    }
    else if (getType(tree) == OPEN_BLOCK)
    {
        printf("\t:\n");
        eval(getRight(tree), env);
        printf("\t;\n");
    }
    else if (getType(tree) == UMINUS)
    {
        printf("-");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == UNOT)
    {
        printf("!");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == NOT)
    {
        return evalNot(tree, env);
    }
    else if (getType(tree) == PLUS)
    {
        return evalPlus(tree, env);
    }
    else if (getType(tree) == MINUS)
    {
        return evalMinus(tree, env);
    }
    else if (getType(tree) == MULTIPLY)
    {
        return evalMultiply(tree, env);
    }
    else if (getType(tree) == DIVIDE)
    {
        return evalDivide(tree, env);
    }
    else if (getType(tree) == LESS_THAN)
    {
        return evalLt(tree, env);
    }
    else if (getType(tree) == LESS_THAN_EQUAL)
    {
        return evalLte(tree, env);
    }
    else if (getType(tree) == GREATER_THAN)
    {
        return evalGt(tree, env);
    }
    else if (getType(tree) == GREATER_THAN_EQUAL)
    {
        return evalGte(tree, env);
    }
    else if (getType(tree) == EQUAL)
    {
        return evalAssign(tree, env);
    }
    else if (getType(tree) == COMPARE_EQUAL)
    {
        return evalCe(tree, env);
    }
    else if (getType(tree) == MODULO)
    {
        return evalMod(tree, env);
    }
    else if (getType(tree) == OR)
    {
        return evalOr(tree, env);
    }
    else if (getType(tree) == AND)
    {
        return evalAnd(tree, env);
    }
    else if (getType(tree) == AT)
    {
        printf("@");
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == PRINT)
    {
        printf("print");
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == IF)
    {
        printf("if ");
        printf("[");
        eval(getLeft(tree), env);
        printf("]\n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == ELSE)
    {
        printf("else \n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == WHILE)
    {
        printf("while ");
        printf("[");
        eval(getLeft(tree), env);
        printf("]\n");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == RETURN)
    {
        printf("return ");
        eval(getRight(tree), env);
        printf("\n");
    }

    else if (getType(tree) == MOREPROGRAM)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == VAR)
    {
        printf("var ");
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
        printf("\n");
    }
    else if (getType(tree) == FUNC)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == FUNCDEF)
    {
        printf("func ");
        eval(getLeft(tree), env);
        printf("[");
        eval(getRight(tree), env);
        printf("]\n");
    }
    else if (getType(tree) == ARGLIST)
    {
        eval(getLeft(tree), env);
        printf("| ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == PARAMLIST)
    {
        eval(getLeft(tree), env);
        printf("| ");
        eval(getRight(tree), env);
    }
    else if (getType(tree) == STATEMENTS)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == IFJOIN)
    {
        eval(getLeft(tree), env);
        eval(getRight(tree), env);
    }
    else if (getType(tree) == ENDofINPUT)
    {
        eval(getLeft(tree), env);
        printf("\n");
    }
    else if (getType(tree) == NULL)
    {
        
    }
    else 
    {
        printf("bad expression!\n"); 
    }  
}

LEXEME *
evalPlus(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {

        return newLexeme(INTEGER, itoa(getIntegerToken(left) + getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getIntegerToken(left) + getRealToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {

        return newLexeme(REAL, itoa(getRealToken(left) + getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getRealToken(left) + getRealToken(right), buffer, 10));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == STRING))
    {

        return newLexeme(STRING, strcat(itoa(getIntegerToken(left), buffer, 10), getStringToken(right)));
    }
    else if ((getType(left) == STRING) && (getType(right) == INTEGER))
    {

        return newLexeme(STRING, strcat(getStringToken(left), itoa(getIntegerToken(right), buffer, 10)));
    }
    else if ((getType(left) == REAL) && (getType(right) == STRING))
    {

        return newLexeme(STRING, strcat(itoa(getRealToken(left), buffer, 10), getStringToken(right)));
    }
    else if ((getType(left) == STRING) && (getType(right) == REAL))
    {

        return newLexeme(STRING, strcat(getStringToken(left), itoa(getRealToken(right), buffer, 10)));
    }
    else if ((getType(left) == STRING) && (getType(right) == STRING))
    {

        return newLexeme(STRING, strcat(getStringToken(left), getStringToken(right)));
    }
    else
    {
        printf("EVALUATOR: incompatible PLUS operation.\n");
        exit(1);
    }

}

LEXEME *
evalMinus(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {

        return newLexeme(INTEGER, itoa(getIntegerToken(left) - getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getIntegerToken(left) - getRealToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {

        return newLexeme(REAL, itoa(getRealToken(left) - getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getRealToken(left) - getRealToken(right), buffer, 10));
    }
    else
    {
        printf("EVALUATOR: incompatible MINUS operation.\n");
        exit(1);
    }
}

LEXEME *
evalMultiply(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {

        return newLexeme(INTEGER, itoa(getIntegerToken(left) * getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getIntegerToken(left) * getRealToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {

        return newLexeme(REAL, itoa(getRealToken(left) * getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getRealToken(left) * getRealToken(right), buffer, 10));
    }
    else
    {
        printf("EVALUATOR: incompatible MULTIPLY operation.\n");
        exit(1);
    }
}

LEXEME *
evalDivide(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {

        return newLexeme(INTEGER, itoa(getIntegerToken(left) / getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getIntegerToken(left) / getRealToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {

        return newLexeme(REAL, itoa(getRealToken(left) / getIntegerToken(right), buffer, 10));
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {

        return newLexeme(REAL, itoa(getRealToken(left) / getRealToken(right), buffer, 10));
    }
    else
    {
        printf("EVALUATOR: incompatible DIVIDE operation.\n");
        exit(1);
    }
}

LEXEME *
evalNot(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) != getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) != getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) != getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) != getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == STRING))
    {
        if (getIntegerToken(left) != getStringToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == INTEGER))
    {
        if (getStringToken(left) != getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == STRING))
    {
        if (getRealToken(left) != getStringToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == REAL))
    {
        if (getStringToken(left) != getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == STRING))
    {
        if (strcmp(getStringToken(left), getStringToken(right)) != 0)
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible NOT operation.\n");
        exit(1);
    }   
}

LEXEME *
evalCe(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) == getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) == getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) == getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) == getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == STRING))
    {
        if (getIntegerToken(left) == getStringToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == INTEGER))
    {
        if (getStringToken(left) == getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == STRING))
    {
        if (getRealToken(left) == getStringToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == REAL))
    {
        if (getStringToken(left) == getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == STRING) && (getType(right) == STRING))
    {
        if (strcmp(getStringToken(left), getStringToken(right)) == 0)
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible COMPARE_EQUAL operation.\n");
        exit(1);
    }   
}

LEXEME *
evalLt(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) < getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) < getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) < getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) < getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible LESS_THAN operation.\n");
        exit(1);
    }   
}

LEXEME *
evalLte(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) <= getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) <= getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) <= getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) <= getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible LESS_THAN_EQUAL operation.\n");
        exit(1);
    }   
}

LEXEME *
evalGt(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) > getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) > getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) > getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) > getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible GREATER_THAN operation.\n");
        exit(1);
    }   
}

LEXEME *
evalGte(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if (getIntegerToken(left) >= getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if (getIntegerToken(left) >= getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if (getRealToken(left) >= getIntegerToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if (getRealToken(left) >= getRealToken(right))
        {
            return newLexeme(INTEGER, "1");
        }

        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible GREATER_THAN_EQUAL operation.\n");
        exit(1);
    }   
}

LEXEME *
evalMod(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    LEXEME *modRes;
    char buffer[20];

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        modRes = getIntegerToken(left) % getIntegerToken(right);
        return newLexeme(INTEGER, itoa(modRes));
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        modRes = getIntegerToken(left) % getRealToken(right);
        return newLexeme(INTEGER, itoa(modRes));
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        modRes = getRealToken(left) % getIntegerToken(right);
        return newLexeme(INTEGER, itoa(modRes));
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        modRes = getRealToken(left) % getRealToken(right);
        return newLexeme(INTEGER, itoa(modRes));
    }
    else
    {
        printf("EVALUATOR: incompatible MODULO operation.\n");
        exit(1);
    }   
}

LEXEME *
evalAnd(LEXEME *tree, LEXEME *env)
{
    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if ((getIntegerToken(left) != 0) && (getIntegerToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if ((getIntegerToken(left) != 0) && (getRealToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if ((getRealToken(left) != 0) && (getIntegerToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if ((getRealToken(left) != 0) && (getRealToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible AND operation.\n");
        exit(1);
    }   
}

LEXEME *
evalOr(LEXEME *tree, LEXEME *env)
{
    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        if ((getIntegerToken(left) != 0) || (getIntegerToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        if ((getIntegerToken(left) != 0) || (getRealToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        if ((getRealToken(left) != 0) || (getIntegerToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        if ((getRealToken(left) != 0) || (getRealToken(right) != 0))
        {
            return newLexeme(INTEGER, "1");
        }
        else
        {
            return newLexeme(INTEGER, "0");
        }
    }
    else
    {
        printf("EVALUATOR: incompatible OR operation.\n");
        exit(1);
    }   
}

LEXEME *
evalAssign(LEXEME *tree, LEXEME *env)
{
    LEXEME *value = eval(getRight(tree), env);
    update(getLeft(tree), value, env);
    return value;
}


