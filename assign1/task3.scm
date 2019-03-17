; Ian Braudaway
; CS403 Assign 1, Task 3

(define (square x)
	(* x x)
	)

(define (good-enough? guess x)
	(< (abs (- (square guess) x)) 0.0000000000000001)
	)

(define (average x y nthRoot) 
	(/ (+ x y) nthRoot)
	)

(define (improve guess x nthRoot)
	(average guess (/ x (^ guess (- nthRoot 1))) nthRoot)
	)

(define (root-iter guess x nthRoot)
	(if (good-enough? guess x)
		guess
		(root-iter (improve guess x nthRoot)
			x))
	)

(define (root-n nthRoot)
	(define (root-iter 1.0 rootOf nthRoot)
		(if (good-enough? guess x)
		guess
		(root-iter (improve guess x nthRoot)
			x))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define argOne (readExpr))
	(define argTwo (readExpr))
	(println "((root-n " argOne ")" argTwo ") is " (fmt "%.15f" ((root-n argOne) argTwo)))
	)