#include <iostream>

#include "EightQueens.h"

using namespace std;



int main(void)
{
	int myBoardSize;
	cout << "Enter Board Size:";
	cin >> myBoardSize;

	EightQueens mySolver(myBoardSize);

	//mySolver.initBoard(myBoardSize);
	mySolver.printBoard();

	mySolver.solveBoard();

	cout << "THE SOLVED VERSION IS:" << endl;
	mySolver.printBoard();

	return 0;
}