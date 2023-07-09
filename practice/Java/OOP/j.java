public class j {

      public static void main(String[] args) { 
      
            Monkey m = new Monkey("Mandrill");
            m.say();
            System.out.println(m.monkeySpecies());
      
      }

}

class Monkey { 

      String species;

      public Monkey() {} 
      
      public Monkey(String species){
            this.species = species;
      }
      
      void say() { 
            System.out.println("monkey scream");
      }
      
      String monkeySpecies() { 
            if(species != null)
                  return species;
            else 
                  return "Species Unknown";
      }

}
