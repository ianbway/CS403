; Ian Braudaway
; CS403 Assign 1, Task 4

(define (pascalElem left right)
	(cond ((== left 0) left)
		  ((== left right) right)
		  (else ((+ (pascalElem (- left 1) (- right 1)) 
		  			(pascalElem (- left 1) right)))))
	)

(define (crazyTriangle left right)
	(define (trianglePrint levels)
		(cond
			((== levels 0) return)
			(else (println (pascalElem left right))
				(trianglePrint (- levels 1)))
			)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define left (readExpr))
	(define right (readExpr))
	(define levels (readExpr))
	((crazyTriangle left right) levels)
	)

