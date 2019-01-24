# Ian Braudaway #

# This is the first test.# 
# This is a line comment. It supports a single line, followed by a hash. # 
# This function demonstrates math capability and prints to command line. #
func math[param1| param2]
    [[
        var varSum = param1 + param2 
        var varProduct = param1 * param2 
        var varDifference = param1 - param2 
        var varQuotient = param1 / param2 

        print["This is test 1 for the lexer portion of CS403."] 
        print[varSum] 
        print[varProduct] 
        print[varDifference] 
        print[varQuotient] 
    ]]

#
This is a block comment.
Multiple lines are supported, followed by a double hash.
This function demonstrates list operations, loops, conditionals, and return statements.
#
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

# This function uses comparators #
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

# This function demonstrates nested function definitions. #
func nest[number]
    [[
        func nestFunc[num]
        [[
            var sumNums = number + num

            return sumNums
        ]]

        return nestFunc
    ]]

# This is the main function, with a call to it below. #
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