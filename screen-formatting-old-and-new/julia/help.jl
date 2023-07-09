#!/usr/bin/julia
using Printf

data = "a,b;c x,y;z"
data = replace(data, ";" => "")
@printf("%s\n", data)

msg = "51  a,b;c x,y;z  asga asgsg  ag         gagg"
msg = filter(!isdigit, msg) 
msg = replace(msg, r"[,;]" => "")
msg = strip(msg)
@printf("%s\n", msg)

b = "huh.      okay                   bruh"
a = split(b)
chrCount = 0

for i in a
	global chrCount = chrCount + lastindex(i) + 1
	if(chrCount < 7)
		print(i, " ")
	else
		println()
		print(i, " ")
		chrCount = 0
	end
end

println(lastindex(a[1]))

bruh = 15314
ok = string(bruh)
@printf("%s\n", ok)
println(lastindex(ok))
exit(0)
