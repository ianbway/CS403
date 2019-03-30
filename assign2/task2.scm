; Ian Braudaway
; CS403 Assign 2, Task 2

(define (curry @)
	;(length (get 'parameters (car @)))

	(if (== 1 (length (car @)))
		(apply (car @) '(cdr @))
		(lambda (@) (curry (cdr @)))
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (define (f a b) (+ a b))
; (inspect (curry f))

; (define (f a b) (+ a b))
; (inspect ((curry f) 1))

; (define (f a b) (+ a b))
; (inspect (((curry f) 1) 1))

; (define (f a b) (+ a b))
; (inspect ((curry f) 1 1))

; (define (f a b) (+ a b))
; (inspect (curry f 1 1))

; (define (g a b c d) (- a b c d))
; (inspect ((curry g) 39 10 9 1))

; (define (g a b c d) (- a b c d))
; (inspect ((curry g 21) 11 7 4))

; (define (g a b c d) (- a b c d))
; (inspect (((curry g) 23 13) 9 3))

; (define (g a b c d) (- a b c d))
; (inspect ((curry g 25 14) 9 4))

; (define (g a b c d) (- a b c d))
; (inspect (((curry g 36) 10) 7 4))
