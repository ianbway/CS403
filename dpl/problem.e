# Ian Braudaway #
# make problem, non-AVL #
# summing integers found in file #

func summation[file]
:
	var int = readInteger[file]
	var sum = 0

	while[atFileEnd[file] != 1]
	:
		sum = sum + int
		int = readInteger[file]
	;

	sum = sum + int
	print["Sum is: "]
	print[sum]
;

func main[]
:
    var fp = openFileForReading[getArg[2]]
    summation[fp]
    closeFile[fp]
    return 0
;

main[]
