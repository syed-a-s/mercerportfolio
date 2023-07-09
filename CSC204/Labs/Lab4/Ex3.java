
import java.util.*;

public class Ex3
{
	public static void main(String[] args)
	{
		int i, j, k;

                Scanner stdin = new Scanner(System.in);

		i = stdin.nextInt();

		j = stdin.nextInt();

		k = stdin.nextInt();

    		i = j;
    		j = j + k;
    		k = j - k;
    		j = j - k;

		System.out.println("\n" + "i = " + i);
		System.out.println("\n" + "j = " + j);
		System.out.println("\n" + "k = " + k);
	}
}
