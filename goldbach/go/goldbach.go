package main

import ("fmt" 
        "math"
)

func main() {  

      fmt.Print("Enter an odd number greater 7 : ")
      var sum int
      fmt.Scan(&sum)
      
      if((sum > 7) && (sum % 2 == 1)) { 
            var primeNums []int = StorePrime(135)
            FindMinTriplet(primeNums, sum)
      } else { 
            fmt.Println("Please enter a number that is ODD and greater than 7!")
      }
      
}

// Stores all prime numbers from 1 to user input 
func StorePrime(n int) []int{ 

      var primeNums []int       
      for i := 1; i < n; i++ { 
            if IsPrime(i) { 
                  primeNums = append(primeNums, i)
            }    
      }
      return primeNums  
      
}

// Checks if a given number is prime
func IsPrime(n int) bool { 

      var prime bool = true
      for i := 2; i < n; i++ { 
            if(n % i == 0) {
                  prime = false
                  break
            } 
      } 
      return prime 
      
}

// Finds the triple sum with the lowest norm
func FindMinTriplet(primeNums []int, sum int) { 

      var norm float64 = 99999999
      var (l, r int)
      triplet := make([]int, 3)
      
      for i := 0; i < len(primeNums) - 2; i++ { 
            l = i + 1
            r = len(primeNums) - 1
            for l < r { 
                  if(primeNums[i] + primeNums[l] + primeNums[r] == sum) { 
                        if (NormOf( float64(primeNums[i]), float64(primeNums[l]), float64(primeNums[r])))  <= norm { 
                              norm = NormOf(float64(primeNums[i]), float64(primeNums[l]), float64(primeNums[r]))
                              triplet[0] = primeNums[i]
                              triplet[1] = primeNums[l]
                              triplet[2] = primeNums[r]
                        }
                        l++
                        r--
                  } else if(primeNums[i] + primeNums[l] + primeNums[r] < sum) { 
                        l++
                  } else { 
                        r--
                  }   
            }
      }
      
      _ = norm
      fmt.Println(sum, " : " , "(", triplet[0], ",", triplet[1], ",", triplet[2], ")");

}

// Finds the norm of 3 given numbers
func NormOf(i, j, k float64) (float64) { 

      var norm float64 = math.Sqrt((i*i) + (j*j) + (k*k))
      return norm

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
