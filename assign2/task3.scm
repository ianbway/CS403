; Ian Braudaway
; CS403 Assign 2, Task 3

(define (countSize s)
	(+ s 1)
	)

(define (Stack)	
	(cons nil nil)
	)

(define (push s v)
	(cons v s)
	)

(define (pop s)
	(car s)
	)

(define (speek s)
	(car s)
	)

(define (ssize s)


	)

(define (Queue)
	(cons nil nil)
	)

(define (enqueue q v)
	(cons q (cons v nil))
	)

(define (dequeue q)
	(car q)
	)

(define (qpeek q)
	(car q)
	)

(define (qsize q)


	)

; ; read some ints and place them in both a stack and queue
; (define (loop stack queue)
; 	(define x (readInt))
; 	(if (eof?)
; 		(list stack queue)
; 		(loop (push stack x) (enqueue queue x))
; 		)
; 	)

; ; empty out a stack, printing the values as they come off
; (define (popper s mode)
; 	(cond
; 		((!= (ssize s) 0)
; 			(if (= mode 1) (inspect (speek s)))
; 				(popper (pop s) mode)
; 			)
; 		)
; 	)

; ; empty out a queue, printing the values as they come off
; (define (dequeuer q mode)
; 	(cond
; 		((!= (qsize q) 0)
; 			(if (= mode 1) (inspect (qpeek q)))
; 			(dequeuer (dequeue q) mode)
; 			)
; 		)
; 	)

; (define (main)
; 	(define oldstream (setPort (open (get ScamArgs 1) 'read)))
; 	(define mode (get ScamArgs 2))
; 	(define data (loop (Stack) (Queue)))
; 	(setPort oldStream)
; 	(println "popping...")
; 	(popper (car data) mode)
; 	(println "dequeuing...")
; 	(dequeuer (cadr data) mode)
; 	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
