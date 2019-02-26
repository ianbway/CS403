# Ian Braudaway #
# make error 4 #

func conditionTester[]
    :
        print["This test will use conditions."] 

        if [1.0 > 0.5]
        :
            var oneIsGreater = "1 is indeed larger than 0.5"
            print[oneIsGreater]
        ;

        else if ["same" == "same"]
        :
            print["The string same is equal to same."]
        ;

        else
        :
            print["Else condition."]
        ;
    ;

func listDeclare[]
    :
        print["We will declare a list."] 

        var exampleList = @[1.0| 1.5| 2.0| 456.9| 7000000000.888]
    ;

# Semantic error #
badFunction[]
    :
        print["This function does not begin with the func keyword."]
        print["It is being misinterpreted as a statement and breaking the program."]
    ;