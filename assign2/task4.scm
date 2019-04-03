; Ian Braudaway
; CS403 Assign 2, Task 4

(define (lambdaize var val body)
		;(list (cons 'lambda (cons (list var) body)) val)
		(list (cons 'lambda (cons (list var) body)) val)
	)

(define (lambdaFeeder pairings body)
	(cond
		((nil? (cdr pairings)) 
			(lambdaize (car (car pairings)) (car (cdr (car pairings))) body)
			)
		(else
			(lambdaize (car (car pairings)) (car (cdr (car pairings))) (lambdaFeeder (cdr pairings) body))
			)
		)
	)

(define (let*->lambdas func)
	; (inspect (car func))
	; (inspect (cdr func))
	; (inspect (car (cdr func)))
	; (inspect (cdr (cdr func)))
	; (inspect (car (cdr (cdr func))))
	; (inspect (cdr (cdr (car (cdr (cdr func))))))
	; (inspect (car (cdr (car (cdr (cdr func))))))
	; (inspect (car (car (cdr (car (cdr (cdr func)))))))
	; (inspect (car (car (car (cdr (car (cdr (cdr func))))))))
	; (inspect (cdr (car (car (cdr (car (cdr (cdr func))))))))
	; (inspect (car (cdr (car (car (cdr (car (cdr (cdr func)))))))))
	; (inspect (cdr (car (cdr (car (cdr (cdr func)))))))
	; (inspect (cdr (cdr (car (cdr (car (cdr (cdr func))))))))
	; (inspect (car (car (cdr (cdr func)))))
	; (inspect (cdr (cdr (cdr func))))
	;(inspect func)


	(define defineWord (car func))
	(define arbitraryFuncName (car (cdr func)))
	(define paramArgList (car (cdr (car (cdr (cdr func))))))
	(define body (cdr (cdr (car (cdr (cdr func))))))

	(inspect defineWord)
	(inspect arbitraryFuncName)
	(inspect paramArgList)
	(inspect body)

	(list defineWord arbitraryFuncName (lambdaFeeder paramArgList body))

	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

;(inspect (lambdaize 'y 3 '((* y y))))

; (define sd '(define (f x) (define y 2) (+ x y)))
; (println (let*->lambdas sd))
; (inspect ((eval (let*->lambdas sd) this) 3))

; (define sd '(define (f x) (let* ((y 2)) (+ x y))))
; (println (let*->lambdas sd))
; (inspect ((eval (let*->lambdas sd) this) 3))

; (println (let*->lambdas '(define (f x) (let ((y 2) (z 3)) (+ x y z)))))

; (println (let*->lambdas '(define (g x y) (let* ((w (+ 2 3))) (+ x y w)))))

; (println (let*->lambdas '(define (g x y) (let* ((w (+ 2 3))) (inspect w) (+ x y w)))))

; (define sd '(define (g x y) (let* ((w (+ 2 3)) (z (* 2 w))) (inspect w) (inspect z) (+ x y w z))))
; (println (let*->lambdas sd))
; (inspect ((eval (let*->lambdas sd) this) 3 4))
