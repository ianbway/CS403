; Ian Braudaway
; CS403 Assign 3, Task 7

(include "streams.scm")

(define (mystery x)


	)

(define (ps-mystery x)


	)

(define (acc-mystery x)


	)

(define (super-mystery x)


	)

(define (symbolic-mystery)
	(println "(mystery x) is $\\cos x$")
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
