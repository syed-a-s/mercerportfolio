program fact1

integer(kind = 16) :: val, i
integer(kind = 16) :: fact
external fact

do i = 1, 34
  print *, i, fact(i)
enddo

end program fact1

recursive integer(kind = 16) function fact( i ) result (val)

integer(kind = 16) :: i

if ( i /= 1 ) then
  val = i * fact(i-1)
else
  val = 1
  return
endif

end function fact
