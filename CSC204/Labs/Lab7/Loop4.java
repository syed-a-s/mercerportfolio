
import java.util.*;

public class Loop4
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
                String userInput = stdin.nextLine();

		int index = 0;
		char ch = '*';

		for (int k = 1;  k <= 20000;  k++)
			if (k <= 3)
			{
				ch = userInput.charAt(index);
				System.out.print(ch);
				index++;
			}

		System.out.println(ch);
	}
}
