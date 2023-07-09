
import java.util.*;

public class RandomArray
{
	public static void main(String[] args)
	{
   int [] random = new int[51];
   
   for( int k = 1; k < random.length; k++)
     {
       random[k] = (int) (Math.random() * 41 + 10);
       System.out.print(" " + random[k] + " ");
       if( k % 10 == 0 )
       System.out.println();
     } 
   System.out.println();
   
  }
 
}