program collatz

      implicit none
      
      integer(kind = 16) :: i, j, n, r, seqCount, CountCollatz 
      integer(kind = 16), dimension(10) :: sequences, nums, newArray
      
      sequences = (/0, 1, 2, 3, 5, 6, 7, 8, 16, 19/)
      nums = (/1, 2, 4, 8, 5, 10, 3, 6, 7, 9/)
      r = 100
      i = 4
      seqCount = 1312
      n = 3
      
      do j = 1,10
            print*, sequences(j)
      end do
      print*,""
      do j = 1,10
            print*, nums(j)
      end do
      
      print*,""
      
      call shiftleft(sequences, nums, i, seqCount, r)
      
      do j = 1,10
            print*, sequences(j)
      end do
      print*,""
      do j = 1,10
            print*, nums(j)
      end do
      
end program

subroutine shiftleft(sequences, nums, pos, seq, currentNum)
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