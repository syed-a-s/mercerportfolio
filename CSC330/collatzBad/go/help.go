package main

import ("fmt"
        //"sort"
)

func main() { 

      n := make([]int, 10)
      for i := 0; i < len(n); i++ { 
            n[i] = i * 2
      }
      PrintArray(n)
      fmt.Println()
      n = addPos(n, 9, 31)
      n = addPos(n, 8, 29)
      PrintArray(n)
      fmt.Println()
      
      b := make([]int, 30)
      for i := 0; i < len(b); i++ { 
            b[i] = i * 2
      }
      PrintArray(b)
      fmt.Println()
      b = addPos(b, 19, 31)
      b = addPos(b, 18, 29)
      PrintArray(b)
      
}

func b(n int, array []int) { 

      if(array[0] > n) { 
            fmt.Println("n is smaller than the smallest in array")
            return
      }
      fmt.Println("bruh")
      for i := 1; i < len(array); i++ { 
            if(array[i] >= n) { 
                  array[i - 1] = n
                  return
            }
      }
      
      array[len(array) - 1] = n
      
}

func PrintArray(numSeq []int) { 

      for i := 0; i < len(numSeq); i++ {
            fmt.Println("n :", numSeq[i])
      }

}


func ShiftLeft(array []int) []int { 

      demo := make([]int, len(array))
      
      for i := 0; i < len(array) - 1; i++ { 
            demo[i] = array[i+1]
      }
      
      demo[len(demo) - 1] = array[0]
      
      return demo
      
}

func addPos(array []int, pos int, num int) []int { 

      demo := make([]int, len(array))
      for i := len(array) - 1; i > pos; i-- { 
            demo[i] = array[i]
      }
      demo[pos] = num
      for i := pos - 1; i >= 0; i-- { 
            demo[i] = array[i+1]
      }
      return demo
}