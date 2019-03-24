; Ian Braudaway
; CS403 Assign 1, Task 9

(define (ramanujanr-helper depth acc)
	(cond
		((== depth 0.0) (* 1 (sqrt (+ 6.0 acc))))
		(else
			(ramanujanr-helper (- depth 1.0) (* (+ depth 1.0) (sqrt (+ (+ depth 6.0) acc)))))
		)
	)

(define (ramanujanr depth)
	(ramanujanr-helper (real depth) 0.0)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define depth (readExpr))
	(println "(ramanujanr " depth ") is " (fmt "%.25f" (ramanujanr depth)))
	(println "$" (integer (ramanujanr depth)) "$")
	)
