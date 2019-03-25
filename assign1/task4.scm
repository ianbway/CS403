; Ian Braudaway
; CS403 Assign 1, Task 4

(define (pascal left right row col)
    (cond 
    	((= col 1) left)
        ((= col row) right)
        (else (+ (pascal left right (- row 1) (- col 1))
                 (pascal left right (- row 1) col)))
        )
    )

(define (triangleMake left right levels row)
    (cond
    	((< row levels) 
    		(spacesPrint row levels)
    		(rowPrint left right row 1)
    		(println "")
    		(triangleMake left right levels (+ row 1))
    		)
    	(else
    		(rowPrint left right row 1)
    		(println ""))
    	)
    )

(define (spacesPrint counter levels)
    (cond
    	((< counter (- levels 1)) 
    		(print " ")
    		(spacesPrint (+ counter 1) levels))
    	(else
    		(print " "))
    	)
    )

(define (rowPrint left right row col)
    (cond
    	((== col row) (print (pascal left right row col)))
    	(else
    		(print (pascal left right row col))
    		(print " ")
    		(rowPrint left right row (+ col 1))
    		)
    	)
    )

(define (crazyTriangle left right)
    (define (trianglePrint levels)
        (triangleMake left right levels 1)
        )
    )

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define left (readExpr))
	(define right (readExpr))
	(define levels (readExpr))
	(println "((crazyTriangle " left " " right ") " levels ")" )
	((crazyTriangle left right) levels)
	)

;((crazyTriangle 1 1) 5)
;((crazyTriangle 1 1) 1)
;((crazyTriangle 0 0) 8)
;((crazyTriangle -10 -11) 7)
;((crazyTriangle 16 -10) 10)
;((crazyTriangle -19 11) 6)
;((crazyTriangle -14 12) 3)
;((crazyTriangle -9 -7) 5)
;((crazyTriangle -3 15) 7)
;((crazyTriangle 2 16) 10)
;((crazyTriangle -13 7) 1)
