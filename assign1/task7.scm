; Ian Braudaway
; CS403 Assign 1, Task 7

(define (div2 value)
	(cond
		((== (cdr value) 0) #t)
		((== (cdr value) 2) #t)
		((== (cdr value) 4) #t)
		((== (cdr value) 6) #t)
		((== (cdr value) 8) #t)
		(else #f)
		)
	)

(define (double value)
	(+ value value)
	)

(define (halve value)

	)

(define (ethiop a b)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define a (readExpr))
	(define b (readExpr))
	(inspect (div2 a))
	(inspect (double a))
	(inspect (halve a))
	(inspect (ethiop a b))
	;(println (ethiop a b))
	)
