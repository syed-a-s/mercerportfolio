import java.util.*;

public class TestFract {
//  CSC 204 Lab 5: Using classes
//  Written by: Syed Saadat
//  Date: 7/5/20
//  This program illustrates some of the operations in the Fraction class.

   public static void main (String arg [])
   {
    // All Variables
    int numerator, denominator, numerator2, denominator2;
    String first, sec;
    int index, index2;
    Fraction f1, f2;
    
    // Asking user for fractions
    
    Scanner scan = new Scanner(System.in);
    System.out.println();
    System.out.print("Enter the first fraction (x/y) : ");
    first = scan.nextLine();
    System.out.print("Enter the second fraction (x/y) : ");
    sec = scan.nextLine();
    
    // Getting rid of "/" and turning string to int
    
    index = first.indexOf("/");
    numerator = Integer.parseInt(first.substring(0, index).trim());
    denominator = Integer.parseInt(first.substring(index + 1).trim());
    
    index2 = sec.indexOf("/");
    numerator2 = Integer.parseInt(sec.substring(0, index2).trim());
    denominator2 = Integer.parseInt(sec.substring(index2 + 1).trim());
  
    // Calculations
    
    f1 = new Fraction (numerator, denominator);
    f2 = new Fraction (numerator2, denominator2);

    Fraction result, b, c, d;
    result = f1.add (f2);
    b = f1.subtract (f2);
    c = f1.multiply (f2);
    d = f1.divide (f2);
    
    System.out.println();
    System.out.println("The first fraction is " + f1);
    System.out.println("The second fraction is " + f2);
    System.out.println("The sum is " + result);
    System.out.println("The difference is " + b);
    System.out.println("The product is " + c);
    System.out.println("The quotient is " + d + "\n");
   }
}
