using System;
using System.Collections;
using System.Collections.Generic;

public class goldbach {

      public static void Main() { 
      
            Console.Write("Enter an odd number greater than 7 : ");
            int sum = Convert.ToInt32(Console.ReadLine());
        
            if((sum > 7) && (sum % 2 == 1)) { 
                  ArrayList primeNums = new ArrayList();
                  primeNums = StorePrime(sum);
	                FindMinTriplet(primeNums, sum);
            } else { 
                  Console.WriteLine("Please enter a number that is ODD and greater than 7!");
            }        
            
      }
      
      // Stores all prime numbers from 1 to user input into an array
      public static ArrayList StorePrime(int n) {
      
            ArrayList primeNums = new ArrayList();
            
            for(int i = 1; i < n; i++) { 
                  if(IsPrime(i))
                        primeNums.Add(i);
            }
            
            return primeNums;            
            
      }
      
      // Checks if a given number is prime
      public static bool IsPrime(int n) {

            bool prime = true;

            for (int i = 2; i < n; i++) {
                  if( n % i == 0) {
                        prime = false;
                        break;
                  }
            }

            return prime;

      }

      // Finds the triple sum with the lowest norm
      public static void FindMinTriplet(ArrayList nums, int sum) { 

            int l, r;
     	    double norm = Double.PositiveInfinity;
            int[] triplet = new int[3];
            
            for(int i = 0; i < nums.Count - 2; i++) { 
                  l = i + 1;
                  r = nums.Count - 1;
                  while(l < r) { 
                        if(Convert.ToInt32(nums[i]) + Convert.ToInt32(nums[l]) + Convert.ToInt32(nums[r]) == sum) { 
                              if(NormOf(Convert.ToInt32(nums[i]), Convert.ToInt32(nums[l]), Convert.ToInt32(nums[r])) <= norm) { 
                                    norm = NormOf(Convert.ToInt32(nums[i]), Convert.ToInt32(nums[l]), Convert.ToInt32(nums[r]));
                                    triplet[0] = Convert.ToInt32(nums[i]);
                                    triplet[1] = Convert.ToInt32(nums[l]);
                                    triplet[2] = Convert.ToInt32(nums[r]);
                              }
                              l++;
                              r--;
                        } else if(Convert.ToInt32(nums[i]) + Convert.ToInt32(nums[l]) + Convert.ToInt32(nums[r]) < sum) {
                              l++;
                        } else { 
                              r--;
                        }
                  }
            }

	         Console.WriteLine(sum + " : " + "(" + triplet[0] + ", " + triplet[1] + ", " + triplet[2] +")");

     }
     
     // Finds the norm of 3 given numbers 
     public static double NormOf(double i, double j, double k) { 
      
	         double norm = Math.Sqrt(Convert.ToDouble((i*i) + (j*j) + (k*k)));
	         return norm; 
      
     }
} 
