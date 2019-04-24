; Ian Braudaway
; CS403 Assign 3, Task 8

(include "streams.scm")

(define (cube x)
	(* x x x)
	)

(define (weight i j)
  (+ (cube i) (cube j)))

(define ramanujan 
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
