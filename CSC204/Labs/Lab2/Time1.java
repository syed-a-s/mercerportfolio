// Author : Syed Saadat
// Title  : The Time Program 
// Input  : A single integer representing a given number of hours
// Output : A single integer representing the total number of seconds in the given number of hours input

import java.util.*;     // Package needed when using Scanner class
public class Time1 
{
	public static void main (String[] args)
	{
	  final int SEC_IN_MIN = 60;		// constant value for SEC_IN_MIN
	  final int MIN_IN_HR = 60;             // constant vaulue for MIN_IN_HR

	  Scanner stdin = new Scanner(System.in);
	  System.out.print("Please enter the number of hours:  ");

	  int hrs = stdin.nextInt();   // Input hrs as String
	  int total_sec = hrs * MIN_IN_HR * SEC_IN_MIN;

	  System.out.print("Total Seconds:  ");
	  System.out.println(total_sec + "\n\n");
	}
}
