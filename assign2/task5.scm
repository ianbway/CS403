; Ian Braudaway
; CS403 Assign 2, Task 5

(define (create arabic)
	(cond
		((== 0 arabic) 
			(lambda (f) 
				(lambda (x) 
					x)))
		(else
			((lambda (n)
				(lambda (f)
					(lambda (x)
						(f ((n f) x))
						)
					)
				) 
			(create (- arabic 1)))
			)
		)
	)

(define pred 
	(lambda (n)
		((lambda (t)
			(t 
				(lambda (x) 
					(lambda (y) x))))
		((n (lambda (t)
			(((lambda (ca)
				(lambda (cr)
					(lambda (w)
						((w ca) cr))))
			((lambda (t)
				(t (lambda (x) (lambda (y) y)))) t))
			((lambda (n)
				(lambda (f)
					(lambda (x)
						(f ((n f) x))))) 
			((lambda (t)
				(t (lambda (x) (lambda (y) y)))) t)))))    
		(((lambda (ca)
			(lambda (cr)
				(lambda (w)
					((w ca) cr)))) 
		(lambda (f) 
			(lambda (x) x))) 
		(lambda (f) 
			(lambda (x) x))))))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (println (((create 4) (lambda (x) (+ x 1))) 0))

; (println (((create 4) (lambda (x) (cons 'x x))) nil))

; (println (((pred (create 4)) (lambda (x) (+ x 1))) 0))

; (println (((pred (pred (create 4))) (lambda (x) (+ x 1))) 0))

; (println (((pred (pred (create 10))) (lambda (x) (* x 2))) 1))

; (println (((pred (pred (create 10))) (lambda (x) (list x))) 'x))

; (println (((pred (pred (create 10))) (lambda (x) (cons 'x x))) nil))

; (println (((pred (pred (pred (create 3)))) (lambda (x) (list x x))) 'zero))
