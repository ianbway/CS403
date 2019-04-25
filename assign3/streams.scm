; Ian Braudaway
; CS403 Assign 3 Stream Functions

(define (stream-ref s n)
	(if (= n 0)
		(stream-car s)
		(stream-ref (stream-cdr s) (- n 1))))

(define (stream-enumerate-interval low high)
	(if (> low high)
		'()
		(cons-stream
			low
			(stream-enumerate-interval (+ low 1) high))))

(define (stream-filter pred stream)
	(cond ((stream-null? stream) '())
		((pred (stream-car stream))
			(cons-stream (stream-car stream)
						 (stream-filter pred
						 				(stream-cdr stream))))
		(else (stream-filter pred (stream-cdr stream)))))

; (define (stream-map proc s)
; 	(if (stream-null? s)
; 		'()
; 		(cons-stream (proc (stream-car s))
; 			(stream-map proc (stream-cdr s)))))

(define (stream-map proc . argstreams)
  (if (stream-null? (car argstreams))
    '()
    (cons-stream
      (apply proc (map stream-car argstreams))
      (apply stream-map (cons proc
                              (map stream-cdr argstreams))))))

(define (shuffle s t)
	(cons-stream (stream-car s) (shuffle t (stream-cdr s))))

(define (pairs s t)
	(shuffle
		(stream-map (lambda (x) (list (stream-car s) x)) t)
			(pairs (stream-cdr s) (stream-cdr t))
		)
	)

(define (add-shuffle-streams s t)
	(cons-stream
		(+ (stream-car s) (stream-car t))
			(add-shuffle-streams t (stream-cdr s))
		)
	)

(define (add-streams s1 s2)
	(stream-map + s1 s2))

(define (merge s1 s2)
	(cond ((stream-null? s1) s2)
		  ((stream-null? s2) s1)
		  (else
		  	(let ((s1car (stream-car s1))
		  		  (s2car (stream-car s2)))
		  	 (cond ((< s1car s2car)
		  	 		(cons-stream s1car (merge (stream-cdr s1) s2)))
		  	 	   ((> s1car s2car)
		  	 	   	(cons-stream s2car (merge s1 (stream-cdr s2))))
		  	 	   (else
		  	 	   	(cons-stream s1car
		  	 	   				 (merge (stream-cdr s1)
		  	 	   				 		(stream-cdr s2)))))))))

(define (stream-for-each proc s)
	(if (stream-null? s)
		'done
		(begin (proc (stream-car s))
				(stream-for-each proc (stream-cdr s)))
		)
	)

(define (display-line x)
	(newline)
	(display x)
	)

(define (display-stream s)
	(stream-for-each display-line s)
	)

(define (sdisplay upToIndex stream)
	(print "(")
	(define (iter index s)
		(cond
			((stream-null? s) 
				(print "...)")
				)
			((= index 0)
				(print "...)")
				)
			(else
				(begin (print (stream-car s) ",")
					(iter (- index 1) (stream-cdr s)))
				)
			)
		)
	(iter upToIndex stream)
	)

(define (force delayed-object)
	(delayed-object))

(define (delay expression)
	(memo-proc (lambda () expression))
	)

(define (memo-proc proc)
	(let ((already-run? false) (result false))
		(lambda()
			(if (not already-run?)
				(begin (set! result (proc))
					   (set! already-run? true)
					   result)
				result))))

(define (scale-stream stream factor)
	(stream-map (lambda (x) (* x factor)) stream))

(define (integers-starting-from n)
	(cons-stream n (integers-starting-from (+ n 1)))
	)

(define indices (integers-starting-from 0))

(define integers (integers-starting-from 1))

(define ones (cons-stream 1 ones))
