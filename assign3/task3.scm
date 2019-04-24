; Ian Braudaway
; CS403 Assign 3, Task 3

(define (deque)
	(define front nil)
	(define back nil)
	(define q (cons front back))

	(define (enqueueFront value)


		)

	(define (enqueueBack value)


		)

	(define (enqueueIndex index value)


		)

	(define (dequeueFront)


		)

	(define (dequeueBack)


		)

	(define (dequeueIndex index)


		)

	(define (display)


		)

	(define (peekFront)


		)

	(define (peekBack)



		)

	(define (size)


		)

	this
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
