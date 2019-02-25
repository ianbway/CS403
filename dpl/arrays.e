# Ian Braudaway #
# make array test #

func arrayTest[]
:
	var exampleArray = @[1| 2| 3| 4| 5]
	var one = getArray[exampleArray| 0]
	setArray[exampleArray| 0| 11]
;

arrayTest[]