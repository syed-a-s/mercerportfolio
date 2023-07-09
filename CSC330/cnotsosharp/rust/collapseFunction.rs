

//This is the Rust version of the collapse function for the CSC 330 Group Project

fn main() //This is the main function we will use to run the collapse function
{
  let mut number_string = String::new(); //Creates a string we will use to hold the user's input
  println!("Please enter the number you will be collapsing: "); //The terminal asks the user for the number they want collapsed
  std::io::stdin().read_line(&mut number_string); //This reads in the user's input and stores their number;
  let number:i32 = number_string.trim().parse().expect("Input not an integer"); //This integer will hold the number we are collapsing
  println!("{}", collapse(number).to_string()); //Finds and prints the collapsed version of the user given number
}

fn collapse(mut num:i32) -> i32 //This function takes in an integer and performs the collapse function on it before returning it
{
  if num < 10 //If the number we are checking is a single digit
  {
    return num; //Returns the number
  }
  else
  {
    let mut sum:i32 = 0; //Creates a mutable integer to hold the sum of all the single digits in a multidigit number
    while num > 9 //While the checked number has more than one digit
    {
      sum = sum + (num % 10); //Adds the last digit of num to the sum
      num = num / 10; //Cuts off the last digit of num for addition
    }
    sum = sum + num; //Adds num to the sum
    return collapse(sum); //Runs the collapse of and returns the collapse of the sum
  }
}