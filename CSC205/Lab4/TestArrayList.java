import java.util.*;
public class TestArrayList
{
    public static void main(String[] args)
    {
	    ArrayList<String> myArrayList = new ArrayList<String>(10);
         
      myArrayList.add("Python");
      myArrayList.add("Java");
      myArrayList.add("Java");
      myArrayList.add("Java");
      myArrayList.add("Java");
      myArrayList.add("Java");
      myArrayList.add("C++");
      myArrayList.add("C++");
      myArrayList.add("C++");
      myArrayList.add("C++");
      
      printArrayList (myArrayList);
      
      delete (myArrayList, "Java");
      
      printArrayList (myArrayList);
      
      int a = count(myArrayList, "C++");
      
      System.out.println("C++ appears " + a +" time(s)."+ "\n");

    }

    private static void printArrayList(ArrayList<String> myArrayList)
    {
	  // Pre  : myArrayList has been initialized
	  // Post : The elements of Vector v are printed to the screen on separate lines
 
     for (int i = 0;  i < myArrayList.size();  i++)
         System.out.println(myArrayList.get(i));
         
    }
    
    private static void delete(ArrayList<String> myArrayList, Object key)
    {
	  // Pre  : myArrayList has been initialized
	  // Post : All copies of key are removed from myArrayList
     
     System.out.println();
     for(int i = 0; i < myArrayList.size(); i++)
         if( myArrayList.get(i) == key )
             myArrayList.remove(i);

    }
    
    private static int count(ArrayList<String> myArrayList, Object key)
    {
	  // Pre  : myArrayList has been initialized
	  // Post : number of occurrences of key is computed and returned
     
     System.out.println();
     int count = 0;
     for(int i = 0; i < myArrayList.size(); i++)
         if( myArrayList.get(i) == key )
            count++;
            
     return count;

    }

}
