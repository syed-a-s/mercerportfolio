
import java.util.*;

public class Ex1
{
	public static void main(String[] args)
	{

    		int x, y, z;

                Scanner stdin = new Scanner(System.in);
		x = stdin.nextInt();

		z = stdin.nextInt();

    		y = x * z;
    		x = y * z;
    		z = z * z;
	 	
		System.out.println();
		System.out.println(x);	
		System.out.println(y);	
		System.out.println(z);	
	}
}
