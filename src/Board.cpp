/**
 * @author: Anthony Palumbo
 * date: 12-23-2016
 * description: source file for Board class
 */

#include "../include/Board.h"
#include <string>

using namespace std;

/**
 * Constructor for a Board object.
 */
Board::Board() {
    grid = new int*[SIZE];

    // Creates all the 1D arrays to make the 2D array.
    for(int ctr = 0; ctr < SIZE; ctr++) {
        grid[ctr] = new int[SIZE];
        for(int i = 0; i < SIZE; i++) {
            grid[ctr][i] = 0;
        }
    }
}

/**
 * Destructor for a Board object.
 */
Board::~Board() {
    for(int ctr = 0; ctr < SIZE; ctr++) {
        delete[] grid[ctr];
    }
    delete[] grid;
}

/**
 * Checks if there is a winner for the current game.
 * @return: 0 if no winner, X if X player wins or O if O player wins
 */
int Board::checkWinner() {
    int sum;

    // Checks all the rows for a winner.
    for(int i = 0; i < SIZE; i++) {
        sum = 0;
        for(int ctr = 0; ctr < SIZE; ctr++) {
            sum += grid[i][ctr];
        }
        if(sum == 3) {
            return X;
        }
        else if(sum == 15) {
            return O;
        }
    }

    // Checks all the columns for a winner.
    for(int a = 0; a < SIZE; a++) {
        sum = 0;
        for(int b = 0; b < SIZE; b++) {
            sum += grid[b][a];
        }
        if(sum == 3) {
            return X;
        }
        else if(sum == 15) {
            return O;
        }
    }

    // Checks the top-left to bottom-right diagonal for a winner.
    sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += grid[i][i];
    }
    if(sum == 3) {
        return X;
    }
    else if(sum == 15) {
        return O;
    }

    // Checks the top-right to bottom-left diagonal for a winner.
    sum = grid[0][2] + grid[1][1] + grid[2][0];
    if(sum == 3) {
        return X;
    }
    else if(sum == 15) {
        return O;
    }

    // Returns zero because after checking all the possibilities, a winner has not been found.
    return 0;
}

/**
 * Determines if there is an open spot on the board at the given coordinates.
 * @param r: the row to be checked
 * @param c: the column to be checked
 * @return: 1 if there is an open spot, 0 if not
 */
int Board::canPut(int r, int c) {
    if(grid[r][c] == 0)
        return 1;
    return 0;
}

/**
 * Simulates making a move for a player.
 * @param r: the row to set the value
 * @param c: the column to set the value
 * @param val: the value to be set at the given coordinates
 */
void Board::makeMove(int r, int c, int val) {
    grid[r][c] = val;
}

/**
 * Creates a representation of the board as a string.
 * @return: string of the board
 */
string Board::toString() {
    char a, b, c;
    string output = "Board:\n";

    // Loops through every line for the 2D array.
    for(int ctr = 0; ctr < SIZE; ctr++) {

        // Loops through every value of the 1D array being checked.
        for(int i = 0; i < SIZE; i++) {
            output += ' ';
            if(grid[ctr][i] == X) {
                output += 'X';
            }
            else if(grid[ctr][i] == O) {
                output += 'O';
            }
            else {
                output += ' ';
            }
            if(i != (SIZE - 1)) {
                output.append(" |");
            }   
            else {
                output += '\n';
            }
        }

        // Pads each line with a line of '-' characters.
        if(ctr != (SIZE - 1)) {
            for(int i = 0; i < (SIZE * 4) - 1; i++) {
                output += '-';
            }
            output += '\n';
        }
    }
    return output;
}
