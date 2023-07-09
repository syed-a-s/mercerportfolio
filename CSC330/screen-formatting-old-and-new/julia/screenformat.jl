#!/usr/bin/julia
using Printf

# ask user for file name
print("Which file would you like to format? --> ")
userInput = readline()
println()

# open and read input file
file = open(userInput, "r")
msg = read(file, String)

# make a new file so we can write the formatted message into it
outfile = "formatted.txt"
fileFormatted = open(outfile, "w")

# filter garbage and 
# split msg into an array
msg = filter(!isdigit, msg)
msgArray = split(msg)

#### The Formatter ####

chrCount = 0
lineNum = 1
lineEndMarker = 0
@printf("%8s  ", lineNum)
for word in msgArray
	global chrCount = chrCount + lastindex(word) + 1
	if((chrCount + lineEndMarker) < 61)			
		@printf("%s ", word)
		print(fileFormatted, string(word, " "))
	else
		global lineNum += 1
		@printf("\n%8s  %s ", lineNum, word)
		print(fileFormatted, string("\n", word, " "))
		global lineEndMarker = length(word)		# to account for extra word
		global chrCount = 0
	end
end
println("\n")
close(file)
close(fileFormatted)

#######################

# Read formatted message line by line and determine which one is longest and shortest lines
open(outfile) do fileFormatted

	firstLine = readline(fileFormatted)
	longLine = firstLine
	shortLine = firstLine

	lineNum = 1
	longLineNum = 1
	shortLineNum = 1

	while ! eof(fileFormatted)
		lineoftext = readline(fileFormatted)
		lineNum += 1
		if(length(longLine) < length(lineoftext))
			longLine = lineoftext
			longLineNum = lineNum
		end
		
		if(length(shortLine) > length(lineoftext))
			shortLine = lineoftext
			shortLineNum = lineNum
		end
	end
	
	if(length(longLine) == length(shortLine))
		@printf("%8s           %s\n", string("SHORT  ", shortLineNum), shortLine)
	else
		@printf("%8s           %s\n", string("LONG  ", longLineNum), longLine)
		@printf("%8s           %s\n", string("SHORT  ", shortLineNum), shortLine)
	end
end

println()

exit(0)
