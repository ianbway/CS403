; Ian Braudaway
; CS403 Assign 2, Task 2

(define (curryHelp func counter)
	(cond
		((== counter (length (get 'parameters func))) )
		(else
			(curryHelp func (+ counter 1)))
		)

	)

(define (curry func)
	(apply func (curryHelp func 1))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
