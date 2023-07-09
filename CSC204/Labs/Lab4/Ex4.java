
import java.util.*;

public class Ex4
{
	public static void main(String[] args)
	{
		int i;
		double j, k, result;

                Scanner stdin = new Scanner(System.in);

		i = stdin.nextInt();

		j = stdin.nextDouble();

		k = stdin.nextDouble();

    		result = (double) i + j; 
		System.out.print("\n" + result + "\n");

		result = Math.pow( (double) i, 2.0 ) + Math.sqrt( k );
		System.out.print("\n" + result + "\n");
	}
}
