; Ian Braudaway
; CS403 Assign 1, Task 4

(define (pascal left right)
	(cond ((== left 0) left)
		  ((== left right) right)
		  (else ((+ (pascal (- left 1) (- right 1)) 
		  			(pascal (- left 1) right)))))
	)

(define (printerHelperHelper start end left right)
	(cond
		((== start end) " ")
		)
	(print (pascal left right))
	(printerHelperHelper (+ start 1) end left right)
	)

(define (printerHelper start end left right)
	(cond
		((== start end) " ")
		)
	(printerHelperHelper 0 start left right)
	(printerHelper (+ start 1) end left right)
	)

(define (crazyTriangle left right)
	(define (trianglePrint levels)


		(printerHelper 0 levels left right)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define left (readExpr))
	(define right (readExpr))
	(define levels (readExpr))
	((crazyTriangle left right) levels)
	)

