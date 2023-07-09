
import java.util.*;

public class Telephone
{
  public static void main(String[] args)
  {
        System.out.println("\t\t\7@@@@@@ THE TELEPHONE PAD CONVERTER @@@@@@\n");
	System.out.println("\t Software that converts letters into telephone" +
		           " digits!\n\n");

	System.out.print("\t Please enter an uppercase character ==> ");
        Scanner stdin = new Scanner (System.in);
	String userInput = stdin.nextLine();

	// Use the String method charAt to convert our input into a char
   
   char a = userInput.charAt(0);
   int digit = 0;

  // Complete the Program HERE using a Nested-If Statement	
  
   if((a == 'A') || (a == 'B') || (a == 'C')) {
    digit = 2;
   } else if((a == 'D') || (a == 'E') || (a == 'F')) {
    digit = 3;
   } else if((a == 'G') || (a == 'H') || (a == 'I')) { 
    digit = 4;
   } else if((a == 'J') || (a == 'K') || (a == 'L')) {
    digit = 5;
   } else if((a == 'M') || (a == 'N') || (a == 'O')) {
    digit = 6;
   } else if((a == 'P') || (a == 'R') || (a == 'S')) {
    digit = 7;
   } else if((a == 'T') || (a == 'U') || (a == 'V')) { 
    digit = 8;
   } else if((a == 'W') || (a == 'X') || (a == 'Y')){
    digit = 9;}
    else 
         System.out.println("\n\t The letter " + userInput + " is not used"
         + " on a telephone.\n");
   if(digit > 0)      
         System.out.println("\n\t The digit " + digit + " corresponds to the letter " 
         + a + " on the telephone.\n");
   
         
   }
   
}
