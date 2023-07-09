
import java.util.*;

public class TestEmployee
{
      public static void main(String[] args)
      {
  		      Date birthDate = new Date();
		        Date hireDate = new Date(2002, 2, 5);
            Employee emp1 = new Employee("Brown", "Morris", birthDate, hireDate, 40000);
            
            System.out.println(emp1.toString());
      } 
      
}