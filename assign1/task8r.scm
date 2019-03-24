; Ian Braudaway
; CS403 Assign 1, Task 8 Recursive

(define (term index counter)
	(cond
		((== counter index) (/ 1.0 (+ 1.0 (/ 1.0 (+ (* index 2.0) 1.0)))))
		(else
			(/ 1.0 (+ 1.0 (/ 1.0 (+ (* counter 2.0) (/ 1.0 (+ 1.0 (term index (+ counter 1.0)))))))))
		)
	)

(define (ecfr index)
	(cond
		((== (real index) 0.0) 2.0)
		(else
			(+ 2.0 (term (real index) 1.0)))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define index (readExpr))
	(println "(ecfr " index ") is " (fmt "%.25f" (ecfr index)))
	)
