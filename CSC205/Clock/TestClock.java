import java.util.*;
public class TestClock
{
   public static void main(String[] args)
   {
       int hr, min, sec;
       System.out.print("\nWhat time would you like to set your DVR to?");
       
       Scanner scan = new Scanner(System.in);
       Clock clock = new Clock();
       
       System.out.print("\n\nHours = ");
       hr = scan.next(). charAt(0);
       System.out.print("Minutes = ");
       min = scan.next().charAt(0);
       System.out.print("Seconds = ");
       sec = scan.next().charAt(0);
       
       Clock(hr, min, sec);
       clock.toString();
       clock.Advance();
       clock.toString();
       System.out.println();
       
   }
   
}
       
       