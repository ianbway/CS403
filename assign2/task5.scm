; Ian Braudaway
; CS403 Assign 2, Task 5

(define (create  )


	)

(define (pred  )


	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
