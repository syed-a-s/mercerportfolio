
! Count the total number of numbers for a number in the collatz conjecture

program collatz

implicit none

integer :: i, counter = 1
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

end program collatz