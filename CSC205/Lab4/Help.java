import java.util.*;
public class Help
{
    public static void main(String[] args)
    {
      ArrayList<String> myArrayList = new ArrayList<String>(10);
      
      myArrayList.add("1");
      myArrayList.add("2");
      myArrayList.add("3");
      myArrayList.add("4");
      myArrayList.add("5");
      myArrayList.add("6");
      myArrayList.add("7");
      myArrayList.add("8");
      myArrayList.add("9");
      myArrayList.add("10");
      
      //System.out.println(myArrayList.size());
      Scanner scan = new Scanner(System.in);
      int a = scan.nextInt();
      System.out.println(myArrayList.get(a));
      
    }
    
}



    private static void delete(ArrayList<String> myArrayList, Object key)
    {
	// Pre  : myArrayList has been initialized
	// Post : All copies of key are removed from myArrayList



    }

    private static int count(ArrayList<String> myArrayList, Object key)
    {
	// Pre  : myArrayList has been initialized
	// Post : number of occurrences of key is computed and returned



    }