; Ian Braudaway
; CS403 Assign 3, Task 2

(define (checkThisPair functionToLookIn replaceThis withThis)
	(define body (get 'code functionToLookIn))


	(inspect body)
	(inspect (car body))
	(inspect (cadr body))
	; (cond

	; 	)


	)

(define (replace functionToLookIn listOfReplacements)
	;(inspect functionToLookIn)
	;(inspect (car functionToLookIn))
	;(inspect (cadr functionToLookIn))
	(define name (get 'name functionToLookIn))
	;(inspect name)
	;(inspect listOfReplacements)
	(define params (get 'parameters functionToLookIn))
	(define body (get 'code functionToLookIn))

	;(set 'code listOfReplacements name)
	;(inspect params)
	;(inspect (car params))
	; (inspect body)
	; (inspect (car body))
	; (inspect (cdr body))
	; (inspect (cadr body))

	; (inspect listOfReplacements)
	; (inspect (car listOfReplacements))
	; (inspect (cadr listOfReplacements))
	(println "test")

	(cond 
		((nil? listOfReplacements) functionToLookIn)
		(else
			(checkThisPair functionToLookIn (car listOfReplacements) (cadr listOfReplacements))
			(replace functionToLookIn (cddr listOfReplacements))
			)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
