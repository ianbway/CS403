; Ian Braudaway
; CS403 Assign 1, Task 6

(define (S f n)
	(cond
		((<= n 0) (f n))
		(else 
			(+ (f n) (S f (- n 1))))
		)
	)

(define (w function iterator)
	(cond
		((== iterator 0) (function iterator))
		(else 
			(/ (real (- (* (S function (- iterator 1)) (S function (+ iterator 1))) (^ (S function iterator) 2)))
				(real (+ (- (S function (+ iterator 1)) (* 2 (S function iterator))) (S function (- iterator 1))))
				)
			)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define function (eval (readExpr) this))
	(define iterator (readExpr))
	(println "(S " function " " iterator ") is " (fmt "%.15f" (S function iterator)))
	(println "(w " function " " iterator ") is " (fmt "%.15f" (w function iterator)))
	)

;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 0)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 0)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1)))
;(inspect (fmt "%.15f" (S (lambda (x) (* (if (= (% x 2) 0) 1 -1) (/ 1.0 (+ x 1)) (^ 0.5 (+ x 1)))) 33)))
;(inspect (fmt "%.15f" (w (lambda (x) (* (if (= (% x 2) 0) 1 -1) (/ 1.0 (+ x 1)) (^ 0.5 (+ x 1)))) 33)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1807)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1807)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1395)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1395)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1477)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1477)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1062)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1062)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1642)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1642)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1232)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1232)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1313)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1313)))
;(inspect (fmt "%.15f" (S (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1901)))
;(inspect (fmt "%.15f" (w (lambda (x) (/ (if (= (% x 2) 0) 1 -1) (+ x 1.0))) 1901)))
