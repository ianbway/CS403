#Ian Braudaway

test1 : The output of this program should be:

TEST 1:
./recognizer ./test1.e
 legal

test2 : The output of this program should be:

TEST 2:
./recognizer ./test2.e
 legal

test3 : The output of this program should be:

TEST 3:
./recognizer ./test3.e
 illegal
 current lexeme: CLOSE_BLOCK
 recognize error: CLOSE_BRACKET
 line number: 31

The reasoning for the syntax error in TEST 3 is that the expression following the
"if" statement is ended with a CLOSE_BLOCK symbol ( ; ) rather than a CLOSE_BRACKET
symbol ( ] ).

test4 : The output of this program should be:

TEST 4:
./recognizer ./test4.e
 illegal
 current lexeme: OPEN_BLOCK
 recognize error: END_OF_INPUT
 line number: 35

The reasoning for the syntax error in TEST 4 is that the last function declared in
the program is missing the FUNCTION keyword ( func ). Because of this error, the recognizer thinks that 
"badFunction[]" is a function call that is ending the program, rather than a function definition that has content.
This is why the current lexeme says that there is an OPEN_BLOCK ( : ) rather than END_OF_INPUT.

test5 : The output of this program should be:

TEST 5:
./recognizer ./test5.e
 illegal
 current lexeme: GREATER_THAN
 recognize error: OPEN_BRACKET
 line number: 11

The reasoning for the syntax error in TEST 5 is that we have two GREATER_THAN symbols ( >> )
rather than one in the WHILE condition. The recognizer expected a nested condition beginning
with an OPEN_BRACKET ( [ ) but instead received a duplicate symbol that it does not know what
to do with.