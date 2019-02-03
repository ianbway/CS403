// Ian Braudaway
// Main method for environment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "lexer.h"
#include "lexeme.h"
#include "types.h"
#include "recognizer.h"
#include "environment.h"

int 
main() 
{
    printf("Creating a new environment\n");
    LEXEME *env = create();
    displayEnvironment(env, false);

    printf("Adding variable x with value 3\n");
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

    printf("Extending the environment with y:4 and z:\"hello\"\n");
    LEXEME *y = newLexeme("y", NULL);
    LEXEME *four = newLexeme("4", NULL);
    LEXEME *z = newLexeme("z", NULL);
    LEXEME *hello = newLexeme("hello", NULL);
    LEXEME *env2 = extend(y, four, env);
    insert(y, four, env2);
    insert(y, four, env2);
    displayEnvironment(env2, true);
    displayEnvironment(env2, false);
    LEXEME *env3 = extend(z, hello, env2);
    insert(z, hello, env3);
    insert(z, hello, env3);
    displayEnvironment(env3, true);
    displayEnvironment(env3, false);

    return 0;
}