
@SuppressWarnings("unchecked")

public class Links {
	
      public static void main(String[] args) {
	    
         Node pos1 = null;
         Node pos2 = null;
         pos1 = new Node(new Integer(13));
         pos1.setNext(new Node(new Integer(15), null));
         pos2 = new Node(new Integer(11), null);
         pos2.setNext(pos1);
		  
         printList(pos2);
         count(pos2);
         findMax(pos2);
         
	    }

	    private static void printList(Node head) {
		
           if (head != null) {
			        System.out.println(head.getItem());
			        printList(head.getNext());
           }
      }
      
      //Method to count the number 
      public static int count(Node head) { 
           
            if (head.getItem() == null)
                return 0;
            else
                return 1 + count(head.getNext());
                
      }
 
      //Method to find max value in linked list
      private static Object findMax(Node head) {
      
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
