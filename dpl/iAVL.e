# Ian Braudaway #
# iAVL and Interpreter #

function main[]
:
        var fp = openFileForReading[getArg[1]]
        interpreter[fp]
        closeFile[fp]
        return 0
;