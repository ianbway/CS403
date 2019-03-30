; Ian Braudaway
; CS403 Assign 2, Task 6

(define (powerSet symbols)
	(setNilDisplay 'nil)
	(if (nil? symbols)
       '(())
        (merge (powerSet (cdr symbols)) 
          	(map (lambda (x) (cons (car symbols) x)) 
          		(powerSet (cdr symbols))))))

(define (merge listOne listTwo)
	(setNilDisplay 'nil)
    (cond
    	((nil? listOne) listTwo)
    	((nil? listTwo) listOne)
    	((>= (length (car listOne)) (length (car listTwo))) 
    		(cons (car listTwo) 
    			(merge listOne (cdr listTwo))))
    	(else
    		(cons (car listOne)  
    			(merge (cdr listOne) listTwo)))))

(define (main)
	(setNilDisplay 'nil)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

;(println (powerSet '(a b)))

;(println (powerSet '(s e t)))

;(println (powerSet '(y w e b u r)))

;(println (powerSet '(z k t v u)))

;(println (powerSet '(c g z w x)))

;(println (powerSet '(u r i p e w b)))

;(println (powerSet '(l w k e)))

;(println (powerSet '(r f x g h o y i)))

;(println (powerSet '(u h g q a p t y l)))

;(println (powerSet '(s k o u p d q l z m b)))
