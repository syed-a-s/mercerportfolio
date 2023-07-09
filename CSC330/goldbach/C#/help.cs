using System;
using System.Collections;
using System.Collections.Generic;

public class help { 

      public static void Main() { 
      
            ArrayList l = new ArrayList();
            l.Add(1);
            l.Add(5);
            l.Add(41);
            int n = Convert.ToInt32(l[0]) + Convert.ToInt32(l[1]) + Convert.ToInt32(l[2]);
            Console.WriteLine(n);
      
      }

}