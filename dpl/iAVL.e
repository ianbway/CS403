# Ian Braudaway #
# iAVL and Interpreter #

func setBalance[x]
:
	x.leftHeight = 
	set x's leftHeight to the height of the left child,
        zero if there is no left child
    set x's rightHeight to the height of the right child,
        zero if there is no right child
    set x's height to the max of leftHeight and rightHeight, plus one
;

func displayTree[t]
:

;

func insertAvl[t| v]
:

;

func interpreter[file]
:
	var tree;

	var int = readInteger[file]
	while[!atFileEnd[file]]
	:
		if [int == 0]
		:
			displayTree[tree]
		;

		# int is 1 #
		else
		:
			int = readInteger[file]
			insertAvl[tree| int]
		;

		int = readInteger[file]
	;
;

func main[]
:
        var fp = openFileForReading[getArg[1]]
        interpreter[fp]
        closeFile[fp]
        return 0
;