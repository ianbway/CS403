; Ian Braudaway
; CS403 Assign 1, Task 3

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	;(define arg (readExpr))
	(inspect (root-n readInt readInt))
)

(define (square x)
	(* x x)
)

(define (close-enough? guess x)
	(< (abs (- (square guess) x)) 0.0000000000000001)
)

(define (root-n nRoot rootOf)

	(cond (== )


	(cond 
		((close-enough? ) 
			)
		(else
			(root-n ))

	)
)
