
import java.util.*;

public class Loop6
{
	public static void main(String[] args)
	{
                Scanner stdin = new Scanner(System.in);
                String str1 = stdin.nextLine();
		String str2 = "";

		while (true)
		{
			int i = str1.indexOf("-");
			if (i < 0)
				break;
			str2 += str1.substring(0, i);
			str1 = str1.substring(i + 1);
		}

		System.out.println(str2 + str1);
	}
}
