; Ian Braudaway
; CS403 Assign 1, Task 4

(define (crazyTriangle left right)
	(define (trianglePrint levels)
		(cond ((== left 0) left)
			  ((== left right) right)
			  (else ((+ crazyTriangle (left - 1, right - 1) crazyTriangle(left - 1, right))))
			)

	)
		)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define left (readExpr))
	(define right (readExpr))
	(define levels (readExpr))
	(print ((crazyTriangle left right) levels) )
	)

