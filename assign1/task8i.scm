; Ian Braudaway
; CS403 Assign 1, Task 8 Iterative

(define (ecfi index)
	(cond
		((== index 0) 2.0)
		)
	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define index (readExpr))
	(println "(ecfi " index ") is " (fmt "%.25f" (ecfi index)))
	)
