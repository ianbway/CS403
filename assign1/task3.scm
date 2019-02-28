; Ian Braudaway
; CS403 Assign 1, Task 3

(define (root-n value)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (root-n arg))
	)