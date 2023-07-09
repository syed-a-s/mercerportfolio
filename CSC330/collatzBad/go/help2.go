package main

import ("fmt"
        "sort"
)

type sequence struct { 
      num int
      sequences int
}

func main() { 

      n := make([]sequence, 10)
      for i := 0; i < len(n); i++ { 
            n[i].sequences = i * 2
            n[i].num = i
      }
      PrintArray(n)
      fmt.Println("sep")
      
      n = ShiftLeft(n, 8, 1424, 21)
      PrintArray(n)
      
      sort.Slice(n, func(i, j int) bool {
            return n[i].sequences < n[j].sequences
      })

}

func PrintArray(numSeq []sequence) { 

      for i := 0; i < len(numSeq); i++ {
            fmt.Println("n : ", numSeq[i].num)
            fmt.Println("s : ", numSeq[i].sequences)
            fmt.Println()
      }

}

func ShiftLeft(array []sequence, pos int, seq int, currentNum int) []sequence { 

      demo := make([]sequence, len(array))
      for i := len(array) - 1; i > pos; i-- { 
            demo[i].sequences = array[i].sequences
            demo[i].num = array[i].num
      }
      demo[pos].sequences = seq
      demo[pos].num = currentNum
      for i := pos - 1; i >= 0; i-- { 
            demo[i].sequences = array[i+1].sequences
            demo[i].num = array[i+1].num
      }
      return demo
}