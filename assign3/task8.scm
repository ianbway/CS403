; Ian Braudaway
; CS403 Assign 3, Task 8

(include "streams.scm")

(define (merge-weighted s1 s2 weight)
    (cond ((stream-null? s1) s2)
	      ((stream-null? s2) s1)
	      (else
	            (let ((cars1 (stream-car s1))
	                  (cars2 (stream-car s2)))
	              (cond ((< (weight cars1) (weight cars2))
	                    (cons-stream cars1 
                        	(merge-weighted (stream-cdr s1) s2 weight)))
	                ((= (weight cars1) (weight cars2)) 
                        (cons-stream cars1 
                        	(merge-weighted (stream-cdr s1) s2 weight)))
                    (else 
                    	(cons-stream cars2
                        	(merge-weighted s1 (stream-cdr s2) weight))))))))

(define (weighted-pairs s1 s2 weight)
    (cons-stream (list (stream-car s1) (stream-car s2))
        (merge-weighted (stream-map (lambda (x) (list (stream-car s1) x))
                                                      (stream-cdr s2))
                        (weighted-pairs (stream-cdr s1) (stream-cdr s2) weight)
                                                 						weight)))

(define (ramanujanStream s) 
	(define (stream-cadr s) (stream-car (stream-cdr s))) 
	(define (stream-cddr s) (stream-cdr (stream-cdr s))) 
	(let ((scar (stream-car s)) 
	      (scadr (stream-cadr s))) 
	(if (= (addCubes scar) (addCubes scadr))  
	    (cons-stream (addCubes scar) 
	                 (ramanujanStream (stream-cddr s))) 
	    (ramanujanStream (stream-cdr s))))) 

(define (cube x) (* x x x)) 

(define (addCubes x) (+ (cube (car x)) (cube (cadr x)))) 
 
(define (ramanujan) 
    (ramanujanStream (weighted-pairs integers integers addCubes)))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (sdisplay 1 (ramanujan)) (println)

; (sdisplay 6 (ramanujan)) (println)

; (sdisplay 20 (ramanujan)) (println)
