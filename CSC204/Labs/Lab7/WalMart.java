import java.text.*;
import java.util.*;
public class WalMart
{
	public static void main (String[] args)
	{	
	        int numStores = 0;
	        double sum = 0.0, average;

	        System.out.println("*****Average Wal-Mart Sales*****\n");

	        System.out.print("Number of Stores:  ");
          Scanner stdin = new Scanner(System.in);
	        numStores = stdin.nextInt();
	
	        for(int index = 1; index <= numStores; index++)
	        {
                    // Complete Body of for loop HERE
          System.out.print("Store #" + index + " : $");
          sum += stdin.nextDouble();

          }

	        average = sum / numStores;
	        average = Math.round(average * 100) / 100.0;
	
                System.out.print("\nThe Average Sales for " + numStores +
                                 " Wal-Marts was $");
                System.out.printf("%1.2f", average);
                System.out.println(".");
	}
}
