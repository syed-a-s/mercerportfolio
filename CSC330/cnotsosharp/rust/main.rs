//////////////////////////////////////////////////////////////////////////////////
//
// Main function:
//
//////////////////////////////////////////////////////////////////////////////////

fn main() {

  let args: Vec<String> = env::args().collect();        // Collecting args from cmd-line.

  let mut num1:i32 = args[1].parse::<i32>().unwrap();   // Taking first two elements from args.
  let mut num2:i32 = args[2].parse::<i32>().unwrap();

  println!( "{}", num1 );                               // Printing integer range.
  println!( "{}", num2 );

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

fn roman( num : i32 ) {

  let mut i : i32 = 1;

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
