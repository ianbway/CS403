#IAN BRAUDAWAY#

#print["hello world"]#

#if [2 > 1]
:
	print["2 is greater than 1"]
;#

#while [1]
:
	print["one"]
;#

#print[1+2]#

func obj[value| next]
:
	this
;

func main[p]
:
	var n = obj[5| 0]
	print[n.value]
	print[n.next]
	var j = p
	print[j]
	n.next = j
;

main[5]

#var e = 12#