!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!
! Main function
!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

program test

character(1000) :: strNum1
character(1000) :: strNum2


integer*8 :: num1, num2, factor, collapse, totalSum, checkNum, count, factHold
logical :: isPrime

call get_command_argument( 1, strNum1 )     ! Taking command-line arguments as strings.
call get_command_argument( 2, strNum2 )

read( strNum1, * ) num1                     ! Converting strings to ints.
read( strNum2, * ) num2

totalSum = 0
count = 0

checkNum = num1
do while (checkNum <= num2) ! Run within the bounds

    ! Prime numbers are not composite by definition so ignore them
    if (.not. isPrime(checkNum)) then
        factHold = factor(checkNum) ! get the sum of the factors
        totalSum = totalSum + factHold ! Add the sum to the totalSums
        
        ! If the factor sum wasn't 0 then increment the number of valid nubers
        if (factHold /= 0) then
            count = count + int(1,8)
        end if
    end if

    checkNum = checkNum + int(1,8) ! Increment the number to check
end do



!! Print output
print*, "Count:    ", count
print*, "Sum:      ", totalSum
print*, "Collapse: ", collapse(totalSum)
write(*,'(A)', advance = 'no') "Roman:   "
call roman(collapse(totalSum))

print*, "  --Hail Caesar!"

contains

!!  Takes in a number and prints the corresponding roman numeral
subroutine roman(num)
integer*8, intent(in) :: num

        if(num==0) then ! If the number is 0
                print*, "N"
        elseif (num > 8) then ! If the number is greater than 8
                do i = 1, 10-num
                        write(*,'(A)', advance = "no") "I"
                end do
                write(*, '(A)', advance = 'no') "X"
        elseif (num > 5) then ! if the number is between 5-8
                write(*, '(A)', advance = 'no') "V"
                do i = 1, num-5
                        write(*, '(A)', advance = 'no') "I"
                end do
        elseif (num > 3) then ! If the number is 3 or 4
                if (num == 4) then
                        write(*,'(A)',advance = 'no') "I"
                end if
                write (*,'(A)', advance = "no") "V"
        else ! If the number is 1 or 2
                do i = 1, num
                        write(*,'(A)', advance = "no") "I"
                end do
        end if
        print *, ""
end subroutine roman


end program test

!Takes a number and returns a bollean if it is
!prime or not
logical function isPrime(number)
    integer*8 :: number, counter
    !integer :: counter

    isPrime = .true.

    if (mod(number, 2) == 0 .and. number /= 2) then ! Return false if the number is even and not 2
        isPrime = .false.
    else
        counter = 3                     ! Start checking at 3 | auto verifies 1 and 2
        do while(counter**2 <= number)  ! Uses the square to decrease the number of checks
            if (mod(number, counter) == 0) then ! If a number can divide the inNumber, return false
                isPrime = .false.
                EXIT
            end if
            counter = counter + int(2,8) ! Skip over even numbers
        end do
    end if

end function isPrime



!! Takes in a number and breaks it down into its components and adds them,
!! recursively calls istelf if the sum is not a single digit

recursive integer*8 function collapse(input) result (ans)
integer*8, intent (in) :: input
integer*8 :: sum, num

num = input

    if (mod(num, 10) == num) then !Return the input if the number is a single digit
        ans = num
        return
    else
        sum = 0
        do while (num /= 0) ! Break down the number digit by digit
            sum = sum + int(mod(num,10),8) ! Add the digit to the sum
            num = num / int(10,8)
        end do
        ans = collapse(sum) !Recursive call
    end if
end function collapse



!! Takes in a number an computes the sum of its middle factors
!! (factors other than 1 and itself)
!! 
!! Returns sum of the middle factors of there are only two 
!! and they are unique
!!
!! Otherwise returns 0 
!!
!! Input : integer*8
!! Output : integer*8
!!
integer*8 function factor(inNum)

    integer*8, intent (in) :: inNum
    integer*8 :: numHold, sum, numCheck
    integer :: count, uniqueCount


    sum = 0
    factor = 0
    count = 0

    !! Check the number of 2's in the factor tree
    numHold = inNum
    do while (mod(numHold, 2) == 0)
        numHold = int(numHold / int(2,8), 8)
        count = count + 1   ! keep track of factor count
        sum = sum + int(2, 8)       !Add 2 two the sum of the middle factors
    end do

    !! Returns 0 if there are more than 2 middle factors
    if (count > 1) then
        return
    end if
    
    
    uniqueCount = 0
    numHold = inNum
    numCheck = 3

    !! Using the square of the variable 'i' allows
    !! for significatly shortening the run time
    !! as a number times itself denotes the 'middle'
    !! of possible products
    do while (numCheck*numCheck <= inNum)
        !! See how may times variable number 'i' 
        !! can divide the input number
        do while (mod(numHold, numCheck) == 0)
            numHold = int(numHold / numCheck, 8)
            count = count + 1             ! Track numer of factors
            sum = sum + numCheck                ! Add number to sum of factors
            uniqueCount = uniqueCount + 1 !Track if the number is unique
        end do

        !! Return 0 if there are more than 2 factors
        !! or if there are more than 1 of the factor
        if (count > 2 .or. uniqueCount > 1) then
            return
        end if

        uniqueCount = 0
        numCheck = numCheck + int(2,8)
    end do

    !! If code gets this far, there has only been one factor
    !! Add it's complementary factor to the sum and return it
    
    factor = sum + (inNum / sum)
    

end function factor
