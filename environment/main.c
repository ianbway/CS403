// Ian Braudaway
// Main method for environment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "lexeme.h"
#include "types.h"
#include "environment.h"

int 
main() 
{
    printf("\nCreating a new, empty environment.\n");
    LEXEME *env = create();
    displayEnvironment(env, false);

    printf("Adding variable v, w, and x with values 1, 2, 3.\n");
    LEXEME *v = newLexeme(VARIABLE, "v");
    LEXEME *one = newLexeme(INTEGER, "1");
    LEXEME *w = newLexeme(VARIABLE, "w");
    LEXEME *two = newLexeme(INTEGER, "2");
    LEXEME *x = newLexeme(VARIABLE, "x");
    LEXEME *three = newLexeme(INTEGER, "3");
    insert(v, one, env);
    insert(w, two, env);
    insert(x, three, env);
    displayEnvironment(env, true);
    displayEnvironment(env, false);

    printf("Extending the environment with y:4\n");
    LEXEME *y = newLexeme(VARIABLE, "y");
    LEXEME *four = newLexeme(INTEGER, "4");
    LEXEME *vars = cons("IDLIST", y, NULL);
    LEXEME *vals = cons("VALLIST", four, NULL);
    LEXEME *env2 = extend(vars, vals, env);
    printf("Inserting a:5\n");
    LEXEME *a = newLexeme(VARIABLE, "a");
    LEXEME *five = newLexeme(INTEGER, "5");
    insert(a, five, env2);
    printf("Inserting b:6\n");
    LEXEME *b = newLexeme(VARIABLE, "b");
    LEXEME *six = newLexeme(INTEGER, "6");
    insert(b, six, env2);
    displayEnvironment(env2, true);
    displayEnvironment(env2, false);

    printf("Extending the environment with NULL variables and NULL values.\n");
    LEXEME *env3 = extend(NULL, NULL, env2);
    printf("Inserting z:\"hello\"\n");
    LEXEME *z = newLexeme(VARIABLE, "z");
    LEXEME *hello = newLexeme(STRING, "hello");
    insert(z, hello, env3);
    printf("Inserting c:7.1\n");
    LEXEME *c = newLexeme(VARIABLE, "c");
    LEXEME *seven = newLexeme(REAL, "7.1");
    insert(c, seven, env3);
    printf("Inserting d:8\n");
    LEXEME *d = newLexeme(VARIABLE, "d");
    LEXEME *eight = newLexeme(INTEGER, "8");
    insert(d, eight, env3);
    displayEnvironment(env3, true);
    displayEnvironment(env3, false);

    printf("Lookup Test. (We are looking up the z variable.)\n");
    LEXEME *rZ = lookup(z, env3);
    fprintf(stdout, "Looked up var: %s\n\n", getStringToken(rZ));

    printf("Update Test, hello will become goodbye. (This is the value of the z variable.)\n");
    LEXEME *goodbye = newLexeme(STRING, "goodbye");
    update(z, goodbye, env3);
    displayEnvironment(env3, true);
    displayEnvironment(env3, false);

    return 0;
}