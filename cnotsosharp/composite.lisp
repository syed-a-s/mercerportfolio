#!/usr/bin/sbcl --script

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Authors:     CNotSo# Team
; Course:      CSC 330: Organization of Programming Languages (Fall 2021)
; Instructor:  Dr. A. Pounds
;
; Description: Collapse Group Project in Lisp.
;
; Compilation: chmod u+x collapse.lisp
;              ./collapse.lisp [num1] [num2]
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function:
;
; Pre: Takes an integer n.
;
; Pos: Returns a boolean denoting if the number is prime.
;

(defun is-prime (n)
  (declare (fixnum n))
  (cond ((< n 4) (or (= n 2) (= n 3)))
        ((or (zerop (mod n 2)) (zerop (mod n 3))) nil)
          (t (loop for a of-type fixnum from 5 to (floor (sqrt n)) by 6
                never (or (zerop (mod n a)) (zerop (mod n (+ a 2))))))))

                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function:
;
; Pre: Takes an integer n.
;
; Pos: Returns the prime factorization of the number recursively.
;

(defun prime-factors ( inNum )

  ( let 
      (
        ( sum 0 )            ; Local variables.
        ( factor 0 )
        ( a_count 0)
        ( uniqueCount 0 )
        ( checkNum 3 )
        ( numHold 0 )
        ( i 0 )
      ) 

      ( setf sum 0 )
      ( setf factor 0 )
      ( setf a_count 0 )
      ( setf numHold inNum )
    
      ( loop while ( equal ( mod numHold 2 ) 0 )        ; Checking the number of 2's in the
                                                   ; factor tree.
        do( 
          progn 
          ( setf numHold ( floor numHold 2 ) )
          ( incf a_count )
          ( setf sum ( + sum 2 ) )
        )
        
      ) 
          
      ( when ( > a_count 1 )                       ; Returning zero if there are more than
                                                   ; 2 middle factors.
        ( return-from prime-factors 0 )
        
      )

      ( setq uniqueCount 0 )
      ( setq numHold inNum )
      ( setq i 3 )
      
      ( loop while ( <= ( * i i ) inNum )
      
        do (
      
           progn
            (loop while ( equal ( mod numHold i ) 0)
              do( progn
                    ( setf numHold ( floor numHold i ) )
                    ( incf a_count )
                    ( setf sum (+ sum i ) )
                    ( setf uniqueCount ( + uniqueCount 1 ) )
                )
            )
        
            ( when ( or ( > a_count 2 ) ( > uniqueCount 1 ) )
            
              ( return-from prime-factors 0 )
            )
            
            ( setq uniqueCount 0 )
            ( setq i ( + i 2 ) )            
          )
      )

      (return-from prime-factors ( + ( floor inNum sum ) sum ) )

  ) 
) 
           
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function:
;
; Pre: Takes an integer n.
;
; Pos: Performs the total collapse of a number.
;
           
(defun collapse (input)

	(let ((num input) (sum 0) (ans 0))

    ;;if single digit
	  (if (equal (mod num 10) num)

      ;; if clause
	    ( progn
		    (setq ans num)
		    (return-from collapse ans)

	    )
         
      ;;else statement
	    ( progn 

	      ;; Break down the number.
	      ( loop while (/= num 0)

			    do(setq sum (+ sum (mod num 10)))
			    do(setq num (floor num 10))

		    )
		    (setq ans (collapse sum) ) 
	    )
         
    )
    
	)
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function:
;
; Pre: No inputs from the arguments.
;
; Pos: Returns a vector with the command line arguments.
;

( defun argv ()

  (or
   #+clisp (ext:argv)           ; This function handles command-line arguments
   #+sbcl sb-ext:*posix-argv*   ; from both Common Lisp and SBCL.
  nil)

)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Function:
;
; Pre: Takes an integer n, with 0 <= n < 10.
;
; Pos: Returns the representation of the digit in Roman numerals.
;

( defun roman ( num ) 

  (cond (
          ( equal num 0 )                         ; Case for num = 0.

          ( write-string "N" )
        )
        ;;;;;;;;;;
        ( 
          ( > num 8 )                             ; Case for num > 8.

          ( progn
            ( loop for i from 1 to ( - 10 num )   ; Lisp does not demand declaring i before
              do( write-string "I" )              ; the the for loop.
            )
            ( write-string "X" )
          )          
        )
        ;;;;;;;;;;
        ( 
          ( > num 5 )                             ; Case for num > 5.

          ( progn
            ( write-string "V" )
            ( loop for i from 1 to ( - num 5 )
              do( write-string "I" )
            )
          )          
        )
        ;;;;;;;;;;
        ( 
          ( equal num 5 )                         ; Case for num = 5.

          ( write-string "V" )          
        )
        ;;;;;;;;;;
        (
          ( equal num 4 )                         ; Case for num = 4.
          
          ( write-string "IV" )
        )
        ;;;;;;;;;;
        (           
          t                                       ; Case for num <= 3. 

          ( progn
            ( loop for i from 1 to num
              do( write-string "I" )
            )
          )          
        )
        ;;;;;;;;;;
  )
  ( write-line "" )  ; Writing new line.

)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Main function:
;

( defvar num1 )        ; Declaring program variables.
( defvar num2 )
( defvar args )         
( defvar factor )
( defvar collapse )
( defvar totalSum )
( defvar checkNum )
( defvar countValids )
( defvar factHold )

( setq args ( argv ) )  ; Storing command line arguments into 
                        ; args.

( setq num1 ( parse-integer ( nth 1 args ) ) )  ; Initializing the two integers.
( setq num2 ( parse-integer ( nth 2 args ) ) ) 

( setq totalSum 0 )        ; Initializing variables to store the total sum
( setq countValids 0 )     ; and number of valid numbers.

( setq checkNum num1 )     ; Initializing variable to check the number.

( loop while ( <= checkNum num2 )

  do( cond (
              ( not ( is-prime checkNum ) )

              ( progn
                ( setq factHold ( prime-factors checkNum ) ) 
                
                ( setq totalSum ( + totalSum factHold ) )
                
                ( if ( /= factHold 0 )
                  ( incf countValids )  
                )
              )
           )
    )

  do( incf checkNum )    ; Incrementing the number to check.

)

;( write-line "Collapse Project in Lisp" )
;( write-line " " )

( write-string "Count = " )        ; Printing count.
( write countValids )
( write-line "" )

( write-string "Sum = " )          ; Printing sum.
( write totalSum )
( write-line "" )

( write-string "Collapse = " )     ; Computing collapse.
( write ( collapse totalSum ) )
( write-line "" )

( write-string "Roman = " )        ; Printing Roman numerals.
( roman ( collapse totalSum ) ) 
( write-line "" )

( write-line "--Hail Caesar!" )    ; Hail Caesar?
