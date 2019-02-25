# Ian Braudaway #
# make lambda test #

func main[p]
:
	lambda [p]
	:
		p = p + 10
	;
	print[p]
;

# Should be 11 #
main[1]