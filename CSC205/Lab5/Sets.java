
import java.util.*;

public class Sets
{
	private static final int BOUND = 8;
	public static void main(String[] args)
	{
		BitSet set1 = new BitSet(BOUND);
		BitSet set2 = new BitSet(BOUND);
		
		for (int i = 1;  i < BOUND;  i *= 2)
			set1.set(i);

		for (int i = BOUND-1;  i > 0;  i /= 2)
			set2.set(i);
	
		System.out.print("set1 = ");
		print(set1);
		System.out.print("set2 = ");
		print(set2);
   

    String inverse1 = inverse(set1);
    System.out.println("inverse of set1 = " + inverse1);

    String inverse2 = inverse(set2);
    System.out.println("inverse of set2 = " + inverse2);
    
   
   }
   
   //Print the contents of the BitSet
   private static void print(BitSet a)
   {
   for (int i = 1; i < BOUND; i++)
       System.out.print(a.get(i) + " ");
   System.out.println();
   
	 }
   
   //Print the inverse contents of the Bitset
   private static String inverse(BitSet a)
   {
   String binary = "";
   for (int i = 1; i < BOUND; i++)
       if (a.get(i) == true) {
           a.clear(i);
           binary += "0";
       } else { 
           binary += "1"; } 
    
    return binary;    
   
   }
  
}
