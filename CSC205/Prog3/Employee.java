
public abstract class Employee implements Serializable { 

      private String lastName;
      private String firstName;
      private double hourlyWage;
      
      public Employee(String lastName, String firstName, double hourlyWage) { 
            this.lastName = lastName;
            this.firstName = firstName;
            this.hourlyWage = hourlyWage;
      }
      public String getLastName() { 
            return lastName;
      }
      public String getFirstName() { 
            return firstName;
      }
      public double getHourlyWage() {
            return hourlyWage;
      }
      public void raise(double percentChange) { 
            hourlyWage *= 1 + percentChange / 100;
      } 
      public abstract double computePay(double pay);
      
}