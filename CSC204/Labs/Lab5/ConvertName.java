import java.util.*;

public class ConvertName {
//  CSC 204 Lab 5: Using classes
//  Written by: Syed Saadat
//  Date: 7/6/20
//  This program illustrates some of the operations in the String class.

   public static void main (String arg [])
   {
    //  Declare and read a string.
       String S;
       Scanner stdin = new Scanner(System.in);
       System.out.println("Enter your name with a nickname : ");
       S = stdin.nextLine();

   //  Find the location of the first double quote (") in the String,
   //  using indexOf.
       int index;
       index = S.indexOf('"');

   //  Take a substring from the first character (in position 0) to the
   //  location you found in the previous step.  You'll need to use the version
   //  of substring with two parameters.  Call the substring firstName.
       String firstName;
       firstName = S.substring(0,index);

   //  Trim the blank spaces off the ends of firstName, using the trim
   //  method.
       firstName = firstName.trim();

   //  Find the location of the last double quote (") in the String, using
   //  lastIndexOf.
       int index2;
       index2 = S.lastIndexOf('"');

   //  Take a substring from the space after the last double quote (whose
   //  position you found in the previous step) to the end of the string.
   //  You'll can use the version of substring with one parameter.  Call this
   //  substring lastName.
       String lastName;
       lastName = S.substring(index2 + 1);

   //  Trim the blank spaces off the ends of lastName, using the trim
   //  method.
       lastName = lastName.trim();

   //  Create and print a new string consisting of the first name, a
   //  single space, and the last name.
       System.out.println(firstName + " " + lastName); 

   }
}
