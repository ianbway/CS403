; Ian Braudaway
; CS403 Assign 1, Task 6

(define (w left right)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (w arg))
	)