# Ian Braudaway #

# This is the third test.# 

func processString[param]
    [[
        print[param]

        var stringString = "This is a string variable"

        print["We are inside of the string processing function."]
    ]]

func processInteger[param]
    [[
        print[param]
        print[1234567890]

        var intInteger = 9867

        print["We are inside of the integer processing function."]
    ]]

func processReal[param]
    [[
        print[param]
        print[500.0000000000]
        print[234.4323]

        var realNum = 76.89

        print["We are inside of the real processing function."]
    ]]

func apiFunctionOne[param1| param2| param3]
    [[
        print["This program is similar to an API."]
        print["This is test 3 for the lexer portion of CS403."] 

        processString[param1]
        processInteger[param2]
        processReal[param3]
    ]]

# main[] does not have to be called at all. #