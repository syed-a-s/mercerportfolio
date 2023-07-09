
// Author :  Syed Saadat
// Title  :  The GasBill Program

// Input  :  Two integers representing present & previous meter readings 
// Output :  The two integers input will be echoed onto screen with prompts,
//           along with the CCF used.  Three doubles representing the 
//           BTU factor, therms used, and current amount will follow.

import java.util.*;

public class GasBill  {

	public static void main(String [] args)
	{
	 // Declare your four constants HERE
	
	 final double Base_Charge = 22.53;
	 final double BTU_Factor = 1.026;
	 final double Price_Per_Therm = 0.3623;
	 final double Sales_Tax = 0.07;

	 // Prompt and input present meter reading

         System.out.println("\nAtlanta Gas Light Company Billing System\n");
         System.out.print("Enter present meter reading:  ");
         Scanner stdin = new Scanner(System.in);
         int presRead = stdin.nextInt();

         // Prompt and input previous meter reading

       	 System.out.print("Enter previous meter reading: ");
	 int prevRead = stdin.nextInt();
	 int CCFused = presRead - prevRead;
	 double thermsUsed = CCFused * BTU_Factor;

	 // Declare and calculate CCFs used 

	 System.out.print("\nPresent Reading (" + presRead + ") - Previous Reading (" + prevRead + ") = ");
	 System.out.println("CCF Used  (" + CCFused + ")");

	 // Declare and calculate thermsUsed

	 System.out.print("\nCCF used (" + CCFused + ") * BTU Factor (" + BTU_Factor + ") = ");
	 System.out.println("Therms Used (" + thermsUsed + ")");

	 // Declare and calculate consumption charge

	 final double a = 22.53 + (thermsUsed * 0.3623); 
	 final double b = a * 0.07;
	 double Consmp_Charge = a + b;
         Consmp_Charge = Math.round(Consmp_Charge*100.0)/100.0;
	 
	 // Declare and calculate total charges

	 System.out.print("\nCurrent gas amount:$" + Consmp_Charge + "");

	 // All output statements go HERE

	 System.out.println("\n\t(includes tax, base charge, and consumption charge)");

         }
}
