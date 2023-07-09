import java.util.*;
public class help
{
   public static void main(String[] args)
   
   {
     final int NUM_STUDENTS = 100;
     boolean[] failing = new boolean[NUM_STUDENTS];
     initialize(failing);
   }
   
   private static void initialize(boolean[] failing)
   
	 {
     Arrays.fill(failing, Boolean.FALSE);
	 }
    
}
         
