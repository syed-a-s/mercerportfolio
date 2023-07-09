
import java.util.*;

public class OddEven
{
	public static void main(String[] args)
	{
	
  	System.out.print("Please enter an integer ==> ");
                Scanner stdin = new Scanner(System.in);
		int myNum = stdin.nextInt();

		// Insert Your If Statement HERE
   
     if(myNum % 2 == 1)
        System.out.println("The number " + myNum + " is odd.");
        else 
        System.out.println("The number " + myNum + " is even.");
        
	}
}
