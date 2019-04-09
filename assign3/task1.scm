; Ian Braudaway
; CS403 Assign 3, Task 1

(define (checkFinalScope symbol object)
	(cond
		((== (car object) symbol)
			#t
			)
		((== (cdr object) nil)
			#f)
		(else
			(checkFinalScope symbol (cdr object)))
		)
	)

(define (checkNextScope symbol object)
	(cond
		((== (object __context) nil)
			(checkFinalScope symbol object)
			)
		((== (car object) symbol)
			#t
			)
		((== (cdr object) nil)
			(scoping symbol object)
			)
		(else
			(checkNextScope symbol (cdr object))
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
	(println "test")
	(println (ppTable object))
	(println (ppTable (dot object __context)))
	(println (ppTable (dot (dot object __context) __context)))
	(println (ppTable (dot (dot (dot object __context) __context) __context)))
	(println (ppTable (dot (dot (dot (dot object __context) __context) __context) __context)))
	(println (ppTable (dot (dot (dot (dot (dot object __context) __context) __context) __context) __context)))
	; (inspect (define nextScope (dot object __context)))

	; (cond
	; 	((== (checkThisScope symbol object) #t) 
	; 		'bound)
	; 	((== (checkNextScope symbol nextScope) #t)
	; 		'free)
	; 	((== (checkNextScope symbol object) #f)
	; 		(checkNextScope symbol (nextScope __context)))
	; 	((== (checkFinalScope symbol object) #t)
	; 		'free)
	; 	((== (checkFinalScope symbol object) #f)
	; 		'undefined)
	; 	)
	; (println symbol)
	; (inspect (car object))
	; (inspect (cdr object))
	; (inspect (cadr object))
	; (inspect (cddr object))
	; (inspect (caddr object))
	; (inspect (car (cadr object)))
	; (inspect (cdr (cadr object)))

	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
