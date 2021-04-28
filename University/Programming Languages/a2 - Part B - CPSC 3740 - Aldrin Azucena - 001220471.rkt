;Assignment 2 - Part B [Aldrin Azucena - 01220471]

#lang racket

;Answer to (1)
(define (ackermann m n)
  (cond
    [(equal? m 0) (+ n 1)]
    [(equal? n 0) (ackermann (- m 1) 1)]
    [else (ackermann (- m 1) (ackermann m (- n 1)))]
    )
)

;Answer to (2)

(define x
  (lambda (atree)
    (if (pair? atree)
        (if (null? (cdr atree))
            1(+
               (+ 1
                  (x (car (cdr atree)))
                )
               (x (car (cdr (cdr atree))))
              )
         )
     0)
   )
)

; A: The purpose of this function is counting nodes with a left and right child in COMPLETE binary tree
;    and outputs the number of nodes with a pair. The procedure of the function goes like this:
;      1. Check if there are any pair in the tree
;         a. If it doesn't, it will return 0
;         b. Else, continues to count the nodes with a pair
;      2. Checks first if the list is not null
;      3. Continues to count and the pair nodes available
;      4. Go recursive, and do it again with a new function until
;         it can't find any root nodes with a left AND right child

;Answer to (3)

(define preorder
  (let ((visited '()))
    (lambda (bst)
      (if (pair? bst)
          (if (null? (cdr bst))
              (if (null? visited)
                  (display " ")
                  (display (car bst))
                  )
              (let* ([left (cadr bst)]
                     [right (caddr bst)])
                (display (car bst))
                (display " ")
                (set! visited (append  `( ,(reverse bst)) visited))
                (if (equal? (cadr (reverse (car visited))) bst)
                    (set! visited (cdr visited))
                    (preorder left) ;left child
                    )
                (display " ")
                (if (equal? (caddr (reverse (car visited))) bst)
                    (set! visited (cdr visited))
                    (preorder right) ;right child
                    )
                (if (empty? visited)
                    (display " ")
                    (set! visited (cdr visited))
                    )
                )
              )
          (display "Your BST isn't complete")
          )
      )
    )
  )