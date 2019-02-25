# Ian Braudaway #
# make functions test #

func paramFunction[]
:
	var a = 1
	return a
;

func mainFunction[pFunction]
:
	func subFunction[]
	:
		return 1
	;

	return subFunction[] + pFunction
;

# 1 + 1 = 2 #
mainFunction[paramFunction]