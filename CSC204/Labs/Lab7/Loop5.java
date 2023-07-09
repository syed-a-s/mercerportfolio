
import java.util.*;

public class Loop5
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
                String userInput = stdin.nextLine();

		int stopValue = Integer.parseInt(userInput);

		userInput = stdin.nextLine();
		int index = 0;
		char ch = '*';

		for (int k = 4;  k <= stopValue;  k++)
		{
			index++;
			ch = userInput.charAt(index);
			System.out.print(ch);
		}

		System.out.println(ch);
	}
}
