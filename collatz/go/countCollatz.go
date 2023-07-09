
// Count the total number of numbers for a number in the collatz conjecture

package main

import("fmt")

func main() { 

      var userInput int
      fmt.Print("Enter a number : ")
      fmt.Scan(&userInput)
      fmt.Println("Numbers in the Collatz Sequence : ",  CountCollatz(userInput))
      
}

func CountCollatz(n int) int{ 
    
    var counter int = 1
    for n > 1 { 
          fmt.Println(n)
          if(n % 2 == 0) { 
                n = n / 2
          } else  { 
                n = n * 3 + 1
          }
          counter++
    }
    fmt.Println(n)
    return counter
    
}