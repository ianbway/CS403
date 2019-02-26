# Ian Braudaway #
# make problem, non-AVL #

func interpreter[file]
:
	var int = readInteger[file]
	var sum = 0

	while[!atFileEnd[file]]
	:
		sum = sum + int
		int = readInteger[file]
	;

	print[sum]
;

func main[]
:
        var fp = openFileForReading[getArg[1]]
        interpreter[fp]
        closeFile[fp]
        return 0
;