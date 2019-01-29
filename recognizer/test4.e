# Ian Braudaway #

# This is the fourth test.#

func conditionTester[]
    [[
        print["This is test 4 for the lexer portion of CS403."] 
        print["This test will use conditions."] 

        if [1.0 > 0.5]
        [[
            var oneIsGreater = "1 is indeed larger than 0.5"
            print[var]
        ]]

        else if ["same" == "same"]
        [[
            print["The string same is equal to same."]
        ]]

        else
        [[
            print["Else condition."]
        ]]
    ]]

func listDeclare[]
    [[
        print["We will declare a list."] 

        var exampleList = @[1.0| 1.5| 2.0| 456.9| 7000000000.888]
    ]]