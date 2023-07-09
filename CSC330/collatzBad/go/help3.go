package main

import ("fmt"
)

func main() { 

      for i := 0; i < 1000; i++ { 
      
            if(CountCollatz(i) == 147) { 
                  fmt.Println(i)
            }
      
      }

}

func CountCollatz(n int) int{ 
    
    var counter int = 0
    for n > 1 { 
          if(n % 2 == 0) { 
                n = n / 2
          } else  { 
                n = n * 3 + 1
          }
          counter++
    }
    return counter
    
}
