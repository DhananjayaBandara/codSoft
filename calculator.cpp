#include <iostream> // Include the input/output stream library

using namespace std; // Use the standard namespace

int main() { // Start of the main function

    // Declare variables to store two numbers and the operation
    double num1, num2; // Variables to store the input numbers
    char operation; // Variable to store the operation (+, -, *, /)

    // Prompt the user to enter the first number
    cout << "Enter first number: ";
    cin >> num1; // Read the first number from the user

    // Prompt the user to enter the second number
    cout << "Enter second number: ";
    cin >> num2; // Read the second number from the user

    // Prompt the user to choose an operation (+, -, *, /)
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation; // Read the operation from the user

    // Perform the selected operation based on the input
    switch(operation) { // Start of the switch statement
        case '+': // Addition
            cout << "Result: " << num1 + num2 << endl; // Output the result of addition
            break; // Exit the switch statement
        case '-': // Subtraction
            cout << "Result: " << num1 - num2 << endl; // Output the result of subtraction
            break; // Exit the switch statement
        case '*': // Multiplication
            cout << "Result: " << num1 * num2 << endl; // Output the result of multiplication
            break; // Exit the switch statement
        case '/': // Division
            if (num2 != 0) { // Check if the second number is not zero
                cout << "Result: " << num1 / num2 << endl; // Output the result of division
            } else { // If the second number is zero
                cout << "Error: Division by zero!" << endl; // Output an error message
            }
            break; // Exit the switch statement
        default: // Invalid operation
            cout << "Error: Invalid operation!" << endl; // Output an error message
    } // End of the switch statement

    return 0; // Return 0 to indicate successful program execution
} // End of the main function
