# Ian Braudaway #
# make error 5 #

func errorFunction[]
:
	val1 = 1
	val2 = "hello"

	# This is a semantic error. #
	# While legal to multiply two variables, one has a string value and the other an integer value. #
	val3 = val1 * val2
	print[val3]
;