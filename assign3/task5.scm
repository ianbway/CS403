; Ian Braudaway
; CS403 Assign 3, Task 5

(include "streams.scm")

(define (accumulate op initial sequence)
	(if (nil? sequence)
		initial
		(op (car sequence)
			(accumulate op initial (cdr sequence)))
		)
	)

(define (smush stream op)


	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
