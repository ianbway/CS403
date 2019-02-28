; Ian Braudaway
; CS403 Assign 1, Task 7

(define (ethiop value)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (ethiop arg))
	)