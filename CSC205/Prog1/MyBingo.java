import java.io.*;
import java.util.*;

public class MyBingo
{

	public static void main(String[] args)
	{
    String[] BingoNums = new String[25];
    fillCard(BingoNums);
    
    printCard(BingoNums);
    
    randomNumGen(25, BingoNums);
    
  }
  
  // This grabs the numbers from the bingo.in file
  
  private static int fillCard(String[] list)
  {
          //post : List is initialized with all strings from file.

          String filename, stateInput;
          int i = 0, numItems = 0;
          try  {
                Scanner stdin = new Scanner(System.in);
                stdin = new Scanner(new File("bingo.in"));

                while ((stdin.hasNext()) && (i < list.length))
                {
                        stateInput = stdin.nextLine();
                        list[i] = stateInput;
                        i++;
                }
                numItems = i;
          }
          catch (IOException e)  {
                System.out.println(e.getMessage());
          }
          return numItems;
   }
  
  // This will print the bingo card
  
  public static void printCard(String[] BingoNums)
  {
    System.out.println();
    System.out.println("\tYOUR BINGO CARD:");
    System.out.println();
    System.out.println("\tB\tI\tN\tG\tO");
    System.out.println("\t----------------------------------");
    
    // Printing the numbers on Bingo Card
    for (int i = 0; i < BingoNums.length; i++)
    {
         System.out.print("\t" + BingoNums[i] + " ");
         if ((i + 1) % 5 == 0 && i > 0)
             System.out.println("\n");
    }
    
    System.out.println();
     
  }
  
  // The random number generator
  
  public static void randomNumGen(int repeats, String[] BingoNums)
  {
     long RANDOM = 0;
     
     System.out.println("\tBINGO NUMBERS PICKED AT RANDOM FROM BIN :\n");
     
     // Printing out the randoms 
     for ( int i = 0; i < repeats; i++ )
     {
       RANDOM = Math.round((Math.random() * 74 + 1));
       System.out.print("\t" + RANDOM + " ");
             if ( (i + 1) % 9 == 0 && i > 0)
                 System.out.println();
             else if ( (i + 1) == repeats )
                 System.out.print("\t");
       
     }
   System.out.println("\n");  

  }
  
  

}
  



