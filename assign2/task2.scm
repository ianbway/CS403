; Ian Braudaway
; CS403 Assign 2, Task 2

(define (curry @)
	(inspect @)
	(inspect (car @))
	(inspect (cdr @))

	(if (valid? @)
		(lambda (@)
			(apply (car @) (curry (car @))))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
