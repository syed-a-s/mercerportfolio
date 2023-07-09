program screenformat

character (LEN=247) :: long_string
character (LEN=1) :: input
integer :: counter

! read input file into  long_string
open (unit=5,status="old",access="direct",form="unformatted",recl=1,file="input.txt")

counter = 1
100 read (5,rec=counter,err=200) input
	long_string(counter:counter) = input
  counter = counter + 1
	goto 100
200 continue

close(5)

print *, long_string

end program screenformat
