#!/usr/bin/sbcl --script

;;; Want to avoid compiler warnings, so add defvar for these variables
(defvar fl)
(defvar line)
(defvar numLines 1)

(setq fl (open "/pub/pounds/CSC330/translations/KJV.txt" ) )

      (loop for line = (read-line fl nil :eof) ; stream, no error, :eof value
                  until (eq line :eof)
                        do (write-line line)
		        (incf numLines)		  			
		       
      )

      (print numLines)

(close fl)
