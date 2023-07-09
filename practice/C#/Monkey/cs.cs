using System;

namespace App { 

      class Program {
      
            //////////////////////////////////////////////////////// 
      
            public static void Main(string[] args) {
            
                  Console.Write("How many monkeys? : ");
                  int numMonkeys = Convert.ToInt32(Console.ReadLine());
                  
                  Monkey[] Monkeys = new Monkey[numMonkeys];
                  
                  initMonkey(Monkeys, numMonkeys);
                  printMonkeys(Monkeys, numMonkeys);
                  
            }
            
            // Methods
            
            static void initMonkey(Monkey[] m, int n) {
            
                   for(int i = 0; i < n; i++) { 
                   
                         Console.Write("Species: ");
                         string species = Console.ReadLine();
                         
                         Console.Write("Color: ");
                         string color = Console.ReadLine();
                         
                         m[i] = new Monkey();
                         m[i].setSpecies(species);
                         m[i].setColor(color);
                         
                   }
            
            }
            
            static void printMonkeys(Monkey[] m, int n) { 
            
                    Console.WriteLine();
                    
                    for(int i = 0; i < n; i++) { 
                    
                          Console.Write("Monkey " + (i + 1) + " : ");
                          Console.WriteLine(m[i].getColor() + " " + m[i].getSpecies());
                          
                    }
                    
                    Console.WriteLine();
                    
            }
            
            ////////////////////////////////////////////////////////
            
      }     
      
}