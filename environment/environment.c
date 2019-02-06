// Ian Braudaway
// Implementation file for environment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "lexeme.h"
#include "types.h"
#include "environment.h"

static LEXEME *cons(char *, LEXEME *, LEXEME *);
static LEXEME *car(LEXEME *);
static LEXEME *cdr(LEXEME *);
static void setCar(LEXEME *, LEXEME *);
static void setCdr(LEXEME *, LEXEME *);

LEXEME *
cons(char *type, LEXEME *left, LEXEME *right)
{
    LEXEME *consLex = newLexeme(type, NULL);
    setLeft(consLex, left);
    setRight(consLex, right);
    return consLex;
}

LEXEME *
car(LEXEME *lex)
{
    return getLeft(lex);
}

LEXEME *
cdr(LEXEME *lex)
{
    return getRight(lex);
}

void
setCar(LEXEME *lex, LEXEME *newLeft)
{
    setLeft(lex, newLeft);
}

void
setCdr(LEXEME *lex, LEXEME *newRight)
{
    setRight(lex, newRight);
}

LEXEME *
create()
{
    return cons("ENV", NULL, cons("VALUES", NULL, NULL));
}

LEXEME *
lookup(char *variable, LEXEME *env)
{
    while (env != NULL)
    {
        LEXEME *vars = car(env);
        LEXEME *vals = car(cdr(env));
        while (vars != NULL)
        {
            printf("TEST\n");
            if (strcmp(variable, getStringToken(car(vars))) == 0)
            {
                return car(vals);
            }
            vars = cdr(vars);
            vals = cdr(vals);
        }
        env = cdr(cdr(env));
    }
    fprintf(stdout,"FATAL variable: %s is undefined.\n", variable); 
    exit(1); 
    return NULL;
}

void
update(char *variable, LEXEME *values, LEXEME *env)
{
    while (env != NULL)
    {
        LEXEME *vars = car(env);
        LEXEME *vals = car(cdr(env));
        while (vars != NULL)
        {
            if (strcmp(variable, getStringToken(car(vars))) == 0)
            {
                setCar(vals, values);
                return;
            }
            vars = cdr(vars);
            vals = cdr(vals);
        }
        env = cdr(cdr(env));
    }
    fprintf(stdout,"FATAL variable SET: %s is undefined.\n", variable); 
    exit(1); 
}

LEXEME *
insert(LEXEME *variable, LEXEME *value, LEXEME *env)
{
    setCar(env, cons("JOIN", variable, car(env)));
    setCar(cdr(env), cons("JOIN", value, car(cdr(env))));
    return value;
}

LEXEME *
extend(LEXEME *variables, LEXEME *values, LEXEME *env)
{
    return cons("ENV", variables, cons("ENV", values, env));
}

void
displayEnvironment(LEXEME *env, bool lt)
{
    // Display only local table
    if (lt == true) 
    {
        fprintf(stdout, "The local environment is:\n");
        if (env != NULL)
        {
            LEXEME *vars = car(env);
            LEXEME *vals = car(cdr(env));
            while (vars != NULL)
            {
                if (getType(car(vars)) == NULL ||  getType(car(vals)) == NULL)
                {
                    display(vars);
                    display(vals);
                }
                else
                {
                    display(car(vars));
                    display(car(vals));
                }
                vars = cdr(vars);
                vals = cdr(vals);
            }
        }
    }

    // Display all tables
    else
    {
        fprintf(stdout, "The environment is:\n");
        while (env != NULL)
        {
            LEXEME *vars = car(env);
            LEXEME *vals = car(cdr(env));
            while (vars != NULL)
            {
                if (getType(car(vars)) == NULL ||  getType(car(vals)) == NULL)
                {
                    display(vars);
                    display(vals);
                }
                else
                {
                    display(car(vars));
                    display(car(vals));
                }
                vars = cdr(vars);
                vals = cdr(vals);
            }
            env = cdr(cdr(env));
        }
    }
}