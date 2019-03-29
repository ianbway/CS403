; Ian Braudaway
; CS403 Assign 2, Task 4

(define (let*->lambdas func)
	(inspect (car func))
	(inspect (cdr func))
	(inspect func)

	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
