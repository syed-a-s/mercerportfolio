
import java.io.*;
@SuppressWarnings("unchecked")

public class MaxTest 
{
   public static void main(String[] args) throws IOException, CloneNotSupportedException
   {
        	Stack stack1 = new Stack();
		stack1.push("Andy");
		stack1.push("Allison");
		stack1.push("Aaron");
		stack1.push("Austin");
		stack1.push("Abbey");
		stack1.push("Alex");
        	System.out.println("findMax(stack1)=" + findMax(stack1)); 
        	//System.out.println("stack1.findMax()="+stack1.findMax()); 
  
  }
  
  public static Object findMax(Stack stack) { 
  
      Stack curr = stack;
      Comparable currMax = (Comparable) stack.top();
      
      while (curr != null) { 
          Comparable currItem = (Comparable) curr.top();
          if (currItem.compareTo(currMax) > 0)
              currMax = (Comparable)curr.top(); 
          
          curr = curr.pop();
      
      }
      return(currMax);
      
  }

}
