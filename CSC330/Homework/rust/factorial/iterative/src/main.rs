use std::env;

//Iterative Function to find the factorial of a number

fn factorial_iterative(n: u64) -> u64 {
      (1..=n).product()
}
 
fn main () {

      let args: Vec<_> = env::args().collect();
      let n = args[1].parse::<u64>().unwrap();
      println!("{}", factorial_iterative(n));
    
}
