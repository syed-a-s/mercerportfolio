using System;

class factors { 

      public static void Main(string[] args) { 
      
            Console.Write("Enter a number : ");
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Factor Sum : " + factor(n));
      
      }
      
      public static int factor(int inNum) { 
      
            int numHold, sum;
            int count, uniqueCount;
            
            sum = 0; 
            count = 0;
            
            numHold = inNum;
            while(numHold % 2 == 0) { 
                  numHold /= 2;
                  count++;
                  sum += 2;
            }
            
            if(count > 1) 
                  return -1;
                  
            uniqueCount = 0;
            numHold = inNum;
            
            for (int i = 3; i*i <= inNum; i+= 2) {
                 while (numHold % i == 0) {
                       numHold /= i;
                       count++;
                       sum += i;
                       uniqueCount++;
                 }
                 
                 if(count > 2 || uniqueCount > 1)
                       return -1;
                 
                 uniqueCount = 0;
           }
           
           return sum + (inNum / sum);
      
      }      

}