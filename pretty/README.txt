Ian Braudaway
PRETTY PRINTER README

TEST 1 README:


Original file:
# Ian Braudaway #

# This is the first test.#
# This is a line comment. It supports a single line, followed by a hash. #
# This function demonstrates math capability and prints to command line. #
func math[param1| param2]
    :
        var varSum = param1 + param2
        var varProduct = param1 * param2
        var varDifference = param1 - param2
        var varQuotient = param1 / param2

        print["This is test 1 for the pretty printer portion of CS403."]
        print[varSum]
        print[varProduct]
        print[varDifference]
        print[varQuotient]
    ;

#
This is a block comment.
Multiple lines are supported, followed by a double hash.
This function demonstrates list operations, loops, conditionals, and return statements.
#
func listOps[listParam]
    :
        var i = 0
        var j

        while [i < 10]
        :
            if [listsParam[i] == "top"]
            :
                i = i + 1
            ;

            else if [listParam[i] == "bottom"]
            :
                i = 10
            ;

            else
            :
                listParam[i] = listParam[i] - 1
            ;

            i = i + 1
        ;

        return listParam
    ;

# This function uses comparators #
func compare[]
    :
        if [4 > -3]
        :
            print["4 is greater than -3."]
        ;

        if [[4 + 6] < [5 + 6]]
        :
            print["4 + 6 is less than 5 + 6."]
        ;

        if [4 == 4]
        :
            print["4 is equal to 4."]
        ;

        if [4 <= 4]
        :
            print["4 is less than or equal to 4."]
        ;

        if [4.0 >= 4.0]
        :
            print["4.0 is greater than or equal to 4.0."]
        ;

        if [6 % 3 == 0]
        :
            print["6 cleanly divides by 3."]
        ;

        if [a != !a]
        :
            print["a is not equal to not a."]
        ;

        if [1 and 1 == 1]
        :
            print["true logical anded with true is true."]
        ;

        if [1 or 0 == 1]
        :
            print["true logical ored with false is true."]
        ;
    ;

# This function demonstrates nested function definitions. #
func nest[number]
    :
        func nestFunc[num]
        :
            var sumNums = number + num

            return sumNums
        ;

        return nestFunc
    ;

# This is the main function, with a call to it below. #
func main[]
    :
        math[4| 3]

        compare[]

        var emblem = @["top"| 4| 5| 6| "bottom"]

        var returnEmblem = listOps[emblem]

        print[returnEmblem]

        var nestReturn = nest[2]
        print[nestReturn]
    ;

main[]

Pretty Printed version of the original:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]



Pretty Printed version of the pretty printed version:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]

diff -s -q test1.pp.1 test1.pp.2
Files test1.pp.1 and test1.pp.2 are identical

TEST 2 README:


Original file:
# Ian Braudaway #

# This is the second test.#

func nestLoop[]
    :
        var loopConditionOne = 10
        var loopConditionTwo = 5

        print["This is test 2 for the pretty printer portion of CS403."]
        print["This test has a while loop nested inside of another while loop."]

        while [loopConditionOne > 0]
        :
            while [loopConditionTwo > 0]
            :
                loopConditionOne = loopConditionOne - 1
                loopConditionTwo = loopConditionTwo - 1
            ;
        ;

        print["End of function."]
    ;

# main[] does not have to be called "main" #
nestLoop[]

Pretty Printed version of the original:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]



Pretty Printed version of the pretty printed version:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]

diff -s -q test2.pp.1 test2.pp.2
Files test2.pp.1 and test2.pp.2 are identical

TEST 3 README:


Original file:
# Ian Braudaway #

# This is the third test.#

func processString[param]
    :
        print[param]

        var stringString = "This is a string variable"

        print["We are inside of the string processing function."]
    ;

func processInteger[param]
    :
        print[param]
        print[1234567890]

        var intInteger = 9867

        print["We are inside of the integer processing function."]
    ;

func processReal[param]
    :
        print[param]
        print[500.0000000000]
        print[234.4323]

        if [4 > 3]
        :
            print["4 is greater than 3."]
        ;

        var realNum = 76.89

        print["We are inside of the real processing function."]
    ;

func apiFunctionOne[param1| param2| param3]
    :
        print["This program is similar to an API."]
        print["This is test 3 for the pretty printer portion of CS403."]

        processString[param1]
        processInteger[param2]
        processReal[param3]
    ;

# main[] does not have to be called at all. #

Pretty Printed version of the original:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;



Pretty Printed version of the pretty printed version:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;

diff -s -q test3.pp.1 test3.pp.2
Files test3.pp.1 and test3.pp.2 are identical

MAKE RUN:

TEST 1:
Original file:
# Ian Braudaway #

# This is the first test.#
# This is a line comment. It supports a single line, followed by a hash. #
# This function demonstrates math capability and prints to command line. #
func math[param1| param2]
    :
        var varSum = param1 + param2
        var varProduct = param1 * param2
        var varDifference = param1 - param2
        var varQuotient = param1 / param2

        print["This is test 1 for the pretty printer portion of CS403."]
        print[varSum]
        print[varProduct]
        print[varDifference]
        print[varQuotient]
    ;

#
This is a block comment.
Multiple lines are supported, followed by a double hash.
This function demonstrates list operations, loops, conditionals, and return statements.
#
func listOps[listParam]
    :
        var i = 0
        var j

        while [i < 10]
        :
            if [listsParam[i] == "top"]
            :
                i = i + 1
            ;

            else if [listParam[i] == "bottom"]
            :
                i = 10
            ;

            else
            :
                listParam[i] = listParam[i] - 1
            ;

            i = i + 1
        ;

        return listParam
    ;

# This function uses comparators #
func compare[]
    :
        if [4 > -3]
        :
            print["4 is greater than -3."]
        ;

        if [[4 + 6] < [5 + 6]]
        :
            print["4 + 6 is less than 5 + 6."]
        ;

        if [4 == 4]
        :
            print["4 is equal to 4."]
        ;

        if [4 <= 4]
        :
            print["4 is less than or equal to 4."]
        ;

        if [4.0 >= 4.0]
        :
            print["4.0 is greater than or equal to 4.0."]
        ;

        if [6 % 3 == 0]
        :
            print["6 cleanly divides by 3."]
        ;

        if [a != !a]
        :
            print["a is not equal to not a."]
        ;

        if [1 and 1 == 1]
        :
            print["true logical anded with true is true."]
        ;

        if [1 or 0 == 1]
        :
            print["true logical ored with false is true."]
        ;
    ;

# This function demonstrates nested function definitions. #
func nest[number]
    :
        func nestFunc[num]
        :
            var sumNums = number + num

            return sumNums
        ;

        return nestFunc
    ;

# This is the main function, with a call to it below. #
func main[]
    :
        math[4| 3]

        compare[]

        var emblem = @["top"| 4| 5| 6| "bottom"]

        var returnEmblem = listOps[emblem]

        print[returnEmblem]

        var nestReturn = nest[2]
        print[nestReturn]
    ;

main[]

Pretty Printed version of the original:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]



Pretty Printed version of the pretty printed version:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]

diff -s -q test1.pp.1 test1.pp.2
Files test1.pp.1 and test1.pp.2 are identical

TEST 2:
Original file:
# Ian Braudaway #

# This is the second test.#

func nestLoop[]
    :
        var loopConditionOne = 10
        var loopConditionTwo = 5

        print["This is test 2 for the pretty printer portion of CS403."]
        print["This test has a while loop nested inside of another while loop."]

        while [loopConditionOne > 0]
        :
            while [loopConditionTwo > 0]
            :
                loopConditionOne = loopConditionOne - 1
                loopConditionTwo = loopConditionTwo - 1
            ;
        ;

        print["End of function."]
    ;

# main[] does not have to be called "main" #
nestLoop[]

Pretty Printed version of the original:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]



Pretty Printed version of the pretty printed version:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]

diff -s -q test2.pp.1 test2.pp.2
Files test2.pp.1 and test2.pp.2 are identical

TEST 3:
Original file:
# Ian Braudaway #

# This is the third test.#

func processString[param]
    :
        print[param]

        var stringString = "This is a string variable"

        print["We are inside of the string processing function."]
    ;

func processInteger[param]
    :
        print[param]
        print[1234567890]

        var intInteger = 9867

        print["We are inside of the integer processing function."]
    ;

func processReal[param]
    :
        print[param]
        print[500.0000000000]
        print[234.4323]

        if [4 > 3]
        :
            print["4 is greater than 3."]
        ;

        var realNum = 76.89

        print["We are inside of the real processing function."]
    ;

func apiFunctionOne[param1| param2| param3]
    :
        print["This program is similar to an API."]
        print["This is test 3 for the pretty printer portion of CS403."]

        processString[param1]
        processInteger[param2]
        processReal[param3]
    ;

# main[] does not have to be called at all. #

Pretty Printed version of the original:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;



Pretty Printed version of the pretty printed version:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;

diff -s -q test3.pp.1 test3.pp.2
Files test3.pp.1 and test3.pp.2 are identical

MAKE TEST

TEST 1:
Original file:
# Ian Braudaway #

# This is the first test.#
# This is a line comment. It supports a single line, followed by a hash. #
# This function demonstrates math capability and prints to command line. #
func math[param1| param2]
    :
        var varSum = param1 + param2
        var varProduct = param1 * param2
        var varDifference = param1 - param2
        var varQuotient = param1 / param2

        print["This is test 1 for the pretty printer portion of CS403."]
        print[varSum]
        print[varProduct]
        print[varDifference]
        print[varQuotient]
    ;

#
This is a block comment.
Multiple lines are supported, followed by a double hash.
This function demonstrates list operations, loops, conditionals, and return statements.
#
func listOps[listParam]
    :
        var i = 0
        var j

        while [i < 10]
        :
            if [listsParam[i] == "top"]
            :
                i = i + 1
            ;

            else if [listParam[i] == "bottom"]
            :
                i = 10
            ;

            else
            :
                listParam[i] = listParam[i] - 1
            ;

            i = i + 1
        ;

        return listParam
    ;

# This function uses comparators #
func compare[]
    :
        if [4 > -3]
        :
            print["4 is greater than -3."]
        ;

        if [[4 + 6] < [5 + 6]]
        :
            print["4 + 6 is less than 5 + 6."]
        ;

        if [4 == 4]
        :
            print["4 is equal to 4."]
        ;

        if [4 <= 4]
        :
            print["4 is less than or equal to 4."]
        ;

        if [4.0 >= 4.0]
        :
            print["4.0 is greater than or equal to 4.0."]
        ;

        if [6 % 3 == 0]
        :
            print["6 cleanly divides by 3."]
        ;

        if [a != !a]
        :
            print["a is not equal to not a."]
        ;

        if [1 and 1 == 1]
        :
            print["true logical anded with true is true."]
        ;

        if [1 or 0 == 1]
        :
            print["true logical ored with false is true."]
        ;
    ;

# This function demonstrates nested function definitions. #
func nest[number]
    :
        func nestFunc[num]
        :
            var sumNums = number + num

            return sumNums
        ;

        return nestFunc
    ;

# This is the main function, with a call to it below. #
func main[]
    :
        math[4| 3]

        compare[]

        var emblem = @["top"| 4| 5| 6| "bottom"]

        var returnEmblem = listOps[emblem]

        print[returnEmblem]

        var nestReturn = nest[2]
        print[nestReturn]
    ;

main[]

Pretty Printed version of the original:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]



Pretty Printed version of the pretty printed version:
func math[param1| param2]
        :
var varSum = param1 + param2
var varProduct = param1 * param2
var varDifference = param1 - param2
var varQuotient = param1 / param2
print["This is test 1 for the pretty printer portion of CS403."]
print[varSum]
print[varProduct]
print[varDifference]
print[varQuotient]
        ;
func listOps[listParam]
        :
var i = 0
var j
while [i < 10]
        :
if [listsParam[i]
 == "top"]
        :
i = i + 1       ;
else
if [listParam[i]
 == "bottom"]
        :
i = 10  ;
else
        :
listParam[i]
 = listParam[i]
 - 1    ;
i = i + 1       ;
return listParam
        ;
func compare[]
        :
if [4 > -3]
        :
print["4 is greater than -3."]
        ;
if [[4 + 6] < [5 + 6]]
        :
print["4 + 6 is less than 5 + 6."]
        ;
if [4 == 4]
        :
print["4 is equal to 4."]
        ;
if [4 <= 4]
        :
print["4 is less than or equal to 4."]
        ;
if [4.000000 >= 4.000000]
        :
print["4.0 is greater than or equal to 4.0."]
        ;
if [6 % 3 == 0]
        :
print["6 cleanly divides by 3."]
        ;
if [a != !a]
        :
print["a is not equal to not a."]
        ;
if [1 and 1 == 1]
        :
print["true logical anded with true is true."]
        ;
if [1 or 0 == 1]
        :
print["true logical ored with false is true."]
        ;
        ;
func nest[number]
        :
func nestFunc[num]
        :
var sumNums = number + num
return sumNums
        ;
return nestFunc
        ;
func main[]
        :
math[4| 3]
compare[]
var emblem = @["top"| 4| 5| 6| "bottom"]

var returnEmblem = listOps[emblem]

print[returnEmblem]
var nestReturn = nest[2]

print[nestReturn]
        ;
main[]

diff -s -q test1.pp.1 test1.pp.2
Files test1.pp.1 and test1.pp.2 are identical

TEST 2:
Original file:
# Ian Braudaway #

# This is the second test.#

func nestLoop[]
    :
        var loopConditionOne = 10
        var loopConditionTwo = 5

        print["This is test 2 for the pretty printer portion of CS403."]
        print["This test has a while loop nested inside of another while loop."]

        while [loopConditionOne > 0]
        :
            while [loopConditionTwo > 0]
            :
                loopConditionOne = loopConditionOne - 1
                loopConditionTwo = loopConditionTwo - 1
            ;
        ;

        print["End of function."]
    ;

# main[] does not have to be called "main" #
nestLoop[]

Pretty Printed version of the original:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]



Pretty Printed version of the pretty printed version:
func nestLoop[]
        :
var loopConditionOne = 10
var loopConditionTwo = 5
print["This is test 2 for the pretty printer portion of CS403."]
print["This test has a while loop nested inside of another while loop."]
while [loopConditionOne > 0]
        :
while [loopConditionTwo > 0]
        :
loopConditionOne = loopConditionOne - 1loopConditionTwo = loopConditionTwo - 1  ;
        ;
print["End of function."]
        ;
nestLoop[]

diff -s -q test2.pp.1 test2.pp.2
Files test2.pp.1 and test2.pp.2 are identical

TEST 3:
Original file:
# Ian Braudaway #

# This is the third test.#

func processString[param]
    :
        print[param]

        var stringString = "This is a string variable"

        print["We are inside of the string processing function."]
    ;

func processInteger[param]
    :
        print[param]
        print[1234567890]

        var intInteger = 9867

        print["We are inside of the integer processing function."]
    ;

func processReal[param]
    :
        print[param]
        print[500.0000000000]
        print[234.4323]

        if [4 > 3]
        :
            print["4 is greater than 3."]
        ;

        var realNum = 76.89

        print["We are inside of the real processing function."]
    ;

func apiFunctionOne[param1| param2| param3]
    :
        print["This program is similar to an API."]
        print["This is test 3 for the pretty printer portion of CS403."]

        processString[param1]
        processInteger[param2]
        processReal[param3]
    ;

# main[] does not have to be called at all. #

Pretty Printed version of the original:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;



Pretty Printed version of the pretty printed version:
func processString[param]
        :
print[param]
var stringString = "This is a string variable"
print["We are inside of the string processing function."]
        ;
func processInteger[param]
        :
print[param]
print[1234567890]
var intInteger = 9867
print["We are inside of the integer processing function."]
        ;
func processReal[param]
        :
print[param]
print[500.000000]
print[234.432300]
if [4 > 3]
        :
print["4 is greater than 3."]
        ;
var realNum = 76.890000
print["We are inside of the real processing function."]
        ;
func apiFunctionOne[param1| param2| param3]
        :
print["This program is similar to an API."]
print["This is test 3 for the pretty printer portion of CS403."]
processString[param1]
processInteger[param2]
processReal[param3]
        ;

diff -s -q test3.pp.1 test3.pp.2
Files test3.pp.1 and test3.pp.2 are identical