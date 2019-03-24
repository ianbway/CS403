; Ian Braudaway
; CS403 Assign 1, Task 9

(define (ramanujanr-helper depth counter)
	(cond
		((== depth counter) (* (+ depth 1.0) (sqrt (+ depth 6.0))))
		(else
			(* (+ counter 1.0) (sqrt (+ (+ counter 6.0) (ramanujanr-helper depth (+ counter 1.0))))))
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
