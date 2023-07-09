use std::fs;

fn main() {

    let filename = String::from("/pub/pounds/CSC330/translations/KJV.txt");

    let contents = fs::read_to_string(filename)
        .expect("Something went wrong reading the file");

    let upper_case_bible = contents.to_uppercase();
    println!("The contents of the file:\n{}", upper_case_bible);

}
