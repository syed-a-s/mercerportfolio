use std::env;  // Module for command-line argument.

//////////////////////////////////////////////////////////////////////////////////
//
// Main function:
//
//////////////////////////////////////////////////////////////////////////////////

fn main() {

  let args: Vec<String> = env::args().collect();        // Collecting args from cmd-line.

  let num1:i64 = args[1].parse::<i64>().unwrap();   // Taking first two elements from args.
  let num2:i64 = args[2].parse::<i64>().unwrap();
  let mut sum:i64 = 0; //Mutable integer value that will hold the sum of all the valid middle integers
  let mut count:i32 = 0; //Mutable integer to hold the count of how many numbers have exactly 2 unique middle factors that are prime
  let mut holder:i64; //This mutable integer will hold the result of the factor function for checking
  let collapsed_number:i64; //Creates a variable that will hold the number we are collapsing
  let mut counter:i64 = 0; // Variable for 
  
  counter = num1;
  while counter <= num2 //For the range of the beginning of our range to the end
  {
    if is_prime(counter) == false //If counter isn't prime
    {
      holder = factor(counter); //Stores the result of factor in holder
      if holder > 0 //If the prerequisities were met
      {
        sum = sum + holder; //Adds the result of factor to the sum
        count = count + 1; //Increments our count by one
      }
    }
    counter = counter + 1;
  }
  collapsed_number = collapse(sum); //Converts our sum to a collapsed number and stores it
  println!("Count: {}", count.to_string()); //Prints the count of composite numbers that match the requirements
  println!("Sum: {}", sum.to_string()); //Prints out the sum
  println!("Collapse: {}", collapsed_number.to_string()); //Prints out the collapsed version of the sum
  print!("Roman: "); //Prints out the formatting for the Roman numeral version of the collapsed number
  roman(collapsed_number); //Prints out the Roman numeral version of the collapsed number
  println!("  -- Hail Caesar!"); //Prints out "Hail Ceaser!" with two spaces at the beginning and two subsequent dashes
}

//////////////////////////////////////////////////////////////////////////////////
//
// Function:
//
// Pre: Takes an integer n, with 0 <= n < 10.
//
// Pos: Returns the representation of the digit in Roman numerals.
//
//////////////////////////////////////////////////////////////////////////////////

fn roman( num : i64 ) {

  let mut i : i64 = 1;  // Local index for the inner while loops in the function.

  if num == 0           // Case for num = 0.
  {
    print!("N");
  }

  else if num > 8       // Case for num greater than 8.
  {

    while i <= 10-num {
      print!("I");
      i = i + 1;
    }

    print!("X");

  }

  else if num > 5 {     // Case for num greater than 5 but less than 8.

    print!("V");

    while i <= num - 5 {
      print!("I");
      i = i + 1;
    }

  }

  else if num > 3 {     // Case for num = 3 or num = 4.

    if num == 4         
    {
      print!("I");
    }

    print!("V");
    
  }

  else {                // Case for num less than 3.
    
    while i <= num {
      print!("I");
      i = i + 1;
    }

  }

  println!("");         // Printing new line.

}

fn factor(num:i64) -> i64 //This function will take in an integer and return a vector full of its factors
{
  let mut num_hold:i64; //Holds onto the value of the input and allows modification of it
  let mut sum:i64 = 0; //Stores the sum
  let mut count:i32 = 0; //Stores the count of factors
  let mut unique_count:i32 = 0; //Used to verify there is no more than one of each number
  let mut num_check:i64; //Checks the number
  
  num_hold = num; 
  while num_hold % 2 == 0 //While the number is still even
  {
    num_hold = num_hold / 2;
    count = count + 1; //Keeps track of the number of factors
    sum = sum + 2; //Adds 2 to the sum of the middle factors
  }
  if count > 1 //If there are more than 2 middle factors
  {
    return 0; //Returns 0
  }
  
  num_hold = num;
  num_check = 3;
  
  while num_check * num_check <= num //This checks for what other numbers can divide the input number
  //Using the square of the variable 'i' allows for the run time to be signiciantly 
  //shorted as a number times itself denotes the middle of possible products
  {
    while num_hold % num_check == 0
    {
      num_hold = num_hold / num_check;
      count = count + 1; //Tracks the number of factors
      sum = sum + num_check; //Adds number to the sum factors
      unique_count = unique_count + 1; //Tracks if the number is unique
    }
    
    if count > 2 || unique_count > 1 //This returns 0 f there are more than 2 factors or if there are more than 1 of the factor
    {
      return 0;
    }
    
    unique_count = 0;
    num_check = num_check + 2;
  }
  //If we get this far, there has only been one factor. We add its complementary factor to the sum and return it
  sum = sum + (num / sum);
  return sum;

}

fn collapse(mut num:i64) -> i64 //This function takes in an integer and performs the collapse function on it before returning it
{
  if num < 10 //If the number we are checking is a single digit
  {
    return num; //Returns the number
  }
  else
  {
    let mut sum:i64 = 0; //Creates a mutable integer to hold the sum of all the single digits in a multidigit number
    while num > 0 //While the checked number is greater than 0
    {
      sum = sum + (num % 10); //Adds the last digit of num to the sum
      num = num / 10; //Cuts off the last digit of num for addition
    }
    sum = sum + (num / sum); //Adds num to the sum
    return collapse(sum); //Runs the collapse of and returns the collapse of the sum
  }
}

fn is_prime(checking:i64) -> bool //Function that takes in an integer and returns whether it is prime or not
{
  //let mut prime:bool = false; //Creates a variable that will hold the result of whether the number is prime or not
  let mut tracker:i64 = 3; //Creates a variable that will hold how many numbers completely divide into checking
  if checking % 2 == 0 && checking != 2
  {
    return false;
  }
  else
  {
    while tracker*tracker <= checking //Uses the square to reduce run time
    {
      if checking % tracker ==  0// If the number divides the input
      {
        return false;
      }
      tracker = tracker + 2;
    }
  }

  return true;

}
