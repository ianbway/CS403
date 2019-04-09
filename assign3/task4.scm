; Ian Braudaway
; CS403 Assign 3, Task 4

(include "queue.scm")
(include "gates.scm")
(include "nand.scm")

(define inverter-delay 2)
(define and-gate-delay 3)
(define or-gate-delay 5)

(define (half-adder a b s c)
  (let ((d (make-wire)) (e (make-wire)))
    (or-gate a b d)
    (and-gate a b c)
    (inverter c e)
    (and-gate d e s)
    'ok))

(define (full-adder a b c-in sum c-out)
  (let ((s (make-wire))
        (c1 (make-wire))
        (c2 (make-wire)))
    (half-adder b c-in s c1)
    (half-adder a s sum c2)
    (or-gate c1 c2 c-out)
    'ok))

(define (inverter input output)
	(define (invert-input)
		(let ((new-value (logical-not (get-signal input))))
			(after-delay inverter-delay
					(lambda ()
						(set-signal! output new-value)))))
	(add-action! input invert-input)
	'ok)

(define (and-gate a1 a2 output) 
	(define (and-action-procedure)
		(let ((new-value
			(logical-not (logical-and (get-signal a1) (get-signal a2)))))
		 (after-delay and-gate-delay
	 				(lambda ()
	 					(set-signal! output new-value)))))
	(add-action! a1 and-action-procedure)
	(add-action! a2 and-action-procedure)
	'ok)

(define (or-gate a1 a2 output)


	)

(define (nor-gate)


	)

(define (xor-gate)


	)

(define (xnor-gate)


	)


(define the-agenda (make-agenda))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
