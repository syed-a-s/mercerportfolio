using System;

namespace App { 

      public class Monkey { 
      
            public string species;
            public string color;
            
            public Monkey() {}
            
            public Monkey(string species, string color) { 
            
                  this.species = species;
                  this.color = color;
            
            }
            
            public void say() { 
                  Console.WriteLine("monkey scream");
            }
            
            public string getSpecies() { 
                  return species;
            }
            
            public string getColor() { 
                  return color;
            }
            
            
            public void setSpecies(string species) { 
                  this.species = species;
            }
            
            public void setColor(string color) { 
                  this.color = color;
            }
      
      }

}