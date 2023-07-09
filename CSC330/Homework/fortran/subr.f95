program subr
        
        integer :: a, b, c

        print *, "Give two numbers to add"
        read(*, *) a, b
        
        call add(a, b, c)
        print *,  "Sum of the two numbers is :", c

end program 

subroutine add(a, b, c)

        integer, intent(in) :: a, b ! input
        integer, intent(out) :: c   ! output

        c = a + b

end subroutine
