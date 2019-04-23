; Ian Braudaway
; CS403 Assign 3, Task 7

(include "streams.scm")

(sdisplay 12 integers)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
