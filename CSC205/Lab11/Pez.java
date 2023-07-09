
public class Pez { 

      public static void main(String[] args) { 
      
          Stack stack1 = new Stack();
          addPez(stack1);
          System.out.println(stack1.top());
      
      }
      
      public static void addPez(Stack s) {
      
            s.push("yellow");
            s.push("red");
            s.push("green");
            s.push("green");
            s.push("yellow");
            s.push("yellow");
            s.push("red");
            s.push("green");
            
      }
 
}  
class PezDo extends Stack { 

      public void removeGreen(Stack stack) { 
      
            Stack temp = stack
      
            while (temp != ) { 
                  if (temp.peep() == "green") {
                        temp.pop();
                  }
                  else {
                        if (temp.peep() == null)  
                              break;
                        else
                              removeGreen(temp.pop());
                  }
            }
      
      }
}
