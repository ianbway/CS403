; Ian Braudaway
; CS403 Assign 2, Task 1

(define (for-loop arg))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (for-loop arg))
	)
