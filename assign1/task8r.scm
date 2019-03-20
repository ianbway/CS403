; Ian Braudaway
; CS403 Assign 1, Task 8 Recursive

(define (ecfr index)
	(cond
		((== index 0) 2.0)
		)
	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define index (readExpr))
	(println "(ecfr " index ") is " (fmt "%.25f" (ecfr index)))
	)
