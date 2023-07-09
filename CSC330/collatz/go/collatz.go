package main

import ("fmt"
        "sort"
)

// Struct can be used to hold a number and its corresponding Collatz Sequence length
type sequence struct { 
      num int
      sequences int
}

func main() {

      var r int
      fmt.Print("Enter a number greater than 10 : ")
      fmt.Scan(&r)
      FindTop10(r)
      
}

// Finds the top 10 largest sequences with the smallest integers
func FindTop10(r int) { 

      numSeq := make([]sequence, 10)
      
      // Fill up the first 10 slots with sequence lengths for 1 - 10
      for i := 0; i < 10; i++ { 
            numSeq[i].sequences = CountCollatz(i + 1)
            numSeq[i].num = i + 1
      }
      
      // Sort array of structs by sequence length from least to greatest
      sort.Slice(numSeq, func(i, j int) bool {
            return numSeq[i].sequences < numSeq[j].sequences
      })
      
      // Find top 10 
      for i := 10; i < r; i++ { 
            numSeq = ReplaceLeast(numSeq, CountCollatz(i+1), i+1)
      }
      
      // Prints nums and sequence length from greatest sequence length to least greatest sequence length
      fmt.Println("Sorted based on sequence length")  
      PrintArray(numSeq)
      
      // Sort array of structs by integer length from least to greatest
      sort.Slice(numSeq, func(i, j int) bool {
            return numSeq[i].num < numSeq[j].num
      })     
      
      // Prints nums and sequence length from greatest integer to least greatest integer
      fmt.Println("Sorted based on integer size")
      PrintArray(numSeq)

}

// Counts the sequence length of a number iteratively
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

// Will find the smallest sequence length and replace it with a number's current calculated sequence length
func ReplaceLeast(slice []sequence, seqCount int, currentNum int) []sequence { 
      
      // If the current sequence count is lower than the smallest sequence stored, then it
      // can't be bigger than the rest. So skip and return slice
      if(slice[0].sequences > seqCount) {
            return slice
      }
      
      // Otherwise, check all the elements in the array
      for i := 0; i < len(slice); i++ {
      
            // The currentNum will ALWAYS be bigger than the stored num, so skip and return
            if(slice[i].sequences == seqCount) { 
                  return slice
            }

            // If here, and the sequences stored is greater than the current sequences, then
            // the index before must be the spot for the current sequence count
            if(slice[i].sequences >= seqCount) {
                  slice = ShiftLeft(slice, i - 1, seqCount, currentNum)
                  return slice
            }
                  
      }
      
      // Otherwise, the current sequence count is larger than all the stored sequences,
      // so replace the last index and shift other elements down accordingly
      slice = ShiftLeft(slice, len(slice) - 1, seqCount, currentNum)
      return slice
      
}

// The function will shift the element in array to the left by 1
// It helps the ReplaceLeast function replace the elements accordingly with the new values
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

// Prints an array reverse order
func PrintArray(numSeq []sequence) { 

      for i := len(numSeq) - 1; i >= 0; i-- {
            fmt.Println(numSeq[i].num, "   ", numSeq[i].sequences)
      }

}
