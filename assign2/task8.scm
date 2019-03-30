; Ian Braudaway
; CS403 Assign 2, Task 8

(define (insertBST tree value)
	(cond
		(())

		)
	(newBST tree)
	)

(define (node value left right)
	(define (display) (print value))
	this
	)

(define (newBST value)
	(node value nil nil)
	)

(define (displayBST root)
	(define (iter root indent)
		(if (valid? root)
			(begin
				(iter (root'right) (string+ indent "    "))
				(print indent)
				((root'display))
				(println)
				(iter (root'left) (string+ indent "    "))
				)
			)
		)
	(iter root "")
	)

(define (main)
	(setPort (open (getElement ScamArgs 1) 'read))
	(define env this)
	(define (iter expr)
		(if (not (eof?)) (begin (eval expr env) (iter (readExpr)))))
	(iter (readExpr))
	)
