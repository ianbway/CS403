; Ian Braudaway
; CS403 Assign 1, Task 4

(define (crazyTriangle left right)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (crazyTriangle arg))
	)