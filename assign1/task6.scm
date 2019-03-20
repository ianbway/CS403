; Ian Braudaway
; CS403 Assign 1, Task 6

(define (S f n)
	(cond
		((<= n 0) (f n))
		(else 
			(+ (f n) (S f (- n 1))))
		)
	)

(define (w function iterator)
	(cond
		((== iterator 0) (function iterator))
		(else 
			(/ (- (* (S f (- iterator 1)) (S f (+ iterator 1))) (^ (S f iterator) 2)) 
				(+ (- (S f (+ iterator 1)) (* 2 (S f iterator))) (S f (- iterator 1)))
				)
			)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define function (eval (readExpr) this))
	(define iterator (readExpr))
	(println "(S " function " " iterator ") is " (fmt "%.15f" (S function iterator)))
	(println "(w " function " " iterator ") is " (fmt "%.15f" (w function iterator)))
	)
