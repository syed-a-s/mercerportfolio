
public class blowUp {

     public static int counter = 0; 

     public static void main(String[] args) {

	          blowUp(args);

     }

     public static void blowUp(String[] args) {
 
	          System.out.println(counter);
            counter++;
            blowUp(args);
	
     }
}
