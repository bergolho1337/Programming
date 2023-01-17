use std::io;

fn main() {
    println!("Guess the number!");
    println!("Please input your guess: ");

    let mut guess = String::new();  // mutable variable

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line!");

    println!("you guessed: {}",guess);
}

/*
IMPORTANT:
Next, the line .read_line(&mut guess) calls the read_line method on the standard 
input handle to get input from the user. We’re also passing &mut guess as the 
argument to read_line to tell it what string to store the user input in. 
The full job of read_line is to take whatever the user types into standard input 
and append that into a string (without overwriting its contents), so we therefore 
pass that string as an argument. The string argument needs to be mutable so the 
method can change the string’s content.

The & indicates that this argument is a reference, which gives you a way to let 
multiple parts of your code access one piece of data without needing to copy that
data into memory multiple times. References are a complex feature, and one of 
Rust’s major advantages is how safe and easy it is to use references. 
You don’t need to know a lot of those details to finish this program. 
For now, all you need to know is that like variables, references are 
immutable by default. 
Hence, you need to write &mut guess rather than &guess to make it mutable. 
(Chapter 4 will explain references more thoroughly.)
*/