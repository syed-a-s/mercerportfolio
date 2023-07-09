use std:: env;

// Recursive method to find the factorial of a number

fn factorial_recursive (n: u64) -> u64 {
    match n {
        0 => 1,
        _ => n * factorial_recursive(n-1)
    }
}

fn main() {

      let args: Vec<_> = env::args().collect();
      let n = args[1].parse::<u64>().unwrap();
      println!("{}", factorial_recursive(n));
    
}
