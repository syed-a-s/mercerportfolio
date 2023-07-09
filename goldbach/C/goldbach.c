#include <stdio.h>
#include <cstdlib>
#include <math.h>

void StorePrime(int *primeNums, int userInput);
int CountPrime(int n);
void FindMinTriplet(int *primeNums, int size,  int userInput);
int IsPrime(int n);
double NormOf(double i, double j, double k);

int main() { 

      int sum;
      printf("Enter an odd number greater than 7: ");
      scanf("%d", &sum);
      
      if((sum > 7) && (sum % 2 == 1)) {
      
            int size = CountPrime(sum);
            int primeNums[size];
            StorePrime(primeNums, sum);
            FindMinTriplet(primeNums, size, sum);
      
      } else { 
            printf("Please enter a number that is ODD and greater than 7!\n");
      }
      
      return 0;
}

// Stores all prime numbers from 1 to user input into a fixed array
void StorePrime(int *primeNums, int sum) { 

      int arrayIndex = 0;
      for(int i = 0; i < sum; i++) { 
            if(IsPrime(i)) { 
                  primeNums[arrayIndex] = i;
                  arrayIndex++;
            }
      }

}

// Counts the number of prime numbers from 1 to user input
// This is used to find the array size for the array of prime numbers
int CountPrime(int n) { 

      int counter = 0;
      for(int i = 1; i < n; i++) { 
            if(IsPrime(i))
                  counter++;
      }
      return counter;

}

// Checks if a given number is prime
int IsPrime(int n) { 

      int prime = 1;
      for(int i = 2; i < n; i++) { 
            if(n % i == 0) { 
                  prime = 0;
                  break;
            }
      }
      return prime;      
      
}

// Finds the triple sum with the lowest sum
void FindMinTriplet(int *primeNums, int size, int sum) { 

      int l, r;
      double norm = 999999999;
      int triplet[3];
      
      for(int i = 0; i < size - 2; i++) { 
            l = i + 1;
            r = size - 1;
            while(l < r) { 
                  if(primeNums[i] + primeNums[l] + primeNums[r] == sum) { 
                        if(NormOf(primeNums[i], primeNums[l], primeNums[r]) <= norm) { 
                              norm = NormOf(primeNums[i], primeNums[l], primeNums[r]);
                              triplet[0] = primeNums[i];
                              triplet[1] = primeNums[l];
                              triplet[2] = primeNums[r];
                        }                  
                        l++;
                        r--;
                  } else if(primeNums[i] + primeNums[l] + primeNums[r] < sum) { 
                        l++;
                  } else { 
                        r--;
                  }
            }
      }
      
      printf("%d : (%d, %d, %d) \n", sum, triplet[0], triplet[1], triplet[2]);

}

// Finds the norm of 3 given numbers
double NormOf(double i, double j, double k) { 
      
      double norm = sqrt((i*i) + (j*j) + (k*k));
      return norm;
      
}


 
