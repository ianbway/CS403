; Ian Braudaway
; CS403 Assign 1, Task 2

(define (mandelbrot t)
	(define (resistance x y)
		(define (iter r s i)
			(cond 
				((> (+ (* r r) (* s s)) 4.0) i)
				((== t i) 0)
				(else (iter (+ (- (* r r) (* s s)) x) (+ (* 2.0 (* r s)) y) (+ i 1)))
				)
			)
		(iter 0.0 0.0 0)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define threshold (readExpr))
	(define x (readExpr))
	(define y (readExpr))
	(println "((mandelbrot " threshold ") " x " " y ") is " ((mandelbrot threshold) x y))
	)

;(inspect ((mandelbrot 8732) 0.78 -0.47))
;(inspect ((mandelbrot 100) 0.5 0.5))
;(inspect ((mandelbrot 6374) 0.89 0.33))
;(inspect ((mandelbrot 2685) -0.07 0.73))
;(inspect ((mandelbrot 8964) -0.01 1.14))
;(inspect ((mandelbrot 362) 1.05 0.54))
;(inspect ((mandelbrot 1657) 1.1 -0.06))
;(inspect ((mandelbrot 2908) 0.14 0.34))
;(inspect ((mandelbrot 4262) 1.21 0.75))
;(inspect ((mandelbrot 5543) 1.26 1.15))
;(inspect ((mandelbrot 1923) 1.32 -0.44))
