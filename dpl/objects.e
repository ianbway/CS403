# Ian Braudaway #
# make objects test #

func object[value| next]
:
	this
;

func main[]
:
	var n = object[5| 78]

	# Get Value. Should be 5. #
	print["'value' field is:"]
	print[n.value]
	print[""]

	# Set Value. Should be 963. #
	n.value = 963

	# Get Value. Should be 963. #
	print["'value' field is:"]
	print[n.value]
;

main[]