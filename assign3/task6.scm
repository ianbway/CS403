; Ian Braudaway
; CS403 Assign 3, Task 6

(include "streams.scm")

(define (quad coeffOne coeffTwo coeffThree stepVal)


	)

(define (integrate stream stepVal)


	)

(define (derivate stream stepVal constant)


	)

(define (same-stream? s1 s2 n t)


	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
