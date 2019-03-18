; Ian Braudaway
; CS403 Assign 1, Task 4

(define (crazyTriangle left right)
	(define (trianglePrint levels)
		(cond ((== levels 1) (println left))
			  (())
			)

	)
		)


(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define argOne (readExpr))
	(define argTwo (readExpr))
	(define argThree (readExpr))
	((crazyTriangle argOne argTwo) argThree)
	)

