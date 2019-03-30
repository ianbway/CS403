; Ian Braudaway
; CS403 Assign 2, Task 4

(define (let*->lambdas func)
	; (inspect (car func))
	; (inspect (cdr func))
	; (inspect (car (cdr func)))
	; (inspect (cdr (cdr func)))
	; (inspect (car (cdr (cdr func))))
	; (inspect (car (car (cdr (cdr func)))))
	; (inspect (cdr (cdr (cdr func))))
	; (inspect func)

	(cond
		((== nil (cdr func)) func)
		((== "let*" (car func)) )
		(else
			(let*->lambdas (cdr func))
			)
	 	)

	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
