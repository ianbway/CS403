; Ian Braudaway
; CS403 Assign 1, Task 2

(define (iter r s x y i)
		(cond 
			((> (+ (* r r) (* s s)) 4.0) i)
			((== 100.0 i) 0)
		(else (iter (+ (- (* r r) (* s s)) x) (+ (* 2.0 (* r s)) y) x y (+ i 1)))
		)
	)

(define (mandelbrot t)
	(define (resistance x y)
		(iter 0.0 0.0 x y 0)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define threshold (readExpr))
	(define x (readExpr))
	(define y (readExpr))
	(println "((mandelbrot " threshold ") " x " " y ") is " ((mandelbrot threshold) x y))
	)