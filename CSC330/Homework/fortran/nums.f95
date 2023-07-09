program nums

        integer :: n
        logical, external :: isPrime
        print *, "Enter a number  :"
        read *, n 
        call printPrime(n)        

end program

subroutine printPrime(n)

        integer, intent(in) :: n
        logical, external :: isPrime
 
        print *, "All prime numbers from the range 1 to ", n, " are:"

        do i = 1, n
        
                if(isPrime(i)) then
                        print *, i
                end if

        end do

end subroutine 

logical function isPrime(num) result(bool)

        integer, intent (in) :: num  ! input
        bool = .true.

        do i = 2, (num - 1)

                if( modulo(num, i) .eq. 0 ) then 
                        bool = .false.
                        exit
                end if 

        end do

end function 
