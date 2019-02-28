; Ian Braudaway
; CS403 Assign 1, Task 1

(define (cyan value)

	(int (+ value 0.00000001))
	)


(define (yellow value)

	(int (+ value 0.00000001))
	)


(define (magenta value)

	(int (+ value 0.00000001))
	)

(define (cym value)
	(string+ "#"
			 (cyan value) 
			 (yellow value) 
			 (magenta value))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println (cym arg))
	)
