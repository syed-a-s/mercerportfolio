import java.util.*; 

public class Exam2
{
 public static void main (String[] args)
 { 
  String currMin = "ZZZ", currMax = "AAA";
  Scanner scan = new Scanner(System.in);
  System.out.println("Please enter 4 Strings: ");
  String s1, s2, s3, s4;
  s1 = scan.nextLine();
  if (s1.compareTo(currMin) < 0)
        currMin = s1;
  else if (s1.compareTo(currMax) > 0)
        currMax = s1;
  
  // Answer starts here 
  
  s2 = scan.nextLine();
  if (s2.compareTo(currMin) < 0)
        currMin = s2;
  else if (s2.compareTo(currMax) > 0)
        currMax = s2;
        
  s3 = scan.nextLine();
  if (s3.compareTo(currMin) < 0)
        currMin = s3;
  else if (s3.compareTo(currMax) > 0)
        currMax = s3;
        
  s4 = scan.nextLine();
  if (s4.compareTo(currMin) < 0)
        currMin = s4;
  else if (s4.compareTo(currMax) > 0)
        currMax = s4;
  
  System.out.println("\nThe lexicographic minimum is " + currMin);
  System.out.println("\nThe lexicographic maximum is " + currMax + "\n");
 }

}
