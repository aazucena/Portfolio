#lang racket
;1. (3 marks) You are given a list whose elements are integer numbers. One example is (0 0 1 3 5).
;Write a function, called trimming, to delete all the leading zeros.
;For the example, the result is (1 3 5)

(define (trimming list)
  (if (null? list)
       '()
       (if (eqv? 0 (car list))
           (trimming (cdr list))
           list
           )
       )
  )



;2. (3 marks) You are given a list whose elements are integer numbers.
;One example is (0 0 1 3 0 5 0). Write a function, called trimming2, to delete all the zeros in the list.
;For the example, the result is (1 3 5).

(define (trimming2 list)
           (cond
             ((null? list) '())
             ((eqv? 0 (car list))
              (trimming2 (cdr list))
              )
             (else
              (cons(car list) (trimming2 (cdr list))
                    )
              )
             )
  )



;3. (5 marks) You are given a list of elements, each of which could be a list.
;One example is ((a b) e (c d)).
;Create a function, called myreverse, to reverse the elements recursively.
;For the example, the result is ((d c) e (b a)).
;You are not allowed to use the built-in function reverse in Scheme.

(define (myreverse list)
  (if (null? list)
      '()
      (append (myreverse (cdr list)) (cons (car list) '()))
      )
  )


;4. (4 marks) You are given a list of elements, each of which could be a list.
;One example is ((a b) e (c d)). Create a function, called recslen, to count the elements recursively and report the total number of the elements in the list.
;For the example, the result is 5.
;You are not allowed to use the built-in function length.

(define (recslen list)
    (if (null? list)
        0
        (if (pair? (car list))
             (+ (recslen (car list))(recslen (cdr list)))
             (+ 1 (recslen (cdr list)))
            )
     )
  )
