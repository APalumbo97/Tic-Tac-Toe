/**
 * @author: Anthony Palumbo
 * date: 12-23-2016
 * description: Board class for tic-tac-toe project
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>

const int X = 1;
const int O = 5;
const int SIZE = 3;

/**
 * Board class for tic-tac-toe project.
 */
class Board {
    private:
        int **grid;
    public:
        Board();
        ~Board();
        int checkWinner();
        int canPut(int r, int c);
        void makeMove(int r, int c, int val);
        std::string toString();
};

#endif
