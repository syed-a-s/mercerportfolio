
// Program Mixed demonstrates more on precedence of operators
// and what happens in mixed-mode arithmetic

public class Ex5
{
	public static void main (String[] args)
	{
		double doubValue = 3.14159;
		int intValue = 5;

		System.out.println (intValue / intValue);
		System.out.println ((double) intValue / intValue);
	
		intValue++;
		System.out.println (intValue % 4);
		System.out.println (intValue);
		System.out.println (21 % 10);
		System.out.println (66 % 10);
		System.out.println (21 / intValue);
		
		intValue = (int) (doubValue + intValue);
		System.out.println (intValue);

		doubValue = (double) intValue;
		System.out.println (doubValue / (double) intValue);
	}
}
