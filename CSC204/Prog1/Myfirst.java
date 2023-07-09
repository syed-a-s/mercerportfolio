import java.util.*;

public class Myfirst
{
	public static void main(String [] args)
	{
		// Variable used in this program
		String personName;

		// Beginning of main logic

		personName = getName(); // calling value-returning method get name
		printOut(personName);   // calling void method printOut
	}

	private static String getName()
	{
		// This method will get the name of the user and
		// return it to the main function

		Scanner stdin = new Scanner(System.in);
		System.out.print("Please enter your first name : ");
		String userInput = stdin.next();

		return userInput;
	}

	private static void printOut(String personName)
	{
		// This method will pring a congratulatory message to
		// a person with the name personName

		System.out.println("\nCongratulations " + personName +
				  " on running your first Java program!!!\n\n");
	}

}
