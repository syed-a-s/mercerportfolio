#!/usr/bin/julia

function ShiftLeft(sequences, nums, pos, seq, currentNum)

      newSeq = Array{Int64}(undef, 10)
      newNums = Array{Int64}(undef, 10)
      
      for i = 10:-1:pos+1
            newSeq[i] = sequences[i]
            newNums[i] = nums[i]
      end
      
      newSeq[pos] = seq
      newNums[pos] = currentNum
      
      for i = pos - 1:-1:1
            newSeq[i] = sequences[i+1]
            newNums[i] = nums[i+1]
            #println(i)
      end
      
      return newSeq, newNums
      
end

# Main

sequences = [0, 1, 2, 3, 5, 6, 7, 8, 16, 19]
nums = [1, 2, 4, 8, 5, 10, 3, 6, 7, 9]

for i in 1:10
      println(sequences[i])
end

println("nums")
for i in 1:10
      println(nums[i])
end

println("sep\n")

sequences, nums = ShiftLeft(sequences, nums, 4, 3131, 5)

for i in 1:10
      println(sequences[i])
end

println("nums")
for i in 1:10
      println(nums[i])
end

println(length(sequences))