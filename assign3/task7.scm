; Ian Braudaway
; CS403 Assign 3, Task 7

(include "streams.scm")

(define (make-tableau transform s)
	(cons-stream s 
				 (make-tableau transform
							   (transform s))))

(define (accelerated-sequence transform s)
	(stream-map stream-car
				(make-tableau transform s)))

(define (euler-transform stream)
  (let ((s0 (stream-ref stream 0))
		(s1 (stream-ref stream 1))
		(s2 (stream-ref stream 2)))
	(cons-stream 
		(cond
			((= 0 (+ s0 (* s1 -2) s2)) 
				s2)
			(else
				(- s2 (/ (* (- s2 s1) (- s2 s1))
				 (+ s0 (* s1 -2) s2)))
				)
			)
		(euler-transform (stream-cdr stream)))))

(define (partial-sums stream)
  (let ((first (stream-car stream)))
	(cons-stream
	  first
	  (stream-map (lambda (x) (+ x first)) (partial-sums (stream-cdr stream))))))

(define (factorial number)
	(cond
		((= number 1)
			1)
		(else
			(* number (factorial (- number 1)))
			)
		)
	)

(define (mystery-helper x index) 
	(cond
		; even index
		((= (% index 2) 0) 
			(cons-stream (/ (real (^ x (* index 2))) (real (factorial (* index 2)))) (mystery-helper x (+ index 1)))
			)
		; odd index
		(else
			(cons-stream (* (- 1.0) (/ (real (^ x (* index 2))) (real (factorial (* index 2))))) (mystery-helper x (+ index 1)))
			)
		)
	)

(define (mystery x)
	(cons-stream (real 1) (mystery-helper x 1))
	)

(define (ps-mystery x)
	(partial-sums (mystery x))
	)

(define (acc-mystery x)
	(euler-transform (ps-mystery x))
	)

(define (super-mystery x)
	(accelerated-sequence euler-transform (ps-mystery x))
	)

(define (symbolic-mystery)
	(println "(mystery x) is $\\cos x$")
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (newline)
; (define x 0.1)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 0)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 1)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x -6)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 5)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x -3)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 8)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x -9)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 1)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
; (define x 3)
; (sdisplay 5 (mystery x)) (println)
; (sdisplay 5 (ps-mystery x)) (println)
; (sdisplay 5 (acc-mystery x)) (println)
; (sdisplay 5 (super-mystery x)) (println)
; (symbolic-mystery)

; (newline)
