; Ian Braudaway
; CS403 Assign 1, Task 9

(define (ramanujani-helper depth acc)
	(cond
		((== depth 0.0) (* 1 (sqrt (+ 6.0 acc))))
		(else
			(ramanujani-helper (- depth 1.0) (* (+ depth 1.0) (sqrt (+ (+ depth 6.0) acc)))))
		)
	)

(define (ramanujani depth)
	(ramanujani-helper (real depth) 0.0)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define depth (readExpr))
	(println "(ramanujani " depth ") is " (fmt "%.25f" (ramanujani depth)))
	(println "$" (integer (ramanujani depth)) "$")
	)
