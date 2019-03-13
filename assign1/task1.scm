; Ian Braudaway
; CS403 Assign 1, Task 1

(define (toHex number)
	(string+ "" (hexLetters (/ number 16)) (hexLetters (% number 16)))
	)

(define (hexLetters number)
	(cond
		((< number 10) number)
		((== number 10) "A")
		((== number 11) "B")
		((== number 12) "C")
		((== number 13) "D")
		((== number 14) "E")
		((== number 15) "F")
		)
	)

(define (cyan value)
	(int (+ (* 255.0 (cos (* (/ 3.14159265358979323846 200.0) value))) 0.00000001))
	)


(define (yellow value)
	(int (+ (+ 255.0 (* 255.0 (sin (* (/ (* -2.0 3.14159265358979323846) 200.0) value)))) 0.00000001))
	)


(define (magenta value)
	(int (+ (+ (/ 255.0 2.0) (* (/ 255.0 2.0) (cos (* (/ (* -3.0 3.14159265358979323846) 200.0) value)))) 0.00000001))
	)

(define (cym value)
	(string+ "#"
			 (toHex (cyan value)) 
			 (toHex (yellow value)) 
			 (toHex (magenta value)))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println(string+ "(cyan " arg ") is " (cyan arg)))
	(println(string+ "(yellow " arg ") is " (yellow arg)))
	(println(string+ "(magenta " arg ") is " (magenta arg)))
	(println(string+ "(cym " arg ") is " (cym arg)))
	)