program help

    implicit none
    ! Variables used to set up prime numbers
    integer :: userInput, arraySize
    integer, allocatable, dimension(:) :: primeNums
    integer, external :: CountPrime
    logical, external :: IsPrime
    integer :: arrayIndex
    ! Variables used to find the lowest norm of the triple sums
    integer :: tripletSum, i, l, r
    integer, dimension(3) :: triplet
    real, external :: NormOf
    real :: norm
   
    print *, "Enter an odd number greater than 7 : "
    read*, userInput

    if((userInput .gt. 7) .and. (modulo(userInput, 2) .eq. 1)) then
        arraySize = CountPrime(userInput)
        allocate(primeNums(arraySize))
    
    ! STORE PRIME NUMBERS
    arrayIndex = 1
    do i = 0, userInput
        if(IsPrime(i)) then
            primeNums(arrayIndex) = i
            arrayIndex = arrayIndex + 1
        end if
    end do
   
    ! FIND MINIMUN NORM OF TRIPLETS
    norm = 9999
    l = 1
    r = 1
    do i = 1, (arraySize - 1)
        l = i + 1
        r = arraySize
        !tripletSum = primeNums(i) + primeNums(l) + primeNums(r)
        do while (l + 1 .lt. r)
            if (primeNums(i) + primeNums(l) + primeNums(r) .eq. userInput) then
                if ((NormOf(real(primeNums(i), 4), real(primeNums(l), 4), real(primeNums(r), 4))) .le. norm) then
                    norm = NormOf(real(primeNums(i), 4), real(primeNums(l), 4), real(primeNums(r), 4))
                    triplet(1) = primeNums(i)
                    triplet(2) = primeNums(l)
                    triplet(3) = primeNums(r)
                end if
            l = l + 1
            r = r - 1
            else if (primeNums(i) + primeNums(l) + primeNums(r) .le. norm) then
                l = l + 1
            else
                r = r - 1
            end if
        end do
    end do

    print*, userInput, " : ", "(", triplet(1), "," , triplet(2), "," , triplet(3), ")"
   
    else 
    
    print *, "Please enter an odd integer greater than 7"
    
    end if
    
   
end program

! Counts the number of prime numbers between 1 and user inpout
! This is used to set the array of prime number's size
integer function CountPrime(num) result(counter)
    integer, intent (in) :: num
    logical, external :: IsPrime
    counter = 0
    do i = 1, (num - 1)
        if(IsPrime(i)) then
            counter = counter + 1
        end if
    end do
end function

! Checks if a given number is prime
logical function IsPrime(num) result(prime)
    integer, intent (in) :: num
    prime = .true.
    do i = 2, (num - 1)
        if(modulo(num,i) .eq. 0) then
            prime = .false.
            exit
        end if
    end do
end function

! Finds the norm of 3 given numbers
real function NormOf(i, j, k) result(norm)
    real, intent (in) :: i, j, k
    norm = SQRT((i*i) + (j*j) + (k*k))
end function
