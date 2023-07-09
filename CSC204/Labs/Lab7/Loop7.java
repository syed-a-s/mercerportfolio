
import java.util.*;

public class Loop7
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
                String userInput = stdin.nextLine();

		int jumpValue = Integer.parseInt(userInput);

  		int i;  int count = 0;
  		for (i = 1;  i <= 10;  i+= jumpValue)
  		{
			if ( i % 2 == 0 ) 
			   break;

        		count++;
  		}
		System.out.println(count);
		System.out.println(i);
	}
}
