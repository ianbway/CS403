; Ian Braudaway
; CS403 Assign 1, Task 2

(define (rCalc r s x)

	(+ (- (* r r) (* s s)) x)

	)

(define (sCalc r s y)

	(+ (* 2 (* r s)) y)
	
	)

(define (threshold x y)

	(cond (> (+ (* r r) (* s s)) 4) )

	)

(define (mandelbrot value)
	(cond (> (threshold x y) value) 0 )
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define argOne (readExpr))
	(define argTwo (readExpr))
	(define argThree (readExpr))
	(println ((mandelbrot argOne) argTwo argThree))
	)