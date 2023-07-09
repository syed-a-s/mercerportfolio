import java.util.*;
import java.io.*;
public class Crypt
{
   public static void main(String[] args)
   { 
     char a = 'Y';        // Loop for the rerun
     while(a == 'Y')
     {
     intro();             // Intro
    
     int displace = getPassword();       // Getting Password + converting to ASCII value
    
     String ifilename = getFileName("Source File ==> ");        // Select file name
    
     char b = getType();           // b is either encrypt or decrypt
     
     Scanner scan = new Scanner(System.in);
     System.out.print("\n\t\tOutput File ==> ");
     String ofilename = scan.nextLine();
     
     crypt(ifilename,  ofilename, displace, b);
     
     a = rerunPrompt();            // Prompt to rerun or not
     if ( a == 'N')
       System.out.println("\n\t\t!!! Exiting Security System !!!\n");
     
     }
   }

   private static void intro()
   {	
  // Prints the welcome message
     System.out.println("\t\t======================================\t");
     System.out.println("\t\t\tTEXT FILE SECURITY SYSETM\t\t");
     System.out.println("\t\t======================================\t");
   }

   private static int getPassword()
   {	
  // Inputs the password
  
     System.out.print("\t\tEnter Your Password ==> ");
     	
	// Prompt user to enter password
 
   	 Scanner scan = new Scanner(System.in);
     String password = scan.nextLine();
     
	// Add the ascii values of the characters and return sum % 96 which will become displacement value
 
     int sum = 0;
     for ( int i = 0; i < password.length(); i++ )
     {
     int asciiValue = password.charAt(i);
     sum += asciiValue;
     }
     return sum = sum % 96;
   } 

   private static String getFileName(String prompt)
   {	
   // Print out the parameter prompt.  Declare a Scanner to input their filename & return it.
      Scanner scan = new Scanner(System.in);
      System.out.print("\n\t\t" + prompt);
      String filename = scan.nextLine();
      return filename;

   }
   
   private static char getType()
   {	
   // Prompt user to enter either E to encrypt or D to decrypt.  If not E or D, loop until correct.
      String type; boolean valid;
      do
      {
        Scanner scan = new Scanner(System.in);
        System.out.print("\n\t\t" + "Encrypt or Decrypt? (E/D) ");
        type = scan.nextLine().toUpperCase();
        valid = type.equals("E") || type.equals("D");
        if(!valid)
        System.out.println("\tInvalid Selection -- Please Try Again.");
      } while (!valid);
      return type.charAt(0);
   }

   private static char rerunPrompt()
   {	
   // Prompt the user to enter Y to go again or N to stop.  If not Y or N, loop until correct.
        
    char repeat;	
    System.out.print("\n\t\tAnother File? (Y/N) ");
    Scanner scan = new Scanner(System.in);
    repeat =  scan.next().charAt(0);
    return repeat;
    
   }
   private static void crypt(String ifilename, String ofilename, int displace, char type)
   {	// Encrypts the file in ifilename and outputs it to ofilename

	try {
	   // Create input and output file objects to work with
           Scanner in = new Scanner(new File(ifilename));
           PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(ofilename)));

	   int coef = (type == 'E') ? 1 : -1;
	   
	   // Loop until end of file...read a line, encrypt it character by character, and 
	   // write the line to the output file
	   String line;
	   char ch;
	   int linesProcessed = 0, charsCrypted = 0;
	   while(in.hasNext())
	   {
		line = in.nextLine();
		
		// Encrypt the line
		for (int i = 0; i < line.length(); i++)
		{
		   if (line.charAt(i) != '\t')
		   {
			int ascii = (int) line.charAt(i) + (displace * coef);

			// Keep printable characters
			if (coef == 1)
			{
			   if (ascii > 126)
				ch = (char) (ascii - 126 + 31); 
                           else
                                ch = (char) (ascii);
			}
			else
		  	   if (ascii < 32)
				ch = (char) (127 - (32 - ascii));
                           else
                                ch = (char) (ascii);

			line = line.substring(0, i) + ch + line.substring(i + 1);
			charsCrypted++;
		   }
		}	   

		// Write the line to the output file
		out.println(line);
		linesProcessed++;
	   }
	   
	   in.close();
	   out.close();
	   System.out.println("\t\t\t   Lines processed :  " + linesProcessed +
			    "\n\t\t\tCharacters crypted :  " + charsCrypted);

	}
	catch (IOException e)
	{
	   System.err.println(e.getMessage());
	}
   }
}
