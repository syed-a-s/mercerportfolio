import java.util.*;

public class Distance
{

	public static void main(String[] args)
	{
		double x1, x2, y1, y2;
		Scanner scan = new Scanner(System.in);

		System.out.print("x1 of P = ");
		x1 = scan.nextDouble();
		System.out.print("y1 of P = ");
		y1 = scan.nextDouble();
	
		System.out.println();

		System.out.print("x2 of P = ");
		x2 = scan.nextDouble();
		System.out.print("y2 of P = ");
		y2 = scan.nextDouble();
	
		double d = Math.sqrt(Math.pow(x1 - x2, 2.0) + Math.pow(y1 - y2, 2.0) );

		System.out.println("\n\nThe distance between (" + x1 +" , " + y1 + ") and (" + x2 + " , " + y2 + ") is " + d + "\n\n");
	}

}
