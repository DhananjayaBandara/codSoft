#include <iostream>     // Include the input/output stream library
#include <vector>       // Include the vector container library
#include <string>       // Include the string library

using namespace std;    // Use the standard namespace

// Function prototypes
void initializeBoard(vector<vector<char>>& board);                          // Function to initialize the game board
void displayBoard(const vector<vector<char>>& board);                       // Function to display the game board
bool makeMove(vector<vector<char>>& board, char player, int row, int col);  // Function to make a move
bool checkWin(const vector<vector<char>>& board, char player);              // Function to check if a player has won
bool checkDraw(const vector<vector<char>>& board);                          // Function to check if the game is a draw
char switchPlayer(char currentPlayer);                                      // Function to switch players
bool playAgain();                                                           // Function to ask if the players want to play again

int main() {    // Start of the main function
    char currentPlayer = 'X';   // Variable to keep track of the current player
    bool gameFinished = false;  // Variable to indicate if the game has finished

    do { // Start of the do-while loop for the game

        // Create a 3x3 game board initialized with empty spaces
        vector<vector<char>> board(3, vector<char>(3, ' '));

        // Initialize the game board
        initializeBoard(board);

        // Display the initial game board
        displayBoard(board);

        while (!gameFinished) { // Start of the while loop for a single game round
            int row, col; // Variables to store the user's chosen row and column

            // Prompt the current player to enter their move
            cout << "Player " << currentPlayer << "'s turn.\n";

            // Get the user's input for the row
            cout << "Enter row (1-3): ";
            cin >> row;
            row--; // Adjust for zero-based indexing

            // Validate the user's input for the row
            if (row < 0 || row >= 3) {
                cout << "Invalid row! Please enter a number between 1 and 3.\n";
                continue; // Continue to the next iteration of the loop
            }

            // Get the user's input for the column
            cout << "Enter column (1-3): ";
            cin >> col;
            col--; // Adjust for zero-based indexing

            // Validate the user's input for the column
            if (col < 0 || col >= 3) {
                cout << "Invalid column! Please enter a number between 1 and 3.\n";
                continue; // Continue to the next iteration of the loop
            }

            // Check if the selected cell is already occupied
            if (board[row][col] != ' ') {
                cout << "Invalid move! That cell is already taken. Please try again.\n";
                continue; // Continue to the next iteration of the loop
            }

            // Make the move on the game board
            if (!makeMove(board, currentPlayer, row, col)) {
                cout << "Unexpected error! Please try again.\n";
                continue; // Continue to the next iteration of the loop
            }

            // Display the updated game board
            displayBoard(board);

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameFinished = true; // Set the gameFinished flag to true
            }
            // Check if the game is a draw
            else if (checkDraw(board)) {
                cout << "It's a draw!\n";
                gameFinished = true; // Set the gameFinished flag to true
            }
            else {
                // Switch to the next player's turn
                currentPlayer = switchPlayer(currentPlayer);
            }
        } // End of the while loop for a single game round

    } while (playAgain()); // End of the do-while loop for the game

    cout << "Thanks for playing!\n";

    return 0; // Return 0 to indicate successful program execution
} // End of the main function

// Function to initialize the game board with empty spaces
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3\n"; // Display column numbers
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " "; // Display row number
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " "; // Display cell contents
        }
        cout << endl; // Move to the next row
    }
}

// Function to make a move on the game board
bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    if (board[row][col] == ' ') { // Check if the selected cell is empty
        board[row][col] = player; // Place the player's symbol in the selected cell
        return true; // Return true to indicate a successful move
    }
    return false; // Return false to indicate an invalid move
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns for a winning combination
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }

    // Check diagonals for a winning combination
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check main diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check anti-diagonal

    return false; // Return false if no winning combination is found
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there is an empty cell, the game is not a draw
            }
        }
    }
    return true; // If all cells are filled, the game is a draw
}

// Function to switch players
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X'; // If the current player is 'X', switch to 'O', and vice versa
}

// Function to ask if the players want to play again
bool playAgain() {
    char choice; // Variable to store the user's choice
    cout << "Do you want to play again? (y/n): ";
    cin >> choice; // Get the user's choice
    return (choice == 'y' || choice == 'Y'); // Return true if the user chooses 'y', otherwise return false
}
