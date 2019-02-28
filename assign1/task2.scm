; Ian Braudaway
; CS403 Assign 1, Task 2

(define (mandelbrot value)

	
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (mandelbrot arg))
	)