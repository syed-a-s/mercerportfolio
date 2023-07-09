#!/usr/bin/julia

# Count sequence in Collatz Conjecture
function CountCollatz(n)
      counter = 1
      while n > 1
            println(Int64(n))
            if(n % 2 == 0)
                  n = n / 2
            else
                  n = n * 3 + 1
            end
            counter += 1
      end
      println(Int64(n))
      return counter
end;

# Main Funciton
print("Enter a number : ")
userInput = parse(Int64, readline())
println("Numbers in the Collatz Conjecture : ", string(CountCollatz(userInput)))
exit(0)
