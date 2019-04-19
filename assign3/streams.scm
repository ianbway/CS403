; Ian Braudaway
; CS403 Assign 3 Stream Functions

(define (stream-map proc s)
	(if (stream-null? s)
		'()
		(cons-stream (proc (stream-car s))
			(stream-map proc (stream-cdr s)))))

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
