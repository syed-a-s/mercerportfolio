
import java.util.*;

public class Loop1 
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
		String userInput = stdin.nextLine();
		int index = 0;
		char ch = userInput.charAt(index);

		while (ch != '+')
		{
			index++;
			ch = userInput.charAt(index);
			System.out.print(ch);
		}
		System.out.println(ch);
	}
}
