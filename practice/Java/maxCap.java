import java.io. *;
import java.util. *;

public class maxCap { 

    public static void main(String[] args) {

        int pocketCash = 50, storedCash = 0, maxCash = 30;
        Scanner scan = new Scanner(System.in);

        // fix - person can still cash out as long they enter a neg number
        while(true) { 
            int diff = 0, n = 0;
            System.out.println("\nCash on You : " + pocketCash);
            System.out.print("Deposit Amount : ");
            n = scan.nextInt();
            
            // to break loop
            if(n == 0)
                break;

            // to check if you're depositing more cash than you 
            // actually can
             if(pocketCash >= n) { 
                pocketCash = pocketCash - n;
            } else { 
                // continue or you will give back incorrect funds
                System.out.println("Insufficient funds!");
                continue;
            }
            
            // update bank account
            storedCash = n + storedCash;

            // if more money deposited than storage can hold
            if(storedCash > maxCash) { 
                // excess cash recieved refunded to user
                diff = storedCash - maxCash;
                pocketCash = pocketCash + diff;
                diff = 0;
                // storedcash over max so set it back to max 
                storedCash = maxCash;
            }

            if(storedCash == maxCash)
                System.out.println("Storage full!");
            
            System.out.println(storedCash + " / " + maxCash);
        }

    }

}
