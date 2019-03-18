; Ian Braudaway
; CS403 Assign 1, Task 5

(define (curry func)
	(lambda(w)
		(lambda(x)
			(lambda(y)
				(lambda(z)
					(func w x y z)))))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (eval (readExpr) this))
	(define arg1 (readExpr))
	(define arg2 (readExpr))
	(define arg3 (readExpr))
	(define arg4 (readExpr))
	;(setPort (open (getElement ScamArgs 1) 'read))
	;(define nameArg (print arg))
	(println (string+ "(((((curry " arg ") " arg1 ") " arg2 ") " arg3 ") " arg4 ") is " (((((curry arg) arg1) arg2) arg3) arg4)))
	;(print (((((curry arg) arg1) arg2) arg3) arg4) )
	)