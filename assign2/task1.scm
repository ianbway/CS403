; Ian Braudaway
; CS403 Assign 2, Task 1

(define (range start end step)
	(cond
		((>= start end) nil)
		(else
			(cons start (range (+ start step) end step)))
		)
	)

(define (for-loop listOfNumbers procedure)
	(cond
		((== listOfNumbers nil) nil)
		(else
			(procedure (car listOfNumbers))
			(for-loop (cdr listOfNumbers) procedure))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

;(for-loop (range 0 9 5) (lambda (x) (inspect x)))
;(println (range 1 11 3))
;(for-loop (range 74 139 16) (lambda (z) (inspect (+ -9 z))))
;(for-loop (range 32 110 17) (lambda (z) (inspect (* 5 z))))
;(for-loop (range 41 132 17) (lambda (z) (inspect (+ 9 z))))
;(for-loop (range 99 103 18) (lambda (z) (inspect (* -7 z))))
;(for-loop (range 8 25 11) (lambda (z) (inspect (* 7 z))))
;(for-loop (range 17 48 18) (lambda (z) (inspect (+ 1 z))))
;(for-loop (range 25 68 19) (lambda (z) (inspect (* 5 z))))
;(for-loop (range 83 89 12) (lambda (z) (inspect (* 9 z))))
