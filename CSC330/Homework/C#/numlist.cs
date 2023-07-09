using System;

public class Numlist {

      public static void Main() {

            int n;
            Console.Write("Enter a number: " );
    		    String str = Console.ReadLine();
		        n = Convert.ToInt32(str);
            printPrime(n);

      }

      public static void printPrime(int n) {

            Console.WriteLine("All prime numbers from the range 1 to " +  n + " are: ");

            for (int i = 1; i < n; i++) {
                  if(isPrime(i))
                        Console.WriteLine(i);
            }

      }

      public static bool isPrime(int n) {

            bool prime = true;

            for (int i = 2; i < n; i++) {
                  if( n % i == 0) {
                        prime = false;
                        break;
                  }
            }

            return prime;

      }
      
}

