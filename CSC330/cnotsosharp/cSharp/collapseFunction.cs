using System;

//This is the collapse function for the Group Project in CSC330
//This program will take in a number and perform the collapse of it and return the result

namespace collapseFunction
{
  public class collapseFunction //Indicates the beginning of our collapse function
  {
    public static void Main(String[] args) //Main runner of the class
    {
      Console.WriteLine("Please input the number that you would like to find the collapse of: "); //Asks the user for their input
      int number = int.Parse(Console.ReadLine()); //Takes the user's number and stores it to use
      Console.WriteLine("The total collapse of " + number + " is " + collapse(number)); //Finds the collapse of our function and prints it
    }
    
    public static int collapse(int checking) //This recursive function will take in an integer value and return the collapsed form of it
    {
      if(checking < 10) //If we have a single digit number being checked
      {
        return checking; //Returns our final result
      }
      else //If the number still has multiple digits
      {
        int sum = 0; //Creates a variable to hold the sum of all the single digits in our number
        while(checking > 9) //While checing is still multidigit
        {
          sum += checking % 10; //Adds the last digit of checking to the sum
          checking = checking / 10; //Cuts off the last digit of checking 
        }
        sum += checking; //Adds the final digit of the checking number to the sum variable
        return collapse(sum); //Recursively runs collapse with the new number to check 
      }
    }
  }
}
