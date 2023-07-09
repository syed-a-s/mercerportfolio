import java.util.*;
public class BirthDate
{

	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
	
		System.out.println("Please enter a 6-digit Birthdate: ");
		int bday = scan.nextInt();

		int year = bday % 100;
		int day = bday / 100 % 100;
		int month = bday / 100 / 100;

		System.out.println("Month = " + month);
		System.out.println("Day = " + day);
		System.out.println("Year = " + "19" + year);
	}

}
