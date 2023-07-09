using System;

namespace app { 

      public class Monkey : Animal {
      
            public Monkey() {}
      
            public Monkey(string color, string species) { 
                  base.color = color;
                  base.species = species;
            }
      
            public override void say() { 
                  Console.WriteLine("The " + base.getAnimal() + " screams");
            }
            
            /*
            
            Does not work with polymorphism because the monkey is still an animal object and can only call Animal methods
            ---- Is writing a virtual a method the only way to fix this? Or is there another workaround?
            
            public void jump() { 
                  Console.Write("The " + getColor() + " " + getSpecies() + " jumps");
                  
            */
      
      }

}