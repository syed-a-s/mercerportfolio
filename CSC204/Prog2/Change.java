//-------------------------------------------------------------------
// Programmer   : Syed Saadat
// Class        : Dr. Digh's CSC204
// Title        : Change
//-------------------------------------------------------------------
// Program Specifation:
//
// Input        : Two double (total due and amount recieved
//
// Output       : Seven integers (change due plus the appropriate number
//                of hundreds, fifties, twenties, tens, fives, and
//                ones to be distributed)
//-------------------------------------------------------------------

import java.util.*;

public class Change
{
      public static void main (String[] args)
	{
	          int total, tendered, change, changeleft,CheckChange;
            int hunds, twnts, fift, tens, fives, ones;
            char a;
            char again = 'N';
            while(again == 'N')
            {
 
            // Prompt clerk to input the amount due and the amount tendered
            
            System.out.print("\nTotal Due (in dollars) : $ ");                 
            Scanner scan = new Scanner(System.in);
            total = scan.nextInt();
            
            System.out.print("\nAmount tendered (in dollars) : $ ");
            tendered = scan.nextInt();
            
           
         
	          CheckChange = tendered - total;     // The dollar change to check which IF statement to run
           
            if(tendered < total)                                                                    
            {
            Scanner scan2 = new Scanner(System.in);      
            System.out.println("\nInsufficient Funds. Does the customer need to visit an ATM? (Y/N) "); // Asking customer if they need to grab more money. 
            a = scan2.next().charAt(0);                                                                 // If yes, the program ends. If no, the program restarts 
                if(a == 'Y')
                { 
                System.out.println("\nOkay\n"); 
                again = 'Y';
                }
                else if (a == 'N');  
            }
             
            if(CheckChange >= 0)                                                
            {
            System.out.println();                                                    // Prints Out the Change Due Here
            System.out.println("******************************************");
  
            change = tendered - total;
            System.out.print("Amount of Change Due (in dollars) : $ ");
            System.out.print(change);
         
            System.out.println("\n******************************************");      // Blank space, just ignore
            System.out.println(); 
            System.out.println("******************************************");       
            System.out.println("     How Change Should be Distributed");           
            System.out.println("******************************************");        // End of blank Space 
            
            // The Calculations of the Dollar Bills Start Here  
              
              hunds         = change / 100; 
              changeleft    = change % 100;
              fift          = changeleft / 50;
              changeleft    = changeleft % 50;
              twnts         = changeleft / 20;
              changeleft    = changeleft % 20;
              tens          = changeleft / 10;
              changeleft    = changeleft % 10;
              fives         = changeleft / 5;
              ones          = changeleft % 5;
              
            // Printing Out Dollar Bills
           
	           System.out.println("Number of Hundreds => $" + hunds);
            System.out.println("Number of Fifties => $" + fift);
            System.out.println("Number of Twenties => $" + twnts);
            System.out.println("Number of Tens => $" + tens); 
            System.out.println("Number of Fives => $" + fives);
            System.out.println("Number of Ones => $" + ones);
            System.out.println("******************************************");
            
            again = 'Y';
             
            }  } 
            }
               
}    
