
! Find largest sequence number in the given range

program highc

      implicit none
      integer(kind = 16) :: min, max, LargestCollatz
      
      print*, "Minimun : " 
      read*, min
      print*, "Maximum : "
      read*, max
      
      call FindLargest(min, max)

end program

! Recursively find the biggest number in the sequence of a given number
recursive integer(kind = 16) function LargestCollatz(n) result(max)

      implicit none
      integer(kind = 16) :: n, nItself
      max = 0

      if(n .gt. max) then
            max = n
      end if
                  
      if(n .eq. 1) then
            return 
      end if  

      if(modulo(n, 2) .eq. 0) then
            n = LargestCollatz(n / 2)
      else
            n = LargestCollatz(n * 3 + 1)
      end if
      
end function

! Will print out the biggest sequence number within the range
subroutine FindLargest(bot, top)

      implicit none
      integer(kind = 16) :: maxSeq, i, j, bot, top, LargestCollatz
      
      maxSeq = 0
      
      do i = bot, top
            j = i
            if(LargestCollatz(j) .gt. maxSeq) then
                  maxSeq = LargestCollatz(j)
            end if
      end do
      
      print *, maxSeq
      
end subroutine

            
            
            
            
            
            
            
            
            
            
            