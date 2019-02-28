; Ian Braudaway
; CS403 Assign 1, Task 5

(define (curry left right)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (curry arg))
	)