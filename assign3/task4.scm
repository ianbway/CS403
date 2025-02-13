; Ian Braudaway
; CS403 Assign 3, Task 4

(include "queue.scm")
(include "gates.scm")
(include "nand.scm")

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
	(nand-gate input input output))

(define (and-gate a1 a2 output) 
	(let ((out (make-wire)))
		(nand-gate a1 a2 out)
		(inverter out output)
		)
	)

(define (or-gate a1 a2 output)
	(let ((out1 (make-wire)) 
		  (out2 (make-wire)))
		(nand-gate a1 a1 out1)
		(nand-gate a2 a2 out2)
		(nand-gate out1 out2 output)
		)

	)

(define (nor-gate a1 a2 output)
	(let ((out (make-wire)))
		(or-gate a1 a2 out)
		(inverter out output)
		)

	)

(define (xor-gate a1 a2 output)
	(let ((out1 (make-wire)) (out2 (make-wire)) (out3 (make-wire)))
		(nand-gate a1 a2 out1)
		(nand-gate a1 out1 out2)
		(nand-gate a2 out1 out3)
		(nand-gate out2 out3 output)
		)
	)

(define (xnor-gate a1 a2 output)
	(let ((out (make-wire)))
		(xor-gate a1 a2 out)
		(inverter out output)
		)
	)

(define the-agenda (make-agenda))

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 1)
; (propagate)
; (set-signal! input-2 1)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 0)
; (propagate)
; (set-signal! input-2 0)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 0)
; (propagate)
; (set-signal! input-2 1)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 1)
; (propagate)
; (set-signal! input-2 0)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (and-gate a b out)
; (print "\n---------------")
; (print "\n0 AND 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 AND 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 AND 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 AND 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (or-gate a b out)
; (print "\n---------------")
; (print "\n0 OR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 OR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 OR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 OR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (xor-gate a b out)
; (print "\n---------------")
; (print "\n0 XOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 XOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (nor-gate a b out)
; (print "\n---------------")
; (print "\n0 NOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 NOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 NOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 NOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (xnor-gate a b out)
; (print "\n---------------")
; (print "\n0 XNOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 XNOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XNOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XNOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 1)
; (propagate)
; (set-signal! input-2 1)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 0)
; (propagate)
; (set-signal! input-2 0)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 0)
; (propagate)
; (set-signal! input-2 1)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define input-1 (make-wire))
; (define input-2 (make-wire))
; (define sum (make-wire))
; (define carry (make-wire))
; (probe 'sum sum)
; (probe 'carry carry)
; (half-adder input-1 input-2 sum carry)
; (set-signal! input-1 1)
; (propagate)
; (set-signal! input-2 0)
; (propagate)
; (print "\nsum is " (get-signal sum))
; (print "\ncarry is " (get-signal carry))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (and-gate a b out)
; (print "\n---------------")
; (print "\n0 AND 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 AND 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 AND 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 AND 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (or-gate a b out)
; (print "\n---------------")
; (print "\n0 OR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 OR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 OR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 OR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (xor-gate a b out)
; (print "\n---------------")
; (print "\n0 XOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 XOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (nor-gate a b out)
; (print "\n---------------")
; (print "\n0 NOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 NOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 NOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 NOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)

; (define a (make-wire))
; (define b (make-wire))
; (define out (make-wire))
; (probe 'out out)
; (xnor-gate a b out)
; (print "\n---------------")
; (print "\n0 XNOR 0")
; (print "\n---------------")
; (set-signal! a 0)
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n0 XNOR 1")
; (print "\n---------------")
; (set-signal! b 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XNOR 1")
; (print "\n---------------")
; (set-signal! a 1)
; (propagate)
; (print "\noutput is " (get-signal out))
; (print "\n---------------")
; (print "\n1 XNOR 0")
; (print "\n---------------")
; (set-signal! b 0)
; (propagate)
; (print "\noutput is " (get-signal out))
; (println)
