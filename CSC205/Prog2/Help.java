import java.io. *;
import java.util. *;

public class Help
{
	private static int NUM = 10;
	public static void main(String[] args)
  {
    //LibraryBook books = new LibraryBook("ojasdak", "man", 1994, 23, "f");
    //LibraryBook books2 = new LibraryBook("ojk", "man", 1994, 23, "f");
    //int found = books2.compareTo(books);
    //System.out.println(found);
    
      ArrayList<LibraryBook> books = new ArrayList<LibraryBook>(50);
      books.add(new LibraryBook("ojasdak", "man", 1994, 23, "f"));
      
      ArrayList<LibraryBook> books2 = new ArrayList<LibraryBook>(50);
      books2.add(new LibraryBook("ojasdak", "man", 1994, 23, "f"));
      
      
      System.out.println(books2.get(0).compareTo(books.get(0)));
      System.out.println(books.get(0).getTitle());

  }
  

  
}



         if ( CHECK != 0 ) {
         System.out.println("\n\t  That book was not found");
         break;
         } else {
             clearScreen();
             printRecord(books, x);  
             System.out.print("\n\t  Press Enter to Continue...");
             ENTER = scan.nextLine();
             clearScreen();
             printMenu();
             chooseMenu(books, numBooks); 
         }
         


    if ( CHECK != 0 ) {
         System.out.println("\n\t  That book was not found");
         System.out.print("\n\t  Press Enter to Continue...");
         ENTER = scan.nextLine();
         clearScreen();
         printMenu();
         chooseMenu(books, numBooks); 
         
    int CHECK = -1, x = 0; // I used x to replace the i in the for loop later, I don't know why i won't work
    String bookWanted = "", ENTER = "";
    
    // Asking the user what book needs to be found
    Scanner scan = new Scanner(System.in);
    System.out.print("\n\t  Search Book > ");
    bookWanted = scan.nextLine();
    
    // Finding out if the book exists with a for loop
    do {
    
      for ( int i = 0; i < numBooks; i++ )
      {
      CHECK = (bookWanted.compareTo(books.get(i).getTitle()));
        if ( CHECK == 0 ){
           clearScreen();
           printRecord(books, i);  
        }
      x++;
      }     
       } while ( CHECK != 0 );
         {
           if ( CHECK == 0 )
           {
             System.out.print("\t  Press Enter to Continue...");
             ENTER = scan.nextLine();
             printMenu();
             chooseMenu(books, numBooks);

           }
         } 
      
  }
         
         
         
         
         
         
         
         
         
      try{
          int first = 0, last = numBooks, middle, location;
          String key = " ";
          boolean found = false;

          //Asks user what book they are searching for, and does a binary search through the array
                System.out.print("\n\t  Which book would you like to search for?");
                Scanner in = new Scanner(System.in);
                key = in.nextLine();                                    //This scanner allows them to put in the title they are searching for and sets it as the "key" for binary search

                do{
                        middle = (first + last) / 2;

                        if (key.equals(books.get(middle).getTitle()))
                                found = true;
                        else if (key.compareTo(books.get(middle).getTitle()) < 0)       //Binary Search
                                last = middle - 1;
                        else
                                first = middle + 1;
                } while ( (! found) && (first <= last) );
                if(!found )
                        System.out.print("Sorry, this book was not found.");            //If it does not find it book, prints this message, otherwise it prints the book record.
                else{
                location = middle;
                printRecord(books, location);
                }
            }
                catch (Exception e){
                System.out.println("Sorry, this book was not found.");          //I had a strange bug with certain strings, so this catches it and returns a "not found" message instead of crashing
        }