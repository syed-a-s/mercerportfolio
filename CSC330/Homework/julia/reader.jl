#!/usr/bin/julia
using Printf

open("/pub/pounds/CSC330/translations/KJV.txt") do file

  # create a variable to hold the lines
  lines = 0

  # read till end of file
  while ! eof(file)

     # read a line of text and store it in lineoftext
     lineoftext = readline(file)
     lines += 1
     # print the line of text
     println("$lineoftext")
  end
  # Did something nasty on the next line.   Fix it in
  # your code.  This would be a nightmare to debug!
  @printf("There are %d lines\n", lines)
end
