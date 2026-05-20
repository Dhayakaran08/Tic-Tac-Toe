#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool checkWin() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void playerMove() {
    int choice;
    int row, col;

    cout << "Player " << currentPlayer << ", Enter Position (1-9): ";
    cin >> choice;

    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;

        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    } else {
        cout << "\nPosition Already Taken! Try Again.\n";
        playerMove();
    }
}

int main() {

    cout << "===== TIC TAC TOE GAME =====\n";

    while (true) {

        displayBoard();

        playerMove();

        if (currentPlayer == 'X') {

            if (checkWin()) {
                displayBoard();
                cout << "Player O Wins!\n";
                break;
            }

        } else {

            if (checkWin()) {
                displayBoard();
                cout << "Player X Wins!\n";
                break;
            }
        }

        if (checkDraw()) {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }
    }

    return 0;
}