
public class SalariedEmployee extends Employee implements Serializable { 

      private double salary = 0.0;
      
      public SalariedEmployee(String lastName, String firstName, double salary) { 
            super(lastName, firstName, salary/(40 * 52));
            this.salary = salary;
      }
      public double getSalary() { 
            return salary;
      }
      public double computePay(double salary) { 
            return salary / 52;
      }
      public String toString() { 
            return getLastName() + ", " + getFirstName() + "\t\t" + "$" + getSalary() + "/year";
      }
      
}