; Ian Braudaway
; CS403 Assign 2, Task 2

(define (curry @)
	; (inspect @)
	; (inspect (car @))
	; (inspect (cdr @))
	(inspect (length (get 'parameters (car @))))

	(if (== 0 (length (get 'parameters (car @))))
		(apply (car @) (cdr @))

		(lambda (@) (curry @))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
