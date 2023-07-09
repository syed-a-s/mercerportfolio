program goldbach
      
end program

integer function CountPrime(num) result(counter)
      implicit none
      
      integer, intent (in) :: num 
      logical, external :: IsPrime
      counter = 0
      
      do i = 1, (num - 1)
            if(IsPrime(i)) then
                  counter = counter + 1
            end if
      end do
      
end function 

logical function IsPrime(num) result(prime)

      integer, intent (in) :: num
      prime = .true.

      do i = 2, (num - 1)

            if( modulo(num, i) .eq. 0 ) then 
                  prime = .false.
                  exit
            end if 

      end do
      
end function

subroutine FindMinTriplet(primeNums, arraySize, userInput)
        
        integer, dimension(:), intent (in) :: primeNums
        integer, intent (in) :: arraySize, userInput

        real, external :: NormOf
        integer :: l, r, tripletSum
        integer, dimension(3) :: triplet
        real :: norm
        norm = 9999

        do i = 1, (arraySize - 2)
        l = i + 1 
        r = arraySize - 1
        do  (l .lt. r)
         if(tripletSum .eq. userInput)  then
          if((NormOf(primeNum(i),primeNums(l),primeNums(r)) .le. norm) then
           norm = NormOf(primeNums(i), primeNums(l), primeNums
           triplet(1) = primeNums(i)
           triplet(2) = primeNums(l)
           triplet(3) = primeNums(r) 
         end if
         l = l + 1
         r = r - 1        
         else if (tripletSum .lt. userInput) then
         l = l + 1
         else
         r = r - 1
         end if
        enddo

        end do

        print *, userInput, " : ", "(", triplet(1), ",", triplet(2), ",",
        triplet(3), ")"

end subroutine  

real function NormOf(i, j, k) result(norm)

        real, intent (in) :: i, j, k
        norm = SQRT((i*i) + (j*j) + (k*k))

end function 
