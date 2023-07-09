// Name : Saadat
// Desc : This program is an example of how the functions written
//        can work together to find the sum of two middle prime and 
//        unique factors of a given number

// Functions
//        PrimeFactor       : Expects a number and will return a sorted ArrayList with all the factors
//        CheckValidFactors : Expects an ArrayList with factors and will check all cases to see if there
//                            are two middle unique and prime numbers
//        MidUniqueSum      : Expects an ArrayList with factors and uses CheckValidFactors to either return
//                            the sum, or if an invalid number is passed, return -1.
 
using System;
using System.Collections;
using System.Collections.Generic;

class uniquefactors { 

      // Class used to help sort ArrayList (very C# specific)
      public class myReverserClass : IComparer  {

            // Calls CaseInsensitiveComparer.Compare with the parameters reversed.
            int IComparer.Compare( Object x, Object y )  {
                  return( (new CaseInsensitiveComparer()).Compare( y, x ) );
            }
            
      }


      public static void Main(string[] args) {
            
            ArrayList primeFactors = new ArrayList();
            
            // Get number from user and factor it
            Console.Write("Enter a number : ");
            int n = Convert.ToInt32(Console.ReadLine());
            primeFactors = PrimeFactor(n);
            
            // Print all factors of the number given by the user
            Console.Write("The factors of " + n + " are : ");
            foreach(int item in primeFactors) {
                  Console.Write(item + " ");
            }
            Console.WriteLine();
            
            // Find the sum of two middle prime and unique numbers
            // and print it
            int midSum = MidUniqueSum(primeFactors);
            Console.WriteLine("Sum of the two middle prime and unique numbers : " + midSum);
            
      }
      
      // Finds the factors of any given number and 
      // returns the factors in an already SORTED ArrayList
      public static ArrayList PrimeFactor(int n) { 
            
            ArrayList primeFactors = new ArrayList();
            
            primeFactors.Add(n);
            
            // Take care of all even factors
            while(n % 2 == 0) { 
                  primeFactors.Add(2);
                  n /= 2; 
            }
            
            // Take care of all odd factors
            for (int i = 3; i <= Math.Sqrt(n); i+= 2) {
                 while (n % i == 0) {
                       primeFactors.Add(i);
                       n /= i;
                 }
           }
           
           // Take care of the final prime factor
           if(n > 2) { 
                 primeFactors.Add(n);
           }
           
           primeFactors.Add(1); 
           
           // Sort Array from greatest to least greatest
           IComparer myComparer = new myReverserClass();
           primeFactors.Sort(myComparer);

           return primeFactors;
           
      }
      
      // Checks all cases to see if the given list of factors have two middle prime AND unique factors
      public static bool CheckValidFactors(ArrayList primeFactors) { 
      
            // All valid cases have 4 factors
            if(primeFactors.Count == 4) {
                 
                  // If the middle two prime numbers are equal, they are NOT unique
                  if(Convert.ToInt32(primeFactors[1]) == Convert.ToInt32(primeFactors[2])) { 
                        Console.WriteLine("Invalid --- Middle two prime factors are NOT unique!");
                        return false;
                  // Otherwise, they are unique
                  } else  { 
                        return true; 
                  }
            
            // If there are more or less than 4 factors, the number is not valid     
            } else { 
            
                  Console.WriteLine("Invalid -- Two middle prime factors do not exist!");
                  return false;
                  
            }
                
      }
      
      // Returns the sum of the two middle prime factors 
      // This function uses CheckValidFactors to help find valid factors
      public static int MidUniqueSum(ArrayList primeFactors) { 
      
            // If the factors are valid then find the sum
            if(CheckValidFactors(primeFactors)) { 
                  int sum = Convert.ToInt32(primeFactors[1]) + Convert.ToInt32(primeFactors[2]);
                  return sum;
            // If not possible, return -1
            } else { 
                  return -1;
            }
      
      }
      
}