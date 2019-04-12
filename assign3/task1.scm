; Ian Braudaway
; CS403 Assign 3, Task 1

(define (checkNextScope symbol object originalObject)
	(cond
		((== (car object) symbol)
			#t
			)
		((== (cdr object) nil)
			(cond
				((== (dot originalObject __context) nil) #f)
				(else
					(checkNextScope symbol (cadr (dot originalObject __context)) (dot originalObject __context))
					)
				)
			)
		(else
			(checkNextScope symbol (cdr object) originalObject)
			)
		)
	)

(define (checkThisScope symbol object)
	(cond
		((== (car object) symbol)
			#t
			)
		((== (cdr object) nil)
			#f)
		(else
			(checkThisScope symbol (cdr object)))
		)
	)

(define (scoping symbol object)
	(cond
		((== (checkThisScope symbol (cadr object)) #t) 
			'bound)
		((== (checkNextScope symbol (cadr (dot object __context)) (dot object __context)) #t)
			'free)
		(else
			'undefined
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
