// Ian Braudaway
// Implementation file for evaluator

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "environment.h"
#include "evaluator.h"

static LEXEME *eval(LEXEME *, LEXEME *);
static LEXEME *evalUNot(LEXEME *, LEXEME *);
static LEXEME *evalUMinus(LEXEME *, LEXEME *);
static LEXEME *evalPlus(LEXEME *, LEXEME *);
static LEXEME *evalMinus(LEXEME *, LEXEME *);
static LEXEME *evalMultiply(LEXEME *, LEXEME *);
static LEXEME *evalDivide(LEXEME *, LEXEME *);
static LEXEME *evalNot(LEXEME *, LEXEME *);
static LEXEME *evalCe(LEXEME *, LEXEME *);
static LEXEME *evalLt(LEXEME *, LEXEME *);
static LEXEME *evalLte(LEXEME *, LEXEME *);
static LEXEME *evalGt(LEXEME *, LEXEME *);
static LEXEME *evalGte(LEXEME *, LEXEME *);
static LEXEME *evalMod(LEXEME *, LEXEME *);
static LEXEME *evalAnd(LEXEME *, LEXEME *);
static LEXEME *evalOr(LEXEME *, LEXEME *);
static LEXEME *evalAssign(LEXEME *, LEXEME *);
static LEXEME *evalBlock(LEXEME *, LEXEME *);
static LEXEME *evalVarDef(LEXEME *, LEXEME *);
static LEXEME *evalFuncDef(LEXEME *, LEXEME *);
static LEXEME *evalLambda(LEXEME *, LEXEME *);
static LEXEME *getClosureParams(LEXEME *);
static LEXEME *getClosureBody(LEXEME *);
static LEXEME *getClosureEnvironment(LEXEME *);
static LEXEME *evalAt(LEXEME *, LEXEME *);
static LEXEME *evalGa(LEXEME *, LEXEME *);
static LEXEME *evalSa(LEXEME *, LEXEME *);
static LEXEME *evalPrint(LEXEME *, LEXEME *);
static LEXEME *evalFuncCall(LEXEME *, LEXEME *);
static LEXEME *evalArgs(LEXEME *, LEXEME *);
static LEXEME *evalParams(LEXEME *, LEXEME *);
static LEXEME *evalStatements(LEXEME *, LEXEME *);
static LEXEME *evalWhile(LEXEME *, LEXEME *);
static LEXEME *evalIf(LEXEME *, LEXEME *);
static LEXEME *evalElse(LEXEME *, LEXEME *);
static LEXEME *evalReturn(LEXEME *, LEXEME *);
static LEXEME *evalMoreProgram(LEXEME *, LEXEME *);
static LEXEME *evalEnd(LEXEME *, LEXEME *);
static LEXEME *evalNewArray(LEXEME *);
static LEXEME *evalGetArray(LEXEME *);
static LEXEME *evalSetArray(LEXEME *);

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
        return evalFuncCall(tree, env);
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
        return evalBlock(tree, env);
    }
    else if (getType(tree) == UMINUS)
    {
        return evalUMinus(tree, env);
    }
    else if (getType(tree) == UNOT)
    {
        return evalUNot(tree, env);
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
        return evalAt(getRight(tree), env);
    }
    else if (getType(tree) == GET_ARRAY)
    {
        return evalGa(tree, env);
    }
    else if (getType(tree) == SET_ARRAY)
    {
        return evalSa(tree, env);
    }
    else if (getType(tree) == PRINT)
    {
        return evalPrint(getRight(tree), env);
    }
    else if (getType(tree) == IF)
    {
        return evalIf(tree, env);
    }
    else if (getType(tree) == ELSE)
    {
        return evalElse(tree, env);
    }
    else if (getType(tree) == WHILE)
    {
        return evalWhile(tree, env);
    }
    else if (getType(tree) == RETURN)
    {
        return evalReturn(tree, env);
    }
    else if (getType(tree) == MOREPROGRAM)
    {
        return evalMoreProgram(tree, env);
    }
    else if (getType(tree) == VAR)
    {
        return evalVarDef(tree, env);
    }
    else if (getType(tree) == FUNC)
    {
        return evalFuncDef(tree, env);
    }
    else if (getType(tree) == LAMBDA)
    {
        return evalLambda(tree, env);
    
    else if (getType(tree) == ARGLIST)
    {
        return evalArgs(tree, env);
    }
    else if (getType(tree) == PARAMLIST)
    {
        return evalParams(tree, env);
    }
    else if (getType(tree) == STATEMENTS)
    {
        return evalStatements(tree, env);
    }
    else if (getType(tree) == ENDofINPUT)
    {
        return evalEnd(tree, env);
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
evalUNot(LEXEME *tree, LEXEME *env)
{
    LEXEME *right = eval(getRight(tree), env);

    if (getType(right) == INTEGER)
    {
        if (getIntegerToken(right) == 0)
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
        printf("EVALUATOR: incompatible UNOT operation.\n");
        exit(1);
    }
}

LEXEME *
evalUMinus(LEXEME *tree, LEXEME *env)
{
    LEXEME *right = eval(getRight(tree), env);
    LEXEME *returnLex;

    if (getType(right) == INTEGER)
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, - getIntegerToken(right));
        return returnLex;
    }
    else if (getType(right) == REAL)
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, - getRealToken(right));
        return returnLex;
    }
    else if (getType(right) == STRING)
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strrev(getStringToken(right)));
        return returnLex;
    }
    else
    {
        printf("EVALUATOR: incompatible UMINUS operation.\n");
        exit(1);
    }
}

LEXEME *
evalPlus(LEXEME *tree, LEXEME *env)
{
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);
    char buffer[20];
    LEXEME *returnLex;

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, getIntegerToken(left) + getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getIntegerToken(left) + getRealToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) + getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) + getRealToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == STRING))
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strcat(itoa(getIntegerToken(left), buffer, 10), getStringToken(right)));
        return returnLex;
    }
    else if ((getType(left) == STRING) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strcat(getStringToken(left), itoa(getIntegerToken(right), buffer, 10)));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == STRING))
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strcat(itoa(getRealToken(left), buffer, 10), getStringToken(right)));
        return returnLex;
    }
    else if ((getType(left) == STRING) && (getType(right) == REAL))
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strcat(getStringToken(left), itoa(getRealToken(right), buffer, 10)));
        return returnLex;
    }
    else if ((getType(left) == STRING) && (getType(right) == STRING))
    {
        returnLex = newLexeme(STRING, NULL);
        setStringToken(returnLex, strcat(getStringToken(left), getStringToken(right)));
        return returnLex;
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
    LEXEME *returnLex;

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, getIntegerToken(left) - getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getIntegerToken(left) - getRealToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) - getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) - getRealToken(right));
        return returnLex;
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
    LEXEME *returnLex;

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, getIntegerToken(left) * getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getIntegerToken(left) * getRealToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) * getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) * getRealToken(right));
        return returnLex;
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
    LEXEME *returnLex;

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, getIntegerToken(left) / getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getIntegerToken(left) / getRealToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) / getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        returnLex = newLexeme(REAL, NULL);
        setRealToken(returnLex, getRealToken(left) / getRealToken(right));
        return returnLex;
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
    LEXEME *returnLex;

    if ((getType(left) == INTEGER) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, getIntegerToken(left) % getIntegerToken(right));
        return returnLex;
    }
    else if ((getType(left) == INTEGER) && (getType(right) == REAL))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, fmod(getIntegerToken(left), getRealToken(right)));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == INTEGER))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, fmod(getRealToken(left), getIntegerToken(right)));
        return returnLex;
    }
    else if ((getType(left) == REAL) && (getType(right) == REAL))
    {
        returnLex = newLexeme(INTEGER, NULL);
        setIntegerToken(returnLex, fmod(getRealToken(left), getRealToken(right)));
        return returnLex;
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
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);

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
    LEXEME *left = eval(getLeft(tree), env);
    LEXEME *right = eval(getRight(tree), env);

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

LEXEME *
evalBlock(LEXEME *tree, LEXEME *env)
{
    LEXEME *result;
    while (tree = != NULL)
    {
        result = eval(getRight(tree), env);
        tree = getRight(getRight(tree));
    }

    return result;
}

LEXEME *
evalVarDef(LEXEME *tree, LEXEME *env)
{
    LEXEME *closure = cons(CLOSURE, env, tree);
    insert(getLeft(tree), closure, env);
    return closure;
}

LEXEME *
evalFuncDef(LEXEME *tree, LEXEME *env)
{
    LEXEME *closure = cons(CLOSURE, env, tree);
    insert(getLeft(getLeft(tree)), closure, env);
    return closure;
}

LEXEME *
evalLambda(LEXEME *tree, LEXEME *env)
{
    return cons(CLOSURE, env, tree);
}

LEXEME *
getClosureParams(LEXEME *closure)
{
    if (closure == NULL)
    {
        return NULL;
    }
    else
    {
        return getRight(getLeft(getRight(closure)));
    }
}

LEXEME *
getClosureBody(LEXEME *closure)
{
    if (closure == NULL)
    {
        return NULL;
    }
    else
    {
        return getRight(getRight(closure));
    }
}

LEXEME *
getClosureEnvironment(LEXEME *closure)
{
    if (closure == NULL)
    {
        return NULL;
    }
    else
    {
        return getLeft(closure);
    }
}

LEXEME *
evalPrint(LEXEME *argList, LEXEME *env)
{
    LEXEME *evaluatedArgList = evalArgs(argList);

    while (evaluatedArgList != 0)
    {
        display(getLeft(evaluatedArgList));
        evaluatedArgList = getRight(evaluatedArgList);
    }

    return evaluatedArgList;
}

LEXEME *
evalFuncCall(LEXEME *tree, LEXEME *env)
{
    LEXEME *name = lookup(getLeft(tree), env);
    LEXEME *args = getRight(tree);
    LEXEME *eargs = evalArgs(args, env);    
    LEXEME *closure = eval(name, env);
    LEXEME *params = getClosureParams(closure);
    LEXEME *body = getClosureBody(closure);
    LEXEME *senv = getClosureEnvironment(closure);
    LEXEME *xenv = extend(params, eargs, senv);

    return eval(body,xenv);
}

LEXEME *
evalArgs(LEXEME *tree, LEXEME *env)
{
    if (tree == NULL)
    {
        return NULL;
    }

    else
    {
        return cons(GLUE, eval(getLeft(tree), env), evalArgs(getRight(tree), env));
    }
}

LEXEME *
evalParams(LEXEME *tree, LEXEME *env)
{
    if (tree == NULL)
    {
        return NULL;
    }

    else
    {
        return cons(GLUE, eval(getLeft(tree), env), evalParams(getRight(tree), env));
    }
}

LEXEME *
evalStatements(LEXEME *tree, LEXEME *env)
{
    if (tree == NULL)
    {
        return NULL;
    }

    else
    {
        return cons(GLUE, eval(getLeft(tree), env), evalStatements(getRight(tree), env));
    }
}

LEXEME *
evalWhile(LEXEME *tree, LEXEME *env)
{
    LEXEME *whileExpr = getLeft(tree);
    LEXEME *block = getRight(tree); 

    while(getIntegerToken(eval(whileExpr, env)) == 1)
    {
        block = evalBlock(block);
    }

    return block;
}


LEXEME *
evalIf(LEXEME *tree, LEXEME *env)
{
    LEXEME *expr = eval(getLeft(tree), env);
    if (getIntegerToken(expr) == 1)
    {
        LEXEME *block = evalBlock(getLeft(getRight(tree)), env);
        return block;
    }
    else
    {
        LEXEME *elses = evalElse(tree, env);
        return elses;
    }
}

LEXEME *
evalElse(LEXEME *tree, LEXEME *env)
{
    return eval(getRight(tree), env);
}

LEXEME *
evalReturn(LEXEME *tree, LEXEME *env)
{
    return eval(getRight(tree), env);
}

LEXEME *
evalMoreProgram(LEXEME *tree, LEXEME *env)
{
    if (tree == NULL)
    {
        return NULL;
    }

    else
    {
        return cons(GLUE, eval(getLeft(tree), env), evalMoreProgram(getRight(tree), env));
    }
}

LEXEME *
evalEnd(LEXEME *tree, LEXEME *env)
{
    return eval(getLeft(tree), env);
}

LEXEME *
evalAt(LEXEME *tree, LEXEME *env)
{
    LEXEME *evaluatedArgList = evalArgs(tree, env);
    return evalNewArray(evaluatedArgList);
}

LEXEME *
evalNewArray(LEXEME *evaluatedArgList)
{
    assert(cdr(evaluatedArgList) == NULL)  //ensure only one argument
    LEXEME *size = car(evaluatedArgList);
    assert(getType(size) == INTEGER);          //ensure an integer argument
    LEXEME *a = newLexeme(AT, NULL);
    setAvalToken(a, getIntegerToken(size));  //allocate the array     
    assert(getAvalToken(a) != NULL);                //ensure a good allocation
    return a;
}

LEXEME *
evalGa(LEXEME *tree, LEXEME *env)
{
    LEXEME *evaluatedArgList = evalArgs(tree, env);
    return evalGetArray(evaluatedArgList);
}

LEXEME *
evalGetArray(LEXEME *evaluatedArgList)
{
    assert(cdr(cdr(evaluatedArgList)) == NULL);
    LEXEME *a = car(evaluatedArgList);
    LEXEME *i = car(cdr(evaluatedArgList));
    
    //check for valid types here
    assert(getType(a) == AT);
    assert(getType(i) == INTEGER);

    LEXEME **aval = getAvalToken(a);
    int index = getIntegerToken(i);
    return aval[index];
}

LEXEME *
evalSa(LEXEME *tree, LEXEME *env)
{
    LEXEME *evaluatedArgList = evalArgs(tree, env);
    return evalSetArray(evaluatedArgList);
}

LEXEME *
evalSetArray(LEXEME *evaluatedArgList)
{
    assert(cdr(cdr(cdr(evaluatedArgList))) == NULL);
    LEXEME *a = car(evaluatedArgList);
    LEXEME *i = car(cdr(evaluatedArgList));
    LEXEME *v = car(cdr(cdr(evaluatedArgList)));
    
    //check for valid types here
    assert(getType(a) == AT);
    assert(getType(i) == INTEGER);
    assert(getType(v) != NULL);

    LEXEME **aval = getAvalToken(a);
    int index = getIntegerToken(i);
    aval[index] = v;
    return v;                      //could also return the previous value
}