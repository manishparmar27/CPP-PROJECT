#include <iostream>
using namespace std;

// Global 3x3 board
char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

// Function to make a move
void makeMove(char mark) {
    int choice;
    cout << "Player " << mark << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
    } else {
        cout << "Invalid move! Try again.\n";
        makeMove(mark);
    }
}

// Function to check if a player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to check for draw
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Main game function
int main() {
    char currentPlayer = 'X';
    cout << "=== Welcome to Tic Tac Toe ===\n";

    while (true) {
        displayBoard();
        makeMove(currentPlayer);

        if (checkWin()) {
            displayBoard();
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "🤝 It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}