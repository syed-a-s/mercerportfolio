import java.util.*;

public class Exam1
{
      public static void main (String[] args)
      {
      int a, oz, lbs, left; 
      
      System.out.println("How many ounces of gourmet candy? ");
      Scanner scan = new Scanner(System.in);
      a = scan.nextInt();
      
      System.out.println("\n\n");
      
      lbs = a / 16;
      oz = a % 16;
      
      System.out.println("Your order consists of : ");
      System.out.println(lbs + " pounds," + oz + " of our fine gourmet chocolate\n");
              
      }
        
}

