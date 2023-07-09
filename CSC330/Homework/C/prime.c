#include <stdio.h>

int isPrime(int n);
void printPrime(int n);

void main() { 
      
      int n = 51;
      printf("Enter a number : ");
      scanf("%d", &n);
      printPrime(n);
      
} 

void printPrime(int n) { 

      printf("All prime numbers from 1 to %d are: \n", n);
      
      for (int i = 1; i < n; i++) {
            if(isPrime(i))
                  printf("%d\n", i);
      }    

} 

int isPrime(int n) { 

      int prime = 1;
      
      for (int i = 2; i < n; i++) { 
      
            if ( n % i == 0 ) {
                  prime = 0;
                  break;
            }
      }
      
      return prime;
      
}