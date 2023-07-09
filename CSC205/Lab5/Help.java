import java.util.*;
public class Help
{
  private static final int BOUND = 8;
  public static void main(String[] args)
  {
		BitSet set1 = new BitSet(BOUND);
		BitSet set2 = new BitSet(BOUND);
   
   set1.set(0);
   set1.set(1);
   set1.set(2);
   set1.set(3);
   String a = set1.toString();
   System.out.println(a);
   System.out.println(set1.get(3));
    
  }
  
   
}