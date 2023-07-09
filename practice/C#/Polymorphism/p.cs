using System;

namespace app { 

      class p {
      
            /////////////////////////////////////////////////////////
            
            public static void Main(string[] args) { 
            
                  Animal animal = new Animal("Black", "Tiger");
                  animal.say();
                  Console.WriteLine(animal.getColor());
                  Console.WriteLine(animal.getSpecies());
                  Console.WriteLine(animal.getAnimal());
                  
                  Animal monkey = new Monkey("Brown", "Mandrill");
                  monkey.say();
                  Console.WriteLine(monkey.getColor());
                  Console.WriteLine(monkey.getSpecies());
                  Console.WriteLine(monkey.getAnimal());
            
            }
            
            /////////////////////////////////////////////////////////

      } 

}