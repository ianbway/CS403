; Ian Braudaway
; CS403 Assign 2, Task 7

(define (dot-product v w)
   (accumulate + 0 (map * v w)))

(define (matrix-*-vector m v)
	(map (lambda (row) (dot-product row v)) m)
	)

(define (accumulate op initial sequence)
	(if (nil? sequence)
		initial
		(op (car sequence)
			(accumulate op initial (cdr sequence)))
		)
	)

(define (accumulate-n op initial sequence)
	(if (nil? (car sequence))
		nil
		(cons (accumulate op initial (map car sequence))
			  (accumulate-n op initial (map cdr sequence)))
		)
	)

(define (transpose mat)
	(accumulate-n cons nil mat)
	)

(define (matrix-*-matrix m n)
    (let ((cols (transpose m)))
    	(map (lambda (x) (matrix-*-vector cols x)) n)))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

;(println (transpose '((1 0) (0 1))))
;(println (matrix-*-matrix '((1 2) (3 4)) '((1 0) (0 1))))

;(println (dot-product '(1 2 3 4) '(5 6 7 8)))

;(println (transpose '((0 0 1 8 9) (4 1 3 5 1) (7 5 1 4 5) (4 0 1 3 8))))

;(println (matrix-*-matrix '((7 4 3) (9 8 9) (5 9 6) (6 2 9) (7 7 7)) '((8 6 3 8 8) (9 3 7 2 4) (8 3 1 2 1) (9 9 5 3 9) (4 3 4 3 0))))

;(println (transpose '((9 2 1 5) (8 5 8 5) (3 6 2 4) (3 5 3 3) (3 5 9 9))))

;(println (matrix-*-matrix '((1 5 3 6 7) (5 7 6 4 1) (2 8 4 3 9)) '((2 9 7) (4 4 3) (9 3 4) (3 7 6) (9 7 6))))

;(println (transpose '((8 4 5) (3 7 1) (0 7 5))))

;(println (matrix-*-matrix '((5 2 2) (9 2 6) (9 8 6)) '((1 3 1) (6 5 8) (1 1 7) (0 0 8) (5 9 6))))

;(println (transpose '((7 6 4) (0 6 2) (2 4 7) (1 8 5))))

;(println (matrix-*-matrix '((9 4 6 1 6) (7 6 5 4 7) (8 9 3 6 0)) '((9 8 6) (1 5 2) (6 0 8) (2 9 6))))
