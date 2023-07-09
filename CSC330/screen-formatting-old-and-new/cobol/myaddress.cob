       identification division.
       program-id.
       myaddress.
       author.
           Syed A. Saadat.
       date-written.
           October 12, 2021.

       environment division.
       input-output section.
       file-control.
           select line-out-file assign to s-output.

       data division.
       file section.
       fd line-out-file
           label records are omitted.
       01 line-record picture x(26).

       procedure division.
       A000-write-name-and-address.
           open output line-out-file.
           move 'Syed A. Saadat' to line-record.
           write line-record before 1.
           display line-record.
           move '31415 Home Drive' to line-record.
           write line-record before 1.
           display line-record.
           move 'Atlanta, GA' to line-record.
           write line-record before 1.
           display line-record.
           move 'USA' to line-record.
           write line-record before 1.
           close line-out-file.
           display line-record.
           stop run.
