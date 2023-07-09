
! Count the total number of numbers for a number in the collatz conjecture

program collatz

implicit none

integer :: i, counter = 0
integer(kind = 16) :: j ,CountCollatz, seqCount
print *, "Enter a number : "
read *, i

do while(i .ne. 1)
    print *, i
    if(modulo(i, 2) .eq. 0) then
        i = i / 2
    else
        i = i * 3 + 1
    end if
    counter = counter + 1
end do

print *, i
print *, "Numbers in the Collatz Sequence : ", counter

j = 11

seqCount = CountCollatz(j)

print *, "Numbers in the Collatz Sequence : ", seqCount

end program collatz


integer(kind = 16) function CountCollatz(i)
      implicit none
      integer(kind = 16) :: i, counter
      counter = 0
      do while(i .ne. 1)
            if(modulo(i, 2) .eq. 0) then
                  i = i / 2
            else
                  i = i * 3 + 1
            end if
            counter = counter + 1
      end do
      CountCollatz = counter
end function