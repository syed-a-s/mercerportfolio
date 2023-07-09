#!/usr/bin/julia

# Count sequence in Collatz Conjecture iteratively
function CountCollatz(n)
      counter = 0
      while n > 1
            if(n % 2 == 0)
                  n = n / 2
            else
                  n = n * 3 + 1
            end
            counter += 1
      end
      return counter
end;

# Will find the smallest sequence length and replace it with a number's current calculated sequence length
function ReplaceLeast(sequences, nums, seqCount, currentNum)

      # If the current sequence count is lower than the smallest sequence stored, then it
      # can't be bigger than the rest. So skip and return slice
      if(sequences[1] > seqCount)
            return sequences, nums
      end
      
      # Otherwise, check all the elements in the array
      for i in eachindex(sequences)
            
            if(sequences[i] == seqCount) 
                  return sequences, nums
            end
            
            if(sequences[i] > seqCount) 
                  sequences, nums = ShiftLeft(sequences, nums, i - 1, seqCount, currentNum)
                  return sequences, nums
            end
        
      end
      
      # Otherwise, the current sequence count is larger than all the stored sequences,
      # so the index before must be the spot for the current sequence count
      sequences, nums = ShiftLeft(sequences, nums, 10, seqCount, currentNum)
      return sequences, nums
         
end

# The function will shift the element in array to the left by 1
# It helps the ReplaceLeast function replace the elements accordingly with the new values
function ShiftLeft(sequences, nums, pos, seq, currentNum)

      newSeq = Array{Int64}(undef, 10)
      newNums = Array{Int64}(undef, 10)
      
      # The top (pos + 1) indicies will be the same as original array
      for i = 10:-1:pos+1
            newSeq[i] = sequences[i]
            newNums[i] = nums[i]
      end
      
      # Set the new elements at the desired pos
      newSeq[pos] = seq
      newNums[pos] = currentNum
      
      # Shift elements from indicies pos below to the new arrays
      for i = pos - 1:-1:1
            newSeq[i] = sequences[i+1]
            newNums[i] = nums[i+1]
            #println(i)
      end
      
      # Return the new shifted arrays
      return newSeq, newNums
      
end

# Prints two arrays reverse order
function PrintArrays(sequences, nums)

      for i = 10:-1:1
            println(nums[i], "       ", sequences[i])
      end

end

# Main
function main()

      print("\nEnter a number greater than 10 : ")
      r = parse(Int64, readline())
      println()

      # First 10 sequences are set by default
      sequences = [0, 1, 2, 3, 5, 6, 7, 8, 16, 19]
      nums = [1, 2, 4, 8, 5, 10, 3, 6, 7, 9]

      # Find top 10 smallest integers with the largest sequences
      for i in 11:r
            sequences, nums = ReplaceLeast(sequences, nums, CountCollatz(i), i)
      end
      
      println("Sorted based on sequence length")
      PrintArrays(sequences, nums)
      
      # Sort nums and sequences so that num is ordered from least to greatest
      # sequences will be sorted accordingly with nums
      p = sortperm(nums); nums .= nums[p]; sequences .= sequences[p]
      
      println("Sorted based on integer size")
      PrintArrays(sequences, nums)
      
      println()
      
end

main()




