; Ian Braudaway
; CS403 Assign 2, Task 3

(define (countSize size op)
	(op size 1)
	)

(define (Stack)	
	(cons (cons nil 0) nil)
	)

(define (push s v)
	(cons (cons v (countSize (cdr (car s)) +)) s)
	)

(define (pop s)
	(cdr s)
	)

(define (speek s)
	(car (car s))
	)

(define (ssize s)
	(cdr (car s))
	)

(define (Queue)
	(cons (Stack) (Stack))
	)

(define (enqueue q v)
	(define inputStack (car q))
	(define outputStack (cdr q))

	(cons (push inputStack v) outputStack)
	)

(define (reverseQueue q tempStack)
 	(cond
		((> (ssize q) 0)
			(reverseQueue (pop q) (push tempStack (speek q))))
		(else
			tempStack)
		)
	)

(define (dequeue q)
	(define inputStack (car q))
	(define outputStack (cdr q))

	(cond
		((== (ssize outputStack) 0)
			(cons (Stack) (pop (reverseQueue inputStack outputStack))))
		(else
			(cons inputStack (pop outputStack))
			)
		)
	)

(define (qpeek q)
	(define inputStack (car q))
	(define outputStack (cdr q))

	(cond
		((== (ssize outputStack) 0)
			(speek (reverseQueue inputStack outputStack)))
		(else
			(speek outputStack)
			)
		)
	)

(define (qsize q)
	(define inputStack (car q))
	(define outputStack (cdr q))
	
	(+ (ssize inputStack) (ssize outputStack))
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (println (speek (pop (pop (push (push (push (Stack) 3) 2) 1)))))

; (println (qpeek (dequeue (dequeue (enqueue (enqueue (enqueue (Queue) 1) 2) 3)))))

; (println (speek (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (Stack) 81) 15) 16) 26) 87) 95) 46) 27) 44) 62) 20) 76) 62) 25) 49) 61) 50) 15) 20) 38) 87) 77) 12) 56) 22) 55) 98) 27) 99) 75) 86) 80) 81) 93) 97) 68) 88) 44) 85) 33) 96) 96) 99) 59) 22) 49) 20) 62) 55) 31) 91) 42) 98) 93) 88) 20) 49) 87) 38) 48) 62) 25) 29) 43) 18) 27) 12) 97) 61) 87) 31) 58)))

; (println (ssize (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (push (Stack) 83) 78) 46) 45) 96) 90) 96) 57) 97) 72) 66) 32) 99) 78) 77) 73) 88) 70) 40) 86) 88) 95) 38) 80) 30) 50) 89) 39) 22) 29) 19) 96) 97) 56) 41) 94) 47) 38) 52) 44) 11) 18) 66) 10) 87) 44) 74) 75) 14) 14) 62) 93) 10) 90) 74) 30) 41) 63) 59) 54) 82) 69) 50) 80) 25) 82) 74) 62) 20) 26) 97) 21) 34) 63) 22) 22) 97) 86) 87) 12) 91) 50)))

; (println (qpeek (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (Queue) 86) 97) 33) 19) 62) 87) 57) 90) 61) 39) 68) 35) 48) 43) 62) 43) 39) 37) 62) 92) 93) 71) 22) 19) 86) 49) 85) 54) 40) 33) 47) 27) 30) 70) 37) 83) 57) 84) 73) 19) 24) 41) 44) 62) 75) 96) 95) 14) 34) 57) 97) 27) 29) 19) 37) 16) 59) 23) 60) 90) 47) 98) 17) 67) 68) 45) 50) 26) 29) 24) 35) 43) 56) 69) 96) 31) 66) 91) 36) 90) 49) 34) 18) 69) 44) 46) 75) 94) 59) 36) 84) 96) 34)))

; (println (qsize (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (enqueue (Queue) 88) 24) 63) 37) 71) 81) 61) 75) 69) 49) 23) 35) 84) 51) 44) 99) 31) 92) 80) 50) 49) 44) 91)))


