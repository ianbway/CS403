; Ian Braudaway
; CS403 Assign 1, Task 3

(define (compare next guess)
	(cond
		((< next guess) (- 1 (/ next guess)))
		((> next guess) (- 1 (/ guess next)))
		;else its equal
		(else 0.0)
		)
	)

(define (root-n nthRoot)
	(define (root rootOf)
		(define (good-enough? next guess)
			(< (compare next guess) 0.0000000000000000000000000000000000000000001))
		(define (improve guess)
			(/ (+ (* (- nthRoot 1.0) guess) (/ rootOf (expt guess (- nthRoot 1.0)))) nthRoot))
		(define (root-iter guess)
			(if (good-enough? (improve guess) guess)
				guess
				(root-iter (improve guess))))
		(root-iter 1.0))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define nthRoot (readExpr))
	(define rootOf (readExpr))
	(println "((root-n " nthRoot ") " rootOf ") is " (fmt "%.15f" ((root-n nthRoot) rootOf)))
	)


;(inspect (fmt "%.15f" ((root-n 2) 144)))
;(inspect (fmt "%.15f" ((root-n 12) 2)))
;(inspect (fmt "%.15f" ((root-n 3) 6.950000e-29)))
;(inspect (fmt "%.15f" ((root-n 2) 2.210000e-29)))
;(inspect (fmt "%.15f" ((root-n 3) 2.510000e-29)))
;(inspect (fmt "%.15f" ((root-n 2) 776)))
;(inspect (fmt "%.15f" ((root-n 4) 803)))
;(inspect (fmt "%.15f" ((root-n 7) 324)))
;(inspect (fmt "%.15f" ((root-n 9) 858)))
;(inspect (fmt "%.15f" ((root-n 11) 883)))
;(inspect (fmt "%.15f" ((root-n 5) 911)))
