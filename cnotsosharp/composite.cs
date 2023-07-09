using System;

class hailcaesar { 

      public static void Main(string[] args) { 
      
            HailCaesar(long.Parse(args[0]), long.Parse(args[1]));
                  
      }
      
      // Prints the Count, Sum, Collapse, and Roman Numeral onto the screen
      public static void HailCaesar(long a, long b) { 
            
            long sum = 0;
            long validCount = 0;
            
            Console.WriteLine(a + " " + b);

            for(long i = a; i <= b; i++) { 
                  //Console.WriteLine("Testing : " + i);
                  if(FactorSum(i) == 0)
                        continue;
                  sum += FactorSum(i);
                  validCount++;
            }
            
            Console.WriteLine("Count : " + validCount);
            Console.WriteLine("Sum : " + sum);
            Console.WriteLine("Collapse : " + Collapse(sum));
            Console.WriteLine("Roman : " + ToRoman(Collapse(sum), false));
            Console.WriteLine("  --Hail Caesar!");
      
      }
      
      // Checks if a number is prime
      public static bool IsPrime(long n) { 
      
            for(long i = 2; i*i < n; i++) {
                  if(n % i == 0)  
                        return false;
            }
            return true;
      }
      
      // If it exists, it finds the two middle unique and prime numbers' sum
      public static long FactorSum(long inNum) { 
      
            // Prime numbers never have two middle factors
            if(IsPrime(inNum))
                  return 0;
                  
            long numHold, sum;
            long count, uniqueCount;
            
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
            for (long i = 3; i*i <= inNum; i+= 2) {
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
      public static long Collapse(long checking) {
            if(checking < 10) {
                  return checking; 
            } else {
                  long collapseSum = 0;
                  while(checking > 0) {
                        collapseSum += checking % 10; 
                        checking = checking / 10; 
                  }
                  collapseSum += checking; 
                  return Collapse(collapseSum); 
            }
            
      }
      
      // Recursively converts a number into a roman numeral
      public static string ToRoman(long n, bool run) { 
      
            if (n < 1 && run == false) return "N";
            if (n >= 10) return "X" + ToRoman(n - 10, true);
            if (n >= 9) return "IX" + ToRoman(n - 9, true);
            if (n >= 5) return "V" + ToRoman(n - 5, true);
            if (n >= 4) return "IV" + ToRoman(n - 4, true);
            if (n >= 1) return "I" + ToRoman(n - 1, true);
            return string.Empty;
            
      }  

}
