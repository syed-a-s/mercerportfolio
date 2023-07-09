use std::fs;

fn main() {
    let mut tokens:i32 = 0;
    let mut my_string:String = String::new();
    let max_length = 40;
    let mut start:usize = 0;
    let mut word_length:usize = 0;

    let filename = String::from("/pub/pounds/CSC330/translations/KJV.txt");

    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    let uppercase_bible = contents.to_uppercase();

    let my_vec: Vec<char> = uppercase_bible.chars().collect();
    for index in 0..my_vec.len() {
        if  my_vec[index] != ' '  {
            word_length=word_length+1;
        }
        else {
            if (my_string.len() + word_length ) < max_length {
                for i in start..(start+word_length+1) {
                    let letter = my_vec[i].to_string();
                    my_string.push_str(&letter);
                }
                println!( "{}", my_string);
                start=index+1;
                word_length=0;
            }
            tokens=tokens+1;
        }
    }
    println!("There were {} tokens read.", tokens);
}
