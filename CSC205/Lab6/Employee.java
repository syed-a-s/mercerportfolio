
public class Employee extends Person
{
          private Date hireDate;
          private double salary;

          public Employee(String lastName, String firstName, Date birthDate, Date hireDate, double salary)
          {
                 super(lastName, firstName, birthDate);
                 this.hireDate = hireDate;
                 this.salary = salary;
          }
          
          public String toString()
          {
                 return "name = " + getLastName() + ", " + getFirstName() + "\nsalary = " + salary + "\nbirth = " + getBirthDate() + "\nhired = " + hireDate;
                 
          }

}