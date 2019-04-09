; Ian Braudaway
; CS403 NAND Gate

(include "queue.scm")
(include "gates.scm")

(define (nand-gate a1 a2 output) 
	(define (nand-action-procedure)
		(let ((new-value
			(logical-not (logical-and (get-signal a1) (get-signal a2)))))
		 (after-delay 6
	 				(lambda ()
	 					(set-signal! output new-value)))))
	(add-action! a1 nand-action-procedure)
	(add-action! a2 nand-action-procedure)
	'ok)
