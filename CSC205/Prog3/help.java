import java.util.*;
public class help { 

      private static int numEmployees = 1;
      
      public static void main(String[] args) { 
          
            Employee[] employees = new Employee[numEmployees];
            
            System.out.println(employees.length);
          
            newEmployee(employees);
            System.out.println(employees[1]);
         
  
      }
      
     public static void raise(Employee[] employees) {
      
            Scanner scan = new Scanner(System.in); 
            System.out.print("Enter Percentage increase:  ");
            double raise = scan.nextDouble();
            
            if (employees.length != 0) { 
                for(int i = 0; i < employees.length; i++)  
                    employees[i].raise(raise);
            } 
            else
                System.out.println("You have no employees");
      
      }
      
      public static void OTHERraise(Employee[] employees) {
      
            Scanner scan = new Scanner(System.in); 
            
            if (employees.length == 1) { 
                System.out.println("You have no employees");
            } 
            else {
                System.out.print("Enter Percentage increase:  ");
                double raise = scan.nextDouble();
                for(int i = 0; i < numEmployees; i++)  
                    employees[i].raise(raise);
            }
      }
      
      public static void computePay(Employee[] employees) {
      
            int hours = 0;
            Scanner scan = new Scanner(System.in); 
            
            for (int i = 0; i < employees.length; i++) {
                System.out.print("Enter number of hours worked by " + employees[i].getLastName() + ", " 
                + employees[i].getFirstName() + ":  ");
            hours = scan.nextInt();
            System.out.println("Pay:  " + employees[i].computePay(hours));
            }
      }
      
      public static void newEmployee(Employee[] employees) {
            
            Scanner scan = new Scanner(System.in);
            
            System.out.print("Enter the name of the new employee:  ");
            String name = scan.nextLine();
            String lastName = name.substring(0, name.indexOf(","));
            String firstName = name.substring(name.indexOf(",") + 1, name.length());
            
            System.out.print("Hourly (h) or Salaried (s):  ");
            String status = scan.nextLine();
             
            if (numEmployees == employees.length) { 
                Employee[] tempArray = new Employee[employees.length * 2];
                for (int i = 0; i < employees.length; i++)
                  tempArray[i] = employees[i];
                employees = tempArray;
            }         
            
            if (status.equalsIgnoreCase("h")) { 
                System.out.print("Enter hourly wage:  ");
                double wage = scan.nextDouble();
                employees[numEmployees] = new HourlyEmployee(lastName, firstName, wage);
            } else if (status.equalsIgnoreCase("s")) { 
                  System.out.print("Enter annual Salary:  ");
                  double salary = scan.nextDouble();
                  employees[numEmployees] = new SalariedEmployee(lastName, firstName, salary);
            } else { 
                  System.out.println("Input was not h or s; please try again.");    
            }
            numEmployees++;          
      
      } 
                  
}