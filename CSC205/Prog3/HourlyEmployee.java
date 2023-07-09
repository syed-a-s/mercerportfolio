
public class HourlyEmployee extends Employee implements Serializable { 
      
      public HourlyEmployee(String lastName, String firstName, double hourlyWage) { 
            super(lastName, firstName, hourlyWage);
      }
      public double computePay(double hoursWorked) { 
            if (hoursWorked <= 40)
                return getHourlyWage() * hoursWorked;
            else
                return getHourlyWage() * (hoursWorked * 1.5); 
      }
      public String toString() { 
            return getLastName() + ", " + getFirstName() + "\t\t" + "$" + getHourlyWage() + "/hour";
      }
      
}