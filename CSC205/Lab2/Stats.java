import java.util.*;

public class Stats
{
	private static final int MAX_SIZE = 100;
	public static void main(String[] args)
	{
	       int[] List = new int[MAX_SIZE];		
         int numItems;

         numItems = fillUp(List);

         System.out.println("\n\10\7" + " The range of your " +
         numItems + " items is :  " + range (List, numItems));

         System.out.println("\n\10\7" + " The mean of your " + 
         numItems + " items is  :  " + mean (List, numItems));
         
         private static int fillUp(int[] List)
         {
         int n = 0; 
         Scanner scan = new Scanner(System.in);
         System.out.print("Please Input Your Values (Enter a 0 to Stop) :" + "\n");
         
         while ( true )
         {
               List[n] = scan.nextInt();
               
               if ( List[n] == 0 )
                   break;
               n++;
         };
         return n;

         }
         
         // Range finder
         private static int range (int[] List, int numItems)
         {
         int maxValue = List[0];
         for (int i = 1;  i < numItems;  i++)
         {
             if (List[i] > maxValue)
             {
                 maxValue = List[numItems];
             }
         }
             
         int minValue = List[0];
         for (int j = 1; j < numItems ; j++)
         {
             if (List[j] < minValue)
             {
                 minValue = List[numItems];
             }
         
         }
         
         return maxValue - minValue; 
         
         }
         
          // Mean finder
          private static int mean (int[] List, int numItems)
          {
          double total = 0;
            for (int i = 1; i < numItems; i++)
            {
                total += total + List[i];
            }
          return total / numItems;
          
          }
          
  }

}
