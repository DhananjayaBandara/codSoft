#include <iostream> // Include the input/output stream library
#include <cstdlib> // Include the standard library for functions such as rand
#include <ctime> // Include the time library to seed the random number generator

using namespace std; // Use the standard namespace

int main() { // Start of the main function

    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1; // Generates a random number between 1 and 100
    int guess; // Variable to store the user's guess
    int attempts = 0; // Variable to store the number of attempts

    // Output welcome message
    cout << "Welcome to the Guessing Game!\n";
    cout << "I have selected a number between 1 and 100. Can you guess what it is?\n";

    // Start of the do-while loop for the guessing game
    do {
        cout << "Enter your guess: "; // Prompt the user to enter their guess
        cin >> guess; // Read the user's guess from the input

        attempts++; // Increment the number of attempts

        // Check if the guess is too low
        if (guess < secretNumber) {
            cout << "Too low! Try again.\n"; // Output message indicating the guess is too low
        }
        // Check if the guess is too high
        else if (guess > secretNumber) {
            cout << "Too high! Try again.\n"; // Output message indicating the guess is too high
        }
        // If the guess is correct
        else {
            cout << "Congratulations! You've guessed the number " << secretNumber << " correctly!\n"; // Output message indicating the correct guess
            cout << "It took you " << attempts << " attempts.\n"; // Output the number of attempts taken
        }
    } while (guess != secretNumber); // Continue the loop until the guess matches the secret number

    return 0; // Return 0 to indicate successful program execution
} // End of the main function
