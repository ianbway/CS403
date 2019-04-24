; Ian Braudaway
; CS403 Assign 3, Task 5

(include "streams.scm")

(define (partial-sums s) 
   (add-streams s (cons-stream 0 (partial-sums s))))

; (define (acc-stream stream op) 
;    (stream-map op stream (cons-stream 0 (acc-stream stream op))))

(define (smush stream op)
	(define indicesAndStream (cons-stream indices stream))
	(cons-stream indicesAndStream (partial-sums stream))

	;(cons-stream indices (cons-stream stream (cons-stream (partial-sums stream))))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
