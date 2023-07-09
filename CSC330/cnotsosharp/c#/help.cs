using System;
class Program
{
      
      public static void Main() { 
      
            for(int i = 1; i <= 10; i++) 
                  Console.WriteLine(i + " : " + ToRoman(i));
            
      }
      
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