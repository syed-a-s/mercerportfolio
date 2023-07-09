
import java.util.*;

public class Loop3
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
                String userInput = stdin.nextLine();

		int index = 0;
		char ch = '\0';

		for (int k = 5;  k <= 7;  k++)
		{
			ch = userInput.charAt(index);
			System.out.print(ch);
			index++;
		}
		System.out.println(ch);
	}
}
