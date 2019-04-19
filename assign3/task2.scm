; Ian Braudaway
; CS403 Assign 3, Task 2

(define (replace symbol value)
	(inspect symbol)
	(inspect value)


	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
