import java.io. *;
import java.util. *;

public class GreatBooks
{
	
	public static void main(String[] args)
	{
    // Title and choosing the file
    clearScreen();
		System.out.println("\n\t\t\t  THE BOOK SEARCH PROGRAM");
    System.out.println("--------------------------------------------------------------------------------\n");
    System.out.println("\t  What file is your book data stored in?\n");
    System.out.println("\t  Here are the files in the current directory : \n");
    
    File currentDirectory = new File(".");
    String[] fileNames = currentDirectory.list();
    for(int i = 0; i < fileNames.length; i++)
        System.out.print("\t  " + fileNames[i] + "\n");
    System.out.println();
    
    // Declaring arraylist of books 
    ArrayList<LibraryBook> books = new ArrayList<LibraryBook>(50);
     
    // Finding the number of books in file
    Scanner scan = new Scanner(System.in);
    System.out.print("\t  Filename : ");
    String fileWanted = scan.nextLine();        
    int numBooks = inputBooks(fileWanted, books);
    
    // Sorting the array of books in ArrayList books
    sortBooks(numBooks, books);

    // Printing out the number of books, the books are also sorted by now 
    System.out.println("\n\t  A total of " + numBooks + " books have been input & sorted by title\n");
    
    String CHECK = "a";
    while ( ! CHECK.equals("") ) {
    System.out.print("\t  Press the Return Key to Continue... ");
    CHECK = scan.nextLine();
      if ( ! CHECK.equals("") )
        System.out.println("\t  You have made an error. Please try again.");
      else
        clearScreen();
   }
   
   // Calling menu and the its actions
   printMenu();
   chooseMenu(books, numBooks);

   
   
	}
 
  // Clear Screen Method 
  
  private static void clearScreen()
  {
      System.out.println("\u001b[H\u001b[2J");
  }
  
  // Method to count the number of books in a  file 
  
  public static int inputBooks(String inputFile, ArrayList<LibraryBook> books) 
  {
          int numBooks = 0;
          try { 
                    Scanner in = new Scanner(new File(inputFile));
                    while (in.hasNext())
                    {
                      Scanner lsc = new Scanner(in.nextLine()).useDelimiter(";");
                      
                      String title = lsc.next();
                      String name = lsc.next();
                      int copyright = lsc.nextInt();
                      double price = lsc.nextDouble();
                      String genre = lsc.next();
                      
                    books.add(new LibraryBook(title, name, copyright, price, genre));
                      numBooks++;
                     }
                     
                } 
                catch (IOException e) {
                        System.out.println(e.getMessage());
                }          
                return numBooks;
                        
  }
  
  // Method to sort the Books in arraylist
  
  public static void sortBooks(int numBooks, ArrayList<LibraryBook> books)
        { 
        //Performs a selection sort on the books array list. Sorts them alphabetically by title.
                int minIndex, i, j;
                LibraryBook temp = new LibraryBook("", "", -1, -1, "");
                for (i = 0; i < numBooks; i++)
                {
                        minIndex = i;
                        for (j = minIndex+1; j < numBooks; j++)  //have to alter the selection sort code to work on string, and in arraylists.

                        if(books.get(j).compareTo(books.get(minIndex)) < 0)
                                minIndex = j;

                        if (minIndex != i)   //Swapping the books
                        {
                        temp = books.get(minIndex);
                        books.set(minIndex, books.get(i));
                        books.set(i, temp);
                        }
                }
        }
  
  

  // Method to make the menu  
  
  public static void printMenu()
  {
   System.out.println();
   System.out.println("\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   System.out.println("\t\t   THE GREAT BOOKS SEARCH PROGRAM");
   System.out.println("\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   System.out.println("\t  1)  Display all book records");
   System.out.println("\t  2)  Search for a book by Title");
   System.out.println("\t  3)  Exit Search Program");
   System.out.println("\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   System.out.print("\t  Please Enter Your Choice > ");
  
  }
  
  // Choose Menu 1, 2, or 3
  
  public static void chooseMenu(ArrayList<LibraryBook> books, int numBooks)
  {
   int choice = 0;
   String next = "a";
   Scanner scan = new Scanner(System.in);
   choice = scan.nextInt();
   
   while ( choice > 0 && choice < 3 )
     {
         if ( choice == 1 )
         {
             clearScreen();
             printRecord(books, 0);
             menu1(books, numBooks);
         }  
         
         if ( choice == 2 )
         {
             menu2(books, numBooks);         

         }
              
     }
    if ( choice == 3 ) 
       menu3();
     
   }
   
  // Method for Menu 1
  
  public static void menu1(ArrayList<LibraryBook> books, int numBooks)
  {
    String CHECK = "a";
    Scanner scan = new Scanner(System.in);
    
    for ( int i = 1; i < numBooks; i++ )
    { int x = 1;
        while ( ! CHECK.equals("") )
        {
          System.out.print("\t  Press Return to Continue or M for Menu... ");
          CHECK = scan.nextLine();
          CHECK = CHECK.toLowerCase();
            if ( CHECK.equals("m") ) {
              clearScreen();
              x = 0;
              break;
            } else if ( ! CHECK.equals("") ) {
              System.out.println("\t  You have made an error. Please try again.");
            } else  {
                clearScreen();
                printRecord(books, x);
                CHECK = "a"; 
                x++; 
                  if ( x == numBooks ) {
                      x = 0;                    
                  } 
            }
         }
      // Returns to Menu
      if ( CHECK.equals("m") )
          printMenu();
          chooseMenu(books, numBooks);
          break; 
     }
   }
   
  // Method for Menu 2 
  
  public static void menu2(ArrayList<LibraryBook> books,int numBooks)
  {
      String FakeCheck = "";
      try{
          int first = 0, last = numBooks, middle, location;
          String key = " ";
          boolean found = false;

          //Asks user what book they are searching for, and does a binary search through the array
                System.out.print("\n\t  Search Book > ");
          //This scanner allows them to put in the title they are searching for and sets it as the "key" for binary search
                Scanner in = new Scanner(System.in);
                key = in.nextLine();            

                do{
                        middle = (first + last) / 2;

                        if (key.equals(books.get(middle).getTitle()))
                                found = true;
                        else if (key.compareTo(books.get(middle).getTitle()) < 0)       //Binary Search
                                last = middle - 1;
                        else
                                first = middle + 1;
                } while ( (! found) && (first <= last) );
                //If it does not find it book, prints this message, otherwise it prints the book record.
                if(!found )
                        System.out.print("Sorry, this book was not found.");
                else{
                location = middle;
                clearScreen();
                printRecord(books, location);
                }
            }
                catch (Exception e){
                System.out.println("Sorry, this book was not found.");   //I had a strange bug with certain strings, so this catches it and returns a "not found" message instead of crashing
        }
  }
  
  // Method for Menu 3
  
  public static void menu3()
  {
    clearScreen();
    System.out.println("\t  Goodbye. Have a good day :)\n");
     
  } 

  // Print the book info at the specified slot
    
  public static void printRecord(ArrayList<LibraryBook> books, int location) 
  {   
   System.out.println("\t  Record #" + (location + 1) + " :\n");
   System.out.println("\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");   
   System.out.println("\t  Title:          \t\t\t" + books.get(location).getTitle());   
   System.out.println("\t  Author's Name: \t\t\t" + books.get(location).getAuthor());   
   System.out.println("\t  Copyright:   \t\t\t\t\t" + books.get(location).getCopyright());   
   System.out.println("\t  Price:         \t\t\t\t" + books.get(location).getPrice());   
   System.out.println("\t  Genre:    \t\t\t\t" + books.get(location).getGenre());
   System.out.println("\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
   
  }
  
}  
