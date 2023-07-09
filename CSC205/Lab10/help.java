
@SuppressWarnings("unchecked")

public class help {
	
      public static void main(String[] args) {
	    
         Node pos1 = null;
         Node pos2 = null;
         pos1 = new Node(new Integer(13));
         pos1.setNext(new Node(new Integer(15), null));
         pos2 = new Node(new Integer(11), null);
         pos2.setNext(pos1);
		  
         count(pos2);
         
	    }
         
      //Method to count the number 
      public static int count(Node head) { 
           
         if (head.getItem() == null)
             return 0;
         else
             return 1 + count(head.getNext());     
                      
      }
}