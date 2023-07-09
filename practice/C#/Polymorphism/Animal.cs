using System;

namespace app { 

      public class Animal { 
      
            protected string species; 
            protected string color;
            
            public Animal() {}
            
            public Animal(string color, string species) { 
                  this.color = color;
                  this.species = species;
            }
            
            public virtual void say() {   
                  Console.WriteLine("The animal makes a noise");
            }
            
            public void setSpecies(string species) { 
                  this.species = species;
            }
            
            public void setColor(string color) { 
                  this.color = color;
            }
            
            public string getSpecies() { 
                  return species;
            }
            
            public string getColor() { 
                  return color;
            }
            
            public string getAnimal() { 
                  return color + " " + species;
            }
      
      }

}