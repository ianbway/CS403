// Ian Braudaway
// Main method for environment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    LEXEME *v = newLexeme("v", NULL);
    LEXEME *one = newLexeme("1", NULL);
    LEXEME *w = newLexeme("w", NULL);
    LEXEME *two = newLexeme("2", NULL);
    LEXEME *x = newLexeme("x", NULL);
    LEXEME *three = newLexeme("3", NULL);
    insert(v, one, env);
    insert(w, two, env);
    insert(x, three, env);
    displayEnvironment(env, false);

    printf("\nExtending the environment with y:4 and z:\"hello\"\n");
    printf("Three of each variable will exist in each environment.\n");
    LEXEME *y = newLexeme("y", NULL);
    LEXEME *four = newLexeme("4", NULL);
    LEXEME *z = newLexeme("z", NULL);
    LEXEME *hello = newLexeme("hello", NULL);
    LEXEME *env2 = extend(y, four, env);
    insert(y, four, env2);
    insert(y, four, env2);
    LEXEME *env3 = extend(z, hello, env2);
    insert(z, hello, env3);
    insert(z, hello, env3);
    displayEnvironment(env3, true);
    displayEnvironment(env3, false);

    printf("\nLookup Test.\n");
    LEXEME *rZ = lookup(z, env3);
    printf("Type of looked up Z: %s\n", getType(rZ));

    printf("\nUpdate Test, hello will become goodbye.\n");
    LEXEME *goodbye = newLexeme("goodbye", NULL);
    update(z, goodbye, env3);
    displayEnvironment(env3, false);

    return 0;
}