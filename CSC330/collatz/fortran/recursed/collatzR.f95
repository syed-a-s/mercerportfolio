
! Find Top 10 largest Collatz sequence lengths with the smallest integers

program collatz

      implicit none
      integer(kind = 16) :: i, j, r, seqCount, currentNum, CountCollatz
      integer(kind = 16), dimension(10) :: sequences, nums

      print*, "Enter a number greater than 10 : "
      read*, r
      
      ! First 10 sequences are set by default
      sequences = (/0, 1, 2, 3, 5, 6, 7, 8, 16, 19/)
      nums = (/1, 2, 4, 8, 5, 10, 3, 6, 7, 9/)
      
      ! Find top smallest integers with the largest sequences
      do i = 11, r
            j = i
            seqCount = CountCollatz(j)
            currentNum = i
            call ReplaceLeast(sequences, nums, seqCount, currentNum)
      end do
      
      print*, "Sorted based on sequence length"
      call PrintArrays(sequences, nums)
      
      call SortArray(nums, sequences)
      
      print*, "Sorted based on integer size"
      call PrintArrays(sequences, nums)
      
end program 

! Count sequence in Collatz Conjecture recursively
recursive integer(kind = 16) function CountCollatz(n) result(counter)

      implicit none
      integer(kind = 16) :: n
      counter = 0
      if(n .eq. 1) then
            counter = counter + 0
            return
      end if
      if(modulo(n, 2) .eq. 0) then
            counter = counter + CountCollatz(n / 2) + 1
      else
            counter = counter + CountCollatz(n * 3 + 1) + 1
      end if
      
end function

! Will find the smallest sequence length and replace it with a number's current calculated sequence length
subroutine ReplaceLeast(sequences, nums, seqCount, currentNum)

      implicit none
      integer(kind = 16) :: seqCount, currentNum, pos, i, check
      integer(kind = 16), dimension(10) :: sequences, nums
      
      check = 0
      
      ! If the current sequence count is lower than the smallest sequence stored, then it
      ! can't be bigger than the rest. So skip and return slice
      if(sequences(1) .gt. seqCount) then
            check = 1
      end if
      
      ! Otherwise, check all the elements in the array
      if(check .eq. 0) then
            check = 0
            do i = 1, 10
                  pos = i
                  if(sequences(i) .eq. seqCount) then
                        check = 1
                  end if
            
                  if(sequences(i) .gt. seqCount .and. check .eq. 0) then
                        check = 1
                        call ShiftLeft(sequences, nums, pos - 1, seqCount, currentNum)
                        exit
                  end if
            end do
      end if
      
      ! If here, the current sequence count is larger than all the stored sequences,
      ! so the last index must be the right spot for the current sequence count
      if (check .eq. 0) then
            call ShiftLeft(sequences, nums, int(10,16), seqCount, currentNum)
      end if    
      
end subroutine

! The function will shift the element in array to the left by 1
! It helps the ReplaceLeast function replace the elements accordingly with the new values
subroutine ShiftLeft(sequences, nums, pos, seq, currentNum)

      implicit none
      integer(kind = 16) :: pos, seq, currentNum, i
      integer(kind = 16), dimension(10) :: sequences, newSeqs, nums, newNums
      
      ! The top (pos + 1) indicies will be the same as original array
      do i = 10, pos+1, -1
            newSeqs(i) = sequences(i)
            newNums(i) = nums(i)
      end do
      
      ! Set the new elements at the desired pos
      newSeqs(pos) = seq
      newNums(pos) = currentNum

      ! Shift elements from indicies pos below to the new arrays
      do i = (pos-1),1,-1
            newSeqs(i) = sequences(i+1)
            newNums(i) = nums(i+1)
      end do
      
      ! Update original arrays with new shifted arrays
      sequences = newSeqs
      nums = newNums
      
end subroutine

! Selection Sort : It will sort array a in ascending order and it will sort array b
! in relation to array a
subroutine SortArray(a, b)

      implicit none
      integer(kind = 16), dimension(10) :: a, b
      integer(kind = 16) :: i, j, n, min_ind, temp
      
      n = size(a)
      
      do i = 1, n-1
      
            min_ind = i
            
            do j = i+1, n
                  if(a(j) .lt. a(min_ind)) then
                        min_ind = j
                  end if
            end do
                  
            temp = a(min_ind)
            a(min_ind) = a(i)
            a(i) = temp
            
            temp = b(min_ind)
            b(min_ind) = b(i)
            b(i) = temp
      
      end do

end subroutine

! Prints num and seq together
subroutine PrintArrays(seq, num)
      
      implicit none
      integer(kind = 16), dimension(10) :: seq, num
      integer(kind = 16) :: i
      
      do i = 10, 1, -1
            print*, num(i), "    ", seq(i)
      end do
      
end subroutine