// Ian Braudaway
// Header file for scanner class

#ifndef __SCANNER_INCLUDED__
#define __SCANNER_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

typedef struct scanner SCANNER;

extern SCANNER *newScanner(FILE *);
extern void scanner(SCANNER *);

#endif