; Ian Braudaway
; CS403 Assign 2, Task 1

(define (range start end step)
	(cond
		((== start end) nil)
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
