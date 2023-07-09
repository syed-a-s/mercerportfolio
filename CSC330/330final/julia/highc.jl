#!/usr/bin/julia

# Finds max sequence number of the numbers in the given range
function FindLargest(bot, top)

      maxSeq = 0
      for i in bot:top
            if(LargestCollatz(i) > maxSeq)
                  maxSeq = LargestCollatz(i)
            end
      end
      return maxSeq

end

# Returns the largest sequence number for the given number
function LargestCollatz(n)

      max = 0
      while n > 1
            if(n % 2 == 0)
                  n = n / 2
                  # Set max to n if n is greater than max
                  if(n > max)
                        max = n
                  end
            else
                  n = n * 3 + 1
                  # Set max to n if n is greater than max
                  if(n > max)
                        max = n
                  end
            end
      end
      return Int(max)

end

function main()
      
      print("Minimum Value : ")
      min = parse(Int64, readline())
      print("Maximum Value : ")
      max = parse(Int64, readline())
      println(FindLargest(min, max))
      
end

main()
