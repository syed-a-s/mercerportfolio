#!/usr/bin/sbcl --script

(defun CountCollatz(n)
    (let
        (
            (counter 0)
        )
        (if (= n 1)
           
                1

                (if (= (mod n 2) 0)
                
                    ;(setf counter (+ (+ counter (CountCollatz (* n 2)) 1)))
                    (setf n (/ n 2))
                    (setf n (+ (* n 3) 1))
                    ;(setf counter (+ (+ counter (CountCollatz (/ n 3)) 1)))
                
                )
        
        )

        ;(Ret counter)
    )
)
   
; Helper function that helps functions return data
(defun Ret (obj)
    obj
)

; main function

(write (CountCollatz 97))
(terpri)

