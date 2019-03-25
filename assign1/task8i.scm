; Ian Braudaway
; CS403 Assign 1, Task 8 Iterative

(define (term index result)
	(cond
		((== index 0.0) (+ 2.0 result))
		(else
			(term (- index 1.0) (/ 1.0 (+ 1.0 (/ 1.0 (+ (* index 2.0) (/ 1.0 (+ 1.0 result))))))))
		)
	)

(define (ecfi index)
	(cond
		((== (real index) 0.0) 2.0)
		(else
			(term (real index) 0.0))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define index (readExpr))
	(println "(ecfi " index ") is " (fmt "%.25f" (ecfi index)))
	)

;(inspect (fmt "%.25f" (ecfi 2)))
;(inspect (fmt "%.25f" (ecfi 3)))
;(inspect (fmt "%.25f" (ecfi 4)))
;(inspect (fmt "%.25f" (ecfi 5)))
;(inspect (fmt "%.25f" (ecfi 43)))
;(inspect (fmt "%.25f" (ecfi 50)))
