import java.util.*;
import java.io.*;

public class Personnel {  

      private static String choice = " ";
      private static int numEmployees = 1;
      
      public static void main(String[] args) { 
            
            Employee[] employees = new Employee[numEmployees];
            Scanner scan = new Scanner(System.in);
            
            while (choice != "literallyanything"){
                printMenu();
                choice = scan.nextLine();
                switch(choice){
                    case "n" : 
                    case "N" :
                        newEmployee(employees); choice = " "; employees = new Employee[numEmployees]; break;
                    case "c" :
                    case "C" :
                        System.out.println(numEmployees); computeChecks(employees); choice = " ";break;
                    case "r" :
                    case "R" :
                        raise(employees); choice = " "; break;
                    case "p" :
                    case "P" :
                        printRecords(employees); choice = " "; break;
                    case "d" :
                    case "D" :
                        download(employees); choice = " "; break;
                    case "u" :
                    case "U" :
                        upload(employees); choice = " "; break;
                    case "q" :
                    case "Q" :
                        System.out.println("Have a nice day :)"); return;
                    default : 
                        System.out.println("Command was not recognized;  please try again."); choice = " "; break;
                }
            }
            
      }
      
      public static void printMenu() { 
      
            System.out.println();
            System.out.println("----------------------------------------");
            System.out.println("|Commands: n - New Employee            |");
            System.out.println("|          c - Compute paychecks       |");
            System.out.println("|          r - Raise wages             |");
            System.out.println("|          p - Print Records           |");
            System.out.println("|          d - Download data           |");
            System.out.println("|          u - Upload data             |");
            System.out.println("|          q - Quit                    |");
            System.out.println("----------------------------------------");
            System.out.print("Enter Command:  ");
    
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
                for (int i = 1; i < employees.length; i++)
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
      
      public static void computeChecks(Employee[] employees) { 
      
            int hours = 0;
            Scanner scan = new Scanner(System.in);
            System.out.println(numEmployees);
            
            if (employees.length == 1 || employees == null) {
                System.out.println("You have no employees"); 
            } 
            else
                for (int i = 0; i < numEmployees; i ++) {
                    System.out.println("Enter number of hours worked by" + employees[i].getLastName() + ", " 
                    + employees[i].getFirstName() + ":  ");
                    hours = scan.nextInt();
                    System.out.println("Pay:  " + employees[i].computePay(hours));   
            }
      }
      
      public static void raise(Employee[] employees) {
      
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
      
      public static void printRecords(Employee[] employees) { 
      
            if (employees.length == 1) { 
                System.out.println("You have no employees");     
            }
            else { 
            for (int i = 0; i < numEmployees; i++)
                  System.out.println(employees[i].toString());
            }
      
      }
      
      public static void download(Employee[] employees) { 
      
            String fileName = "employee.dat";
            try { 
              FileOutputStream fileOut = 
                new FileOutputStream(fileName);
              ObjectOutputStream out = 
                new ObjectOutputStream(fileOut);
              out.writeObject(employees);
              out.close();
              }
              catch (IOException e) { 
                System.out.println(e.getMessage());
              }
                
      }
      
      public static void upload(Employee[] employees) { 
      
            String fileName = "employee.dat";
            try { 
              FileInputStream fileIn = 
                new FileInputStream(fileName);
              ObjectInputStream in = 
                new ObjectInputStream(fileIn);
              employees = (Employee[]) in.readObject();
              in.close();
              }
              catch (IOException e) { 
                System.out.println(e.getMessage());
              }
              catch (ClassNotFoundException e) {
                System.out.println(e.getMessage());
              }
              
      }
}