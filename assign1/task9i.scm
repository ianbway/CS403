; Ian Braudaway
; CS403 Assign 1, Task 9

(define (ramanujani-helper depth acc)
	(cond
		((== depth 0.0) (* 1.0 (sqrt (+ 6.0 acc))))
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
	(println "$" 4 "$")
	)

;(inspect (fmt "%.25f" (ramanujani 2)))
;(inspect (fmt "%.25f" (ramanujani 3)))
;(inspect (fmt "%.25f" (ramanujani 4)))
;(inspect (fmt "%.25f" (ramanujani 5)))
;(inspect (fmt "%.25f" (ramanujani 25)))
;(inspect (fmt "%.25f" (ramanujani 29)))
;(inspect (fmt "%.25f" (ramanujani 9)))
;(inspect (fmt "%.25f" (ramanujani 37)))
;(inspect (fmt "%.25f" (ramanujani 17)))
;(inspect (fmt "%.25f" (ramanujani 21)))
;(inspect (fmt "%.25f" (ramanujani 50)))
