; Ian Braudaway
; CS403 Assign 2, Task 6

(define (powerSet symbols)
	(if (nil? symbols)
       '(())
        (append (powerSet (cdr symbols)) 
          	(map (lambda (x) (cons (car symbols) x)) 
          		(powerSet (cdr symbols))))))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(setNilDisplay 'nil)
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
