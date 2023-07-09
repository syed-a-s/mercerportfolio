
import java.util.*;

public class Ex6
{
	public static void main(String[] args)
	{

    		char ch = '5';

                Scanner stdin = new Scanner(System.in);

		int value = stdin.nextInt();

		System.out.println(ch + " " + value);
		ch = '$';
		System.out.println("" + ch + ch + ch + ch);

                String userInput = stdin.next();
		value = stdin.nextInt();
		System.out.println("value = " + value);
	}
}
