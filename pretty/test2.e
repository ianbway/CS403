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