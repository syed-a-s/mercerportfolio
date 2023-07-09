using System;

class hailcaesar { 

      public static void Main(string[] args) { 
      
            HailCaesar(Convert.ToInt32(args[0]), Convert.ToInt32(args[1]));
                  
      }
      
      // Prints the Count, Sum, Collapse, and Roman Numeral onto the screen
      public static void HailCaesar(int a, int b) { 
            
            int sum = 0;
            int validCount = 0;
            
            for(int i = a; i <= b; i++) { 
                  
                  if(FactorSum(i) == 0)
                        continue;
                  sum += FactorSum(i);
                  validCount++;

            }
            
            Console.WriteLine("Count : " + validCount);
            Console.WriteLine("Sum : " + sum);
            Console.WriteLine("Collapse : " + Collapse(sum));
            Console.WriteLine("Roman : " + ToRoman(Collapse(sum)));
            Console.WriteLine("  --Hail Caesar!");
      
      }
      
      // Checks if a number is prime
      public static bool IsPrime(int n) { 
      
            for(int i = 2; i*i < n; i++) {
                  if(n % i == 0)  
                        return false;
            }
            return true;
      
      }
      
      // If it exists, it finds the two middle unique and prime numbers' sum
      public static int FactorSum(int inNum) { 
      
            // Prime numbers never have two middle factors
            if(IsPrime(inNum))
                  return 0;
                  
            int numHold, sum;
            int count, uniqueCount;
            
            sum = 0; 
            count = 0;
            
            // Sum all the 2s
            numHold = inNum;
            while(numHold % 2 == 0) { 
                  numHold /= 2;
                  count++;
                  sum += 2;
            }
            
            if(count > 1) 
                  return 0;
                  
            uniqueCount = 0;
            numHold = inNum;
            
            // Sum the next middle number if it exists
            for (int i = 3; i*i <= inNum; i+= 2) {
                 while (numHold % i == 0) {
                       numHold /= i;
                       count++;
                       sum += i;
                       uniqueCount++;
                 }
                 
                 if(count > 2 || uniqueCount > 1)
                       return 0;
                 
                 uniqueCount = 0;
           }
           
           // Otherwise, the next middle number is the given number divided by the sum
           return sum + (inNum / sum);
      
      }
      
      // Recursively collapses a number
      public static int Collapse(int checking) {
      
            if(checking < 10) {
                  return checking; 
            } else {
                  int sum = 0; 
                  while(checking > 9) {
                        sum += checking % 10; 
                        checking = checking / 10; 
                  }
                  sum += checking; 
                  return Collapse(sum); 
            }
            
      }
      
      // Recursively converts a number into a roman numeral
      public static string ToRoman(int n) { 
      
            if (n < 1) return string.Empty;
            if (n >= 10) return "X" + ToRoman(n - 10);
            if (n >= 9) return "IX" + ToRoman(n - 9);
            if (n >= 5) return "V" + ToRoman(n - 5);
            if (n >= 4) return "IV" + ToRoman(n - 4);
            if (n >= 1) return "I" + ToRoman(n - 1);
            return string.Empty;
            
      }  

}