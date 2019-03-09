# Ian Braudaway #
# make error 4 #

func badAssign[]
    :
        # Semantic Error. Attempting to assign literal to literal rather than variable. #    
        1 = 1
        print[1]
    ;

badAssign[]