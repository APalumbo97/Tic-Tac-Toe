/**
 * @author: Anthony Palumbo
 * date: 12-23-2016
 * description: main source file for tic-tac-toe project
 */

#include <iostream>
#include "../include/Board.h"

using namespace std;

/**
 * Main function that is run.
 * @return: 0 on exit success
 */
int main() {
    Board b;
    int r, c;
    int moveCount = 0;

    cout << "* * * * * Welcome to the Tic-Tac-Toe game! * * * * *" << endl;
    cout << "Enter numbers 1, 2, or 3 when prompted for coordinates of your move." << endl;
    cout << b.toString() << endl;

    // Loops until there are no more possible moves.
    while(moveCount < 9) {
        // Prompts for coordinates to make a move.
        do {
            if(moveCount % 2 == 0) {
                cout << "Player X's turn, enter the row and column of your move.\nRow #:";
            }
            else {
                cout << "Player O's turn, enter the row and column of your move.\nRow #:";
            }
            cin >> r;
            cout << "Column #:";
            cin >> c;

            // Checks if the move is valid.
            if(b.canPut((r - 1), (c - 1)) != 1) {
                cout << "\nInvalid move, re-enter the desired coordinates.\n" << endl;
            }
        }while(b.canPut((r - 1), (c - 1)) != 1);
        
        // Makes the move.
        if(moveCount % 2 == 0) {
            b.makeMove((r - 1), (c - 1), X);
        }
        else {
            b.makeMove((r - 1), (c - 1), O);
        }

        cout << b.toString() << endl;

        // Checks if there is a winner and breaks the loop if there is.
        if(b.checkWinner() != 0)
            break;
        moveCount++;
    }

    // Prints the appropriate statement base on the winning status, if any.
    if(moveCount == 9) {
        cout << "\nGame over, stalemate." << endl;
    }
    else {
        if(b.checkWinner() == X) {
            cout << "\nPlayer X has won!!!" << endl;
        }
        else if(b.checkWinner() == O) {
            cout << "\nPlayer O has won!!!" << endl;
        }
    }

    return 0;
}
