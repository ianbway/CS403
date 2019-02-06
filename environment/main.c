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

    printf("\nAdding variable v, w, and x with values 1, 2, 3.\n");
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

    printf("\nExtending the environment with y:4\n");
    LEXEME *y = newLexeme(VARIABLE, "y");
    LEXEME *four = newLexeme(INTEGER, "4");
    LEXEME *env2 = extend(y, four, env);
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

    printf("\nExtending the environment with z:\"hello\"\n");
    LEXEME *z = newLexeme(VARIABLE, "z");
    LEXEME *hello = newLexeme(STRING, "hello");
    LEXEME *env3 = extend(z, hello, env2);
    printf("Inserting c:7\n");
    LEXEME *c = newLexeme(VARIABLE, "c");
    LEXEME *seven = newLexeme(REAL, "7.0");
    insert(c, seven, env3);
    printf("Inserting d:8\n");
    LEXEME *d = newLexeme(VARIABLE, "d");
    LEXEME *eight = newLexeme(INTEGER, "8");
    insert(d, eight, env3);
    displayEnvironment(env3, true);
    displayEnvironment(env3, false);

    printf("\nLookup Test.\n");
    LEXEME *rZ = lookup("z", env3);
    printf("Type of looked up Z: %s\n", getStringToken(rZ));

    printf("\nUpdate Test, hello will become goodbye.\n");
    LEXEME *goodbye = newLexeme(STRING, "goodbye");
    update("z", goodbye, env3);
    displayEnvironment(env3, false);

    return 0;
}