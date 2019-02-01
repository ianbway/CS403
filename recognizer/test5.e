# Ian Braudaway #

# This is the fifth test. It will have a symbol that gives the lexer an error # 

func problemTest[] 
    :
        print["This is test 5 for the recognizer portion of CS403."] 
        print["This test will be bad because we have two greater than signs."] 
        print["The recognizer should think that we missed nesting an expression."] 
        print["Here we go:"] 
        while [1 >> 5]
        :
            print["Should not make it this far."] 
        ;
        print["Should not make it this far."] 
    ;