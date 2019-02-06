#Ian Braudaway
#ENVIRONMENT

TREE WALKER HELPER:
static LEXEME *treeWalkerHelper(LEXEME *, LEXEME *);
The treeWalkerHelper is private to the environment module.
It does the work of walking through the environments and tables.


CONS:
extern LEXEME *cons(char *, LEXEME *, LEXEME *);
The cons function is public.
It constructs a new lexeme of the given type, assigns left and right pointers to new lexemes, and returns the new lexeme.


CAR:
extern LEXEME *car(LEXEME *);
The car function is public.
It returns the lexeme that is assigned to the left pointer of the given lexeme.


CDR:
extern LEXEME *cdr(LEXEME *);
The cdr function is public.
It returns the lexeme that is assigned to the right pointer of the given lexeme.


SET CAR:
extern void setCar(LEXEME *, LEXEME *);
The set car function is public.
It assigns the left pointer of the given lexeme in the first argument of the function call 
to the lexeme given in the second argument of the function call.


SET CDR:
extern void setCdr(LEXEME *, LEXEME *);
The set cdr function is public.
It assigns the right pointer of the given lexeme in the first argument of the function call 
to the lexeme given in the second argument of the function call.


CREATE:
extern LEXEME *create();
The create function is public.
It returns a newly constructed blank environment with a blank table, represented as a lexeme.


LOOKUP:
extern LEXEME *lookup(LEXEME *, LEXEME *);
The lookup function is public.
It searches through each table in each environment until it finds a lexeme of the same type
as the second argument of the function call.


UPDATE:
extern void update(LEXEME *, LEXEME *, LEXEME *);
The update function is public.
It searches through each table in each environment until it finds a lexeme of the same type
as the second argument of the function call. It then updates the value of that variable.


INSERT:
extern LEXEME *insert(LEXEME *, LEXEME *, LEXEME *);
The insert function is public.
It inserts a new variable and value lexeme into a given environment.


EXTEND:
extern LEXEME *extend(LEXEME *, LEXEME *, LEXEME *);
The extend function is public.
It extends the environment with a new initial variable and value lexeme for a new table.
This becomes the new local environment.


DISPLAY ENVIRONMENT:
extern void displayEnvironment(LEXEME *, bool lt);
The display environment function is public.
It displays each variable and value in each environment if the provided boolean is false.
If the provided boolean is true it only displays the local environment.

