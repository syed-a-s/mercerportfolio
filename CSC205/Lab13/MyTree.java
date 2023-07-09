
public class MyTree { 

      public static void main(String[] args) { 
      
            BinarySearchTree t = new BinarySearchTree();
            
            t.insert(new KeyedItem("M"));
            t.insert(new KeyedItem("J"));
            t.insert(new KeyedItem("D"));
            t.insert(new KeyedItem("F"));
            t.insert(new KeyedItem("L"));
            t.insert(new KeyedItem("W"));
            t.insert(new KeyedItem("S"));
            t.insert(new KeyedItem("T"));
            t.insert(new KeyedItem("Z"));
            
            System.out.println();
            t.inorder(); System.out.println();
            t.preorder();
            System.out.println(t.countNodes() + "\n");
            
            BinarySearchTree myCopy = new BinarySearchTree();
            t.insert(new KeyedItem("M"));
            t.insert(new KeyedItem("J"));
            t.insert(new KeyedItem("D"));
            t.insert(new KeyedItem("F"));
            t.insert(new KeyedItem("L"));
            t.insert(new KeyedItem("W"));
            t.insert(new KeyedItem("S"));
            t.insert(new KeyedItem("T"));
            t.insert(new KeyedItem("Z"));
            
            if (t.duplicateCheck(myCopy))
                System.out.println("They're Duplicates\n");
            else
                System.out.println("They're Not Duplicates\n");
                
            t.delete("M");
            t.preorder();
      }

}