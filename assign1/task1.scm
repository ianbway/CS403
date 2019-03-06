; Ian Braudaway
; CS403 Assign 1, Task 1

(define (toHexZero number)
	(cond
		((== number 0) "000")
		((== number 1) "001")
		((== number 2) "002")
		((== number 3) "003")
		((== number 4) "004")
		((== number 5) "005")
		((== number 6) "006")
		((== number 7) "007")
		((== number 8) "008")
		((== number 9) "009")
		(else (toHex number))
		)
	)

(define (toHex number)
	(cond
		((== (int number) 0) " ")
		((== (% (int number) 16) 10) 
			(string+ (string (toHex (/ (int number) 16))) "A"))
		((== (% (int number) 16) 11) 
			(string+ (string (toHex (/ (int number) 16))) "B"))
		((== (% (int number) 16) 12) 
			(string+ (string (toHex (/ (int number) 16))) "C"))
		((== (% (int number) 16) 13) 
			(string+ (string (toHex (/ (int number) 16))) "D"))
		((== (% (int number) 16) 14) 
			(string+ (string (toHex (/ (int number) 16))) "E"))
		((== (% (int number) 16) 15) 
			(string+ (string (toHex (/ (int number) 16))) "F"))
		(else (string+ (string (toHex (/ (int number) 16))) (string (% (int number) 16))))
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
			 (cdr (toHexZero (cyan value))) 
			 (cdr (toHexZero (yellow value))) 
			 (cdr (toHexZero (magenta value))))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define arg (readExpr))
	(println(string+ "(cyan " arg ") is " (cyan arg)))
	(println(string+ "(yellow " arg ") is " (yellow arg)))
	(println(string+ "(magenta " arg ") is " (magenta arg)))
	(println(string+ "(cym " arg ") is " (cym arg)))
	)