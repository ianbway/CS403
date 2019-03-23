; Ian Braudaway
; CS403 Assign 1, Task 7

(define (double value)
	(+ value value)
	)

(define (div2Helper value counter)
		(cond
			((== value 1) #f)
			((== value 0) #t)
			((> (double counter) value)
				(div2Helper (- value counter) 1))
			(else 
				(div2Helper value (double counter)))
			)
		)

(define (div2? value)
	(div2Helper value 1)
	)

;{
(define (halve-iter value countup)
	(cond
		((> (double countup) value) (- value countup))
		(else (halve-iter value (double countup)))
		)
	)
;}

(define (halve value)
	;{
	(cond
		((== (halve-iter value 1) ))
		((== (halve-iter value 1) ))
		(else ())
		)
	;}
	(/ value 2)
	)

(define (ethiop-iter a b c)
	(cond 
		((== a 0) c)
        ((div2? a) (ethiop-iter (halve a) (double b) c))
        (else (ethiop-iter (halve a) (double b) (+ c b)))
        )
	)

(define (ethiop a b)
	(ethiop-iter a b 0)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define a (readExpr))
	(define b (readExpr))
	(println "(halve " a ") is " (halve a))
	(println "(double " a ") is " (double a))
	(println "(div2? " a ") is " (div2? a))
	(println "(ethiop " a b ") is " (ethiop a b))
	)
