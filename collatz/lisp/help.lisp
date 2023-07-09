#!/usr/bin/sbcl --script
; Will find the smallest sequence length and replate it with a number's current calculated sequence length
(defun ReplaceLeastSeqs (arr info arr2 info2)
    (let
        (
            (check 0)
        )

    ; If the current sequence count is lower than the smallest sequence stored, then it 
    ; can't be bigger than the rest. So skip and return the array
    (if (> (aref arr 0) info) (setf check 1))

    ; Otherwise, check all the elements in the array
    (if (= check 0)
        (progn
            (loop for i from 0 to 9
                ; If the sequence length is the same as the one stored, skip
                do(if (= (aref arr i) info) (setf check 1))
                ; If the stored sequence length is greater than the sequence length,
                ; then it must be placed before
                do(if (and (> (aref arr i) info) (= check 0))
                    (progn
                        (setf check 1)
                        (setf arr (ShiftLeft arr (- i 1) info))
                    )
                )
            )
        )
    )

    ; If here, the current sequence count is larger than all the stored sequences,
    ; so the last index must be the right spot for the current sequence count
    (if (= check 0) (setf arr (ShiftLeft arr 9 info)))

    ; return the new sequences array
    (Ret arr)
    )
)

; Same algorithm as ReplaceLeastNum. This function returns a new nums array
; in relation to the sequence array
(defun ReplaceLeastNums (arr info arr2 info2)
    (let
        (
            (check 0)
        )

    (if (> (aref arr 0) info) (setf check 1))

    (if (= check 0)
        (progn
            (loop for i from 0 to 9
                do(if (= (aref arr i) info) (setf check 1))
                do(if (and (> (aref arr i) info) (= check 0))
                    (progn
                        ; unlike before, update the nums array accordingly to 
                        ; the sequences array
                        (setf check 1)
                        (setf arr2 (ShiftLeft arr2 (- i 1) info2))
                    )
                )
            )
        )
    )

    ; again, update the nums array according the sequences array
    (if (= check 0) (setf arr2 (ShiftLeft arr2 9 info2)))

    ; return the new nums array
    (Ret arr2)
    )
)

; Counts the sequence length of a number iteratively
(defun CountCollatz(n)
    (let
        (
            (counter 0)
        )
        (loop while (> n 1)
            do(if (= (mod n 2) 0) 
                (setf n (/ n 2))
                (setf n (+ (* n 3) 1))
            )
            do(incf counter)
        )
        (Ret counter)
    )
)
; Shift array down accordingly 
(defun ShiftLeft(arr pos info1)
    (let 
        (
            ; variables
            (i 0)
            (posHold 0)
            (newArr (make-array '(10)))
        )
        ; set the top most elements to the desired position plus one
        ; elements
        (setf i 9)
        (loop while (> i pos)
            do(setf (aref newArr i) (aref arr i))
            do(decf i)
        )

        ; set the new info at the desired position
        (setf (aref newArr pos) info1)
        
        ; shift the array down accordingly 
        (setf i (- pos 1))
        (loop while (>= i 0)
            do(setf (aref newArr i) (aref arr (+ i 1)))
            do(decf i)
        )
        (Ret newArr)
    )
)

; Sort the nums array from least to greatest
(defun SortNums(nums sequences)
    (let
        (
            (n 10)
            (min_ind 0)
            (temp 0)
        )

        (loop for i from 0 to (- n 1)
            do(setf min_ind i)
            (loop for j from (+ i 1) to (- n 1)
                do(if (< (aref nums j) (aref nums min_ind))
                    (setf min_ind j)
                )
            )
            do(setf temp (aref nums min_ind))
            do(setf (aref nums min_ind) (aref nums i))
            do(setf (aref nums i) temp)

            do(setf temp (aref sequences min_ind))
            do(setf (aref sequences min_ind) (aref sequences i))
            do(setf (aref sequences i) temp)
        )
        (Ret nums)
    )
)

; Sort the sequence array in relation to the nums array
(defun SortSeq(nums sequences)
    (let
        (
            (n 10)
            (min_ind 0)
            (temp 0)
        )

        (loop for i from 0 to (- n 1)
            do(setf min_ind i)
            (loop for j from (+ i 1) to (- n 1)
                do(if (< (aref nums j) (aref nums min_ind))
                    (setf min_ind j)
                )
            )
            do(setf temp (aref sequences min_ind))
            do(setf (aref sequences min_ind) (aref sequences i))
            do(setf (aref sequences i) temp)
        )
        (Ret sequences)
    )
)

; Helper function that helps functions return data
(defun Ret (obj)
    obj
)

(defun argv ()
    (or
        #+clisp (ext:argv)           ; This function handles command-line arguments
        #+sbcl sb-ext:*posix-argv*   ; from both Common Lisp and SBCL.
    nil)
)

; Print array
(defun PrintArray(arr arr2 i)
    (loop while (> i 0)
        do(decf i)
        do(write (aref arr2 i))
        do(write-string "     ")
        do(write (aref arr i))
        do(terpri)
    )
)

;;;;;;;;;;;; Main Funciton ;;;;;;;;;;;;

(defvar sequences (make-array '(10)))
(defvar nums (make-array '(10)))
(defvar args)
(defvar r)

(setf args (argv))
(setf r (parse-integer (nth 1 args)))

; First 10 sequences are set by default
(setf (aref sequences 0) 0)
(setf (aref sequences 1) 1)
(setf (aref sequences 2) 2)
(setf (aref sequences 3) 3)
(setf (aref sequences 4) 5)
(setf (aref sequences 5) 6)
(setf (aref sequences 6) 7)
(setf (aref sequences 7) 8)
(setf (aref sequences 8) 16)
(setf (aref sequences 9) 19)

(setf (aref nums 0) 1)
(setf (aref nums 1) 2)
(setf (aref nums 2) 4)
(setf (aref nums 3) 8)
(setf (aref nums 4) 5)
(setf (aref nums 5) 10)
(setf (aref nums 6) 3)
(setf (aref nums 7) 6)
(setf (aref nums 8) 7)
(setf (aref nums 9) 9)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(loop for i from 11 to r
    do(setf nums (ReplaceLeastNums sequences (CountCollatz (+ i 1)) nums (+ i 1)))
    do(setf sequences  (ReplaceLeastSeqs sequences (CountCollatz (+ i 1)) nums (+ i 1)))
)

(write-string "Sorted based on sequence length")
(terpri)
(PrintArray sequences nums 10)

; (setf sequences(SortSeq nums sequences))
(setf nums (SortNums nums sequences))

(write-string "Sorted based on integer size")
(terpri)
(PrintArray sequences nums 10)