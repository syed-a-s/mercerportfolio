program help
        implicit none
        real :: x, y
        y = x / 3
        print*, y
end program

integer function total(a, b)
      implicit none
      integer :: a, b
      total = a + b
end function
