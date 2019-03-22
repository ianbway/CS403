; Ian Braudaway
; CS403 Assign 1, Task 7

(define (div2 value)
	(cond
		((== (and value 1) 0) #t)
		(else #f)
		)
	)

(define (double value)
	(+ value value)
	)

(define (halve-iter value countup)
	(cond
		((> countup value) )
		((- value countup))
		)


	)

(define (halve value)
	(cond
		((== ))
		)
	)

(define (removeEvens array)



	)

(define (ethiop-iter a b)
	(cond
		((== b 1) (removeEvens b))

		)


	)

(define (ethiop a b)
	(ethiop-iter a b)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define a (readExpr))
	(define b (readExpr))
	;(inspect (div2 a))
	(inspect (double a))
	(inspect (halve a))
	(inspect (ethiop a b))
	;(println (ethiop a b))
	)
