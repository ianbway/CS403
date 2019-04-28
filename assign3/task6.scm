; Ian Braudaway
; CS403 Assign 3, Task 6

(include "streams.scm")

(define (square x) 
	(* x x)
	)

(define (quad coeffOne coeffTwo coeffThree stepVal)
	(define (stepStream stream)
		(cons-stream 
			(+ (stream-car stream) (real stepVal)) 
				(stepStream (stream-cdr stream)))
		)

	(define (fStream stream)
		(cons-stream 
			(+ (* coeffOne (square (stream-car stream))) (* coeffTwo (stream-car stream)) coeffThree) 
				(fStream (stream-cdr stream))
			)
		)

	(define x 
		(cons-stream 
			(real 0) 
				(stepStream x)))

	(cons-stream 
		(+ (* coeffOne (square (stream-car x))) (* coeffTwo (stream-car x)) coeffThree) 
			(fStream (stream-cdr x)))
	)

(define (integrateHelper stream integral stepVal)
	(cons-stream 
		(+ (stream-car integral) 
			(* (/ (+ (stream-car stream) (stream-car (stream-cdr stream))) 2) stepVal)) 
		(integrateHelper (stream-cdr stream) (stream-cdr integral) stepVal))
	)

(define (integrate stream stepVal)
	(define integral 
		(cons-stream (real 0) 
			(integrateHelper stream integral stepVal)))
	)

(define (derivate stream stepVal constant)
	(define (derivateHelper stream constant1)
		(define constant2 (- (* (/ (- (stream-car (stream-cdr stream)) (stream-car stream)) stepVal) 2) constant1))
		(cons-stream constant2 
			(derivateHelper (stream-cdr stream) constant2))
		)

	(cons-stream 
		(real constant) 
			(derivateHelper stream constant))
	)

(define (same-stream? s1 s2 n t)
	(cond
		((= n 0) 
			#t)
		((<= (abs (- (stream-car s1) (stream-car s2))) t) 
			(same-stream? (stream-cdr s1) (stream-cdr s2) (- n 1) t))
		(else 
			#f)
		)
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (newline)
; (define (rsd n s)
; 	(define (iter n s)
; 		(cond
; 			((= n 0) (print "..."))
; 			(else
; 				(print (fmt "%.5f" (stream-car s)) ",")
; 				(iter (- n 1) (stream-cdr s)))
; 			)
; 		)
; 	(print "(")
; 	(iter n s)
; 	(print ")")
; 	)

; (define qs (quad 1 0 0 1))
; (define is (integrate qs 1))
; (define ds (derivate is 1 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define (add-streams s t)
;     (cons-stream
;         (+ (stream-car s) (stream-car t))
;         (add-streams (stream-cdr s) (stream-cdr t))))
; (define (scale-stream s f)
;     (cons-stream
;         (* (stream-car s) f)
;         (scale-stream (stream-cdr s) f)))
; (define ones (cons-stream 1 ones))
; (define ones*f (cons-stream 1 (cons-stream 1 (cons-stream 1 (scale-stream ones 1.1)))))
; (inspect (same-stream? ones ones*f 3 .001))
; (inspect (same-stream? ones ones*f 5 .001))
; (inspect (same-stream? ones ones*f 5 2.0))
; (inspect (same-stream? ones ones*f 5 0.2))
; (inspect (same-stream? ones ones*f 5 0.1001))
; (inspect (same-stream? ones ones*f 5 0.1))
; (inspect (same-stream? ones ones*f 5 0.0999))
; (newline)

; (define qs (quad 0 -3 -1 0.0416666667))
; (define is (integrate qs 0.0416666667))
; (define ds (derivate is 0.0416666667 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad -2 -2 -4 0.0227272727))
; (define is (integrate qs 0.0227272727))
; (define ds (derivate is 0.0227272727 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad 2 3 3 0.0156250000))
; (define is (integrate qs 0.0156250000))
; (define ds (derivate is 0.0156250000 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad 1 2 3 0.0119047619))
; (define is (integrate qs 0.0119047619))
; (define ds (derivate is 0.0119047619 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad 1 0 -4 0.2000000000))
; (define is (integrate qs 0.2000000000))
; (define ds (derivate is 0.2000000000 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad -2 1 1 0.0400000000))
; (define is (integrate qs 0.0400000000))
; (define ds (derivate is 0.0400000000 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad 2 2 1 0.0105263158))
; (define is (integrate qs 0.0105263158))
; (define ds (derivate is 0.0105263158 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)

; (define qs (quad 2 2 3 0.0156250000))
; (define is (integrate qs 0.0156250000))
; (define ds (derivate is 0.0156250000 (stream-car qs)))
; (rsd 5 qs) (println)
; (rsd 5 is) (println)
; (rsd 5 ds) (println)
; (inspect (same-stream? qs ds 10 .001))
; (newline)
