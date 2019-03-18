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
	(define f (eval (readExpr) this))
	(define a (readExpr))
	(define b (readExpr))
	(define c (readExpr))
	(define d (readExpr))
	(println "(((((curry " f ") " a ") " b ") " c ") " d ") is " (((((curry f) a) b) c) d))
	)