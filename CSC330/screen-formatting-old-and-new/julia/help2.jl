#!/usr/bin/julia
using Printf


num = "12314"
okay = "15"
@printf("\t%-8s\n", num)
@printf("\t%-8s\n", okay)

for i in 9999999:10000009
	@printf("%8s  %s\n", i, "test")
end

exit(0)
