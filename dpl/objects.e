# Ian Braudaway #
# make objects test #

func object[value| next]
:
	this
;

func getValue[obj]
:
	return obj.value
;

func setValue[obj| val]
:
	print["setter"]
	print[val]
	obj.value = val
;

func main[]
:
	var n = object[5| 78]

	# Get Value. Should be 5. #
	print[getValue[n]]

	# Set Value. Should be 963. #
	setValue[n| 963]

	# Get Value. Should be 963. #
	print[getValue[n]]
;

main[]