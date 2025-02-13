; Ian Braudaway
; CS403 Assign 2, Task 4

(define (lambdaize var val body)
		(list (cons 'lambda (cons (list var) body)) val)
	)

(define (lambdaFeeder pairings body)
	(cond
		((nil? (cdr pairings)) 
			(lambdaize (car (car pairings)) (car (cdr (car pairings))) body)
			)
		(else
			(lambdaize (car (car pairings)) (car (cdr (car pairings))) (list (lambdaFeeder (cdr pairings) body)))
			)
		)
	)

(define (listReturn func) 
	(define defineWord (car func))
	(define arbitraryFuncName (car (cdr func)))
	(define paramArgList (car (cdr (car (cdr (cdr func))))))
	(define body (cdr (cdr (car (cdr (cdr func))))))
	(list defineWord arbitraryFuncName (lambdaFeeder paramArgList body))
	)

(define (let*->lambdas func)
	(if (!= (car (car (cdr (cdr func)))) 'let*)
		func
		(listReturn func)
		)
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
