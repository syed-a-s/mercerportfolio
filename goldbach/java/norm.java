import java.io.*;
import java.util.*;
import java.lang.Math;

public class norm { 

	public static void main(String[] args) { 
	
		ArrayList<Integer> nums = new ArrayList<Integer>();
		nums.add(5);
		nums.add(12);
		nums.add(2);
		nums.add(6);
		nums.add(8);
		nums.add(7);
		
		int sum = 19;	
		double norm = 100000000;
		for(int i = 0; i < nums.size(); i++) { 
			for(int j = 0; j < nums.size(); j++) { 
				for(int k = 0; k < nums.size(); k++) { 
					
					if(nums.get(i) + nums.get(j) + nums.get(k) == sum) { 
						if((Math.sqrt(Math.pow(i, 2) + Math.pow(j, 2) + Math.pow(k, 2) ) < norm))
							norm = Math.sqrt(Math.pow(i, 2) + Math.pow(j, 2) + Math.pow(k,2));
					}

				}
			}
		}
		
		System.out.println(norm);
	} 

}
