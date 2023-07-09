#!/usr/bin/julia

function fact(n)

	if(n < 0)
		return -1
	elseif(n == 0 || n == 1)
		return 1
	else
		n * fact(n - 1)
	end
	
end

# Main Program

println(fact(parse(Int64, ARGS[1])))
exit(0)
