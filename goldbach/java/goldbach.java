import java.io.*;
import java.util.*;
import java.lang.Math;

public class goldbach {

      public static void main(String[] args) { 

	    Scanner scan = new Scanner(System.in);
            System.out.print("Enter an odd number greater than 7 : ");
            int sum = scan.nextInt();
            
            if((sum > 7) && (sum % 2 == 1)) { 
                  ArrayList<Integer> primeNums = new ArrayList<Integer>();
                  primeNums = StorePrime(sum);
	                FindMinTriplet(primeNums, sum);
            } else { 
                  System.out.println("Please enter a number that is ODD and greater than 7!");
            }

      }
     
      // Puts all prime numbers from 1 to user input into an array list 
      public static ArrayList<Integer> StorePrime(int n) {
      
            ArrayList<Integer> primeNums = new ArrayList<Integer>();
            
            for(int i = 1; i < n; i++) { 
                  if(IsPrime(i))
                        primeNums.add(i);
            }  
             
            return primeNums;
            
      }
      
      // Checks if a number given is prime
      public static boolean IsPrime(int n) { 
      
            boolean prime = true;
            
            for (int i = 2; i < n; i++) {
                  if(n % i == 0) {
                        prime = false;
                        break;
                  } 
            }
            
            return prime;
      
      }    
      
      // Finds the triplet sum with the lowest norm 
      public static void FindMinTriplet(ArrayList<Integer> nums, int sum) { 

            int l, r;
     	    double norm = Double.POSITIVE_INFINITY;
            int[] triplet = new int[3];
            
            for(int i = 0; i < nums.size() - 2; i++) { 
                  l = i + 1;
                  r = nums.size() - 1;
                  while(l < r) { 
                        if(nums.get(i) + nums.get(l) + nums.get(r) == sum) { 
                              if((NormOf(nums.get(i), nums.get(l), nums.get(r))) <= norm) { 
                                    norm = NormOf(nums.get(i), nums.get(l), nums.get(r));
                                    triplet[0] = nums.get(i);
                                    triplet[1] = nums.get(l);
                                    triplet[2] = nums.get(r);
                              }
                              l++;
                              r--;
                        } else if(nums.get(i) + nums.get(l) + nums.get(r) < sum) {
                              l++;
                        } else { 
                              r--;
                        }
                  }
            }

	          System.out.println(sum + " : " + "(" + triplet[0] + ", " + triplet[1] + ", " + triplet[2] +")");

     }
     
     // Finds the norm of 3 given numbers      
     public static double NormOf(double i, double j, double k) { 
      
	         double norm = Math.sqrt((i*i) + (j*j) + (k*k));
	         return norm; 
      
     }

}
