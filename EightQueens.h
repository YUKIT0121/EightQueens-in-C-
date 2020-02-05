#ifndef _EIGHTQUEENS_H_
#define _EIGHTQUEENS_H_

#include <iostream>
using namespace std;

#define MAX_DIM 100

class EightQueens
{
private:
    char theBoard[MAX_DIM][MAX_DIM]; // the contents of the board
    int boardSize;                        // actual size of board

public:
    EightQueens(int bSize);

    //bool canPlace(int row, int col);
    bool canPlace(int row, int col);

    void printBoard();

    bool solveBoard(int fromCol);

    bool solveBoard();

    void initBoard(int boardSize);

};

#endif
