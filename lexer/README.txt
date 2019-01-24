Emblem Programming Language

Written by Ian Braudaway

Emblem is a functional programming language. A program will contain definitions of variables and functions, and will end with a statement. 
That statement will be the "main" call to the program. This is optional, as potentially the file will just be function definitions.
The file extension for an Emblem program is ".e".

FUNCTIONS
The keyword to functions is "func". This should be followed by a function name, an open bracket, parameters delimited by bars, and a close bracket.
The body of a function is a block.

VARIABLES
The keyword to variables is "var". This should be followed by a variable name, an equal sign, and an expression.

BLOCKS
A block is wrapped in double open bracket, double close bracket [[]]. 

COMMENTS
In Emblem comments are started and ended with the hash symbol (#).

LOOPS
The keyword to use a loop is "while". This should be followed by an open bracket, an expression, a close bracket, and a block.

CONDITIONS
The keywords for conditions are "if", "else if", and "else". The "if" and "else if" are followed by an expression and a block.

LISTS
Lists start with an "at" symbol (@) followed by an open bracket, values delimted by bars (|) and a close bracket. This should be assigned.

RETURNING
The keyword to return is "return". Follow this by a variable or a type. 

PRINTING
The keyword to print is "print". This should be followed by an open bracket, a list of arguments, and a close bracket.

Example: 
# Example comment #

func math[param1| param2]
    [[
        var varSum = param1 + param2 
        var varProduct = param1 * param2 
        var varDifference = param1 - param2 
        var varQuotient = param1 / param2 

        print[varSum] 
        print[varProduct] 
        print[varDifference] 
        print[varQuotient] 
    ]]

func listOps[listParam]
    [[
        var i = 0 
        var j

        while [i < 10]
        [[
            if [listsParam[i] == "top"]
            [[
                i = i + 1 
            ]]

            else if [listParam[i] == "bottom"]
            [[
                i = 10 
            ]]

            else
            [[
                listParam[i] = listParam[i] - 1 
            ]]

            i++ 
        ]]

        return listParam 
    ]]

func compare[]
    [[
        if [4 > -3]
        [[
            print["4 is greater than -3."]
        ]]

        if [[4 + 6] < [5 + 6]]
        [[
            print["4 + 6 is less than 5 + 6."]
        ]]

        if [4 == 4]
        [[
            print["4 is equal to 4."]
        ]]

        if [4 <= 4]
        [[
            print["4 is less than or equal to 4."]
        ]]

        if [4.0 >= 4.0]
        [[
            print["4.0 is greater than or equal to 4.0."]
        ]]

        if [6 % 3 == 0]
        [[
            print["6 cleanly divides by 3."]
        ]]

        if [a != !a]
        [[
            print["a is not equal to not a."]
        ]]

        if [1 and 1 == 1]
        [[
            print["true logical anded with true is true."]
        ]]

        if [1 or 0 == 1]
        [[
            print["true logical ored with false is true."]
        ]]
    ]]

func nest[number]
    [[
        func nestFunc[num]
        [[
            var sumNums = number + num

            return sumNums
        ]]

        return nestFunc
    ]]

func main[]
    [[
        math[4| 3] 

        compare[]

        var emblem = @["top"| 4| 5| 6| "bottom"] 

        var returnEmblem = listOps[emblem] 

        print[returnEmblem] 

        var nestReturn = nest[2]
        print[nestReturn]
    ]]

main[]