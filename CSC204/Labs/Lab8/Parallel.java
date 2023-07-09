
import java.util.*;

public class Parallel
{
  public static void main(String[] args)
  {
	char[] a = {'C', '$', 'd', 'Z'};
        boolean[] b = {false, false, true, false};
  	String[] c = {"baseball", "basketball", "golf", "tennis"}; 
	Fraction[] d ={new Fraction(1,2), new Fraction(2,3),
	               new Fraction(-2,5), new Fraction(12,25)};

	for (int k = 3;  k >= 0;  k--) 
	{
		System.out.print(a[k] + " " + b[k] + " " + d[k] + " ");

		if (c[k].compareTo("basketball") < 0)
			System.out.println("Before basketball");
	        else if (c[k].compareTo("basketball") > 0)
			System.out.println("After basketball");
		else
			System.out.println("Hoops Time!");
	}
  }
} 
