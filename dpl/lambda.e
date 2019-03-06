# Ian Braudaway #
# make lambda test #

func main[p]
:
	lambda [x]
	:
		var y = x + 10
		print["inside lambda"]
	;

;

# Should be 11 #
main[1]