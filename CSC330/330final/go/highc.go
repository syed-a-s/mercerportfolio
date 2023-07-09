package main

import("fmt")

func main() {
      
      var min, max int64
      fmt.Print("Minimum Value : ")
      fmt.Scan(&min)
      fmt.Print("Maximum Value : ")
      fmt.Scan(&max)
      fmt.Println(FindLargest(min, max))
      
}

// Finds max sequence number of the numbers in the given range
func FindLargest(bot int64, top int64) int64 { 

      var maxSeq int64 = 0
      for i := bot; i <= top; i++ { 
            if(LongestCollatz(i) > maxSeq) { 
                  maxSeq = LongestCollatz(i)
            }
      }
      return maxSeq
      
}

// Returns the largest sequence number for the given number
func LongestCollatz(n int64) int64{ 
    
      var max int64 = 0
      for n > 1 { 
            if(n % 2 == 0) {
                  n = n / 2
                  // Set max to n if n is greater than max
                  if(n > max) { 
                        max = n
                  } 
            } else  { 
                  n = n * 3 + 1
                  // Set max to n if n is greater than max
                  if(n > max) { 
                        max = n
                  }
            }
      }
      return max
    
}
