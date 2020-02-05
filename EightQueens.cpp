#include "EightQueens.h"

EightQueens::EightQueens(int bSize)
{
	initBoard(bSize);
}

bool
EightQueens::canPlace(int row, int col)
{
	// check the row ... is there another queen?
	for (int c = 0; c < col; c++)
	{
		if (theBoard[row][c] == 'Q')
			return false;
	}

	// if we get here, the row is "clean"

	// check diagonal to the up and left 
	int offset = 1;
	while (col - offset >= 0 && row - offset >= 0)
	{
		if (theBoard[row - offset][col - offset] == 'Q')
			return false;

		offset++;
	}

	// check diagonal down and left
	offset = 1;
	while (col - offset >= 0 && row + offset >= 0)
	{
		if (theBoard[row + offset][col - offset] == 'Q')
			return false;

		offset++;
	}

	// no offending queens found ... we can place here!
	return true;
}

void
EightQueens::printBoard()
{
	// +-+-+-+
	// | | | |
	// +-+-+-+
		// |Q| | |
	// +-+-+-+
		// | |Q| |	
	// +-+-+-+
	for (int row = 0; row < boardSize; row++)
	{
		// print out +-+-+.... pattern
		cout << "+";
		for (int col = 0; col < boardSize; col++)
			cout << "-+";
		cout << endl;

		// print out contents of row 
		cout << "|";
		for (int col = 0; col < boardSize; col++)
		{
			cout << theBoard[row][col] << '|';
		}
		cout << endl;
	}

	// print out last +-+-+.... pattern
	cout << "+";
	for (int col = 0; col < boardSize; col++)
		cout << "-+";
	cout << endl;
}

bool
EightQueens::solveBoard(int fromCol)
{
	// if we're off edge of board, it worked!
	if (fromCol >= boardSize)
		return true;

	// try each row of the current column, and see if it works?
	for (int row = 0; row < boardSize; row++)
	{
		// can we place a queen at row, col based on 
		// all queens already in previous columns? 
		if (canPlace(row, fromCol))
		{
			//place a queen at that row,col  position
			theBoard[row][fromCol] = 'Q';

			// solve the rest of the board 
			if (solveBoard(fromCol + 1))
				return true;

			// if we get here, solving with the current
			// position did not work 
			theBoard[row][fromCol] = ' ';
		}
	}

	// tried all rows in current column, and none worked ....
	return false;
}


bool
EightQueens::solveBoard()
{
	return solveBoard(0);
}

void
EightQueens::initBoard(int boardSize)
{

	for (int row = 0; row < boardSize; row++)
	{
		for (int col = 0; col < boardSize; col++)
		{
			theBoard[row][col] = ' ';
		}
	}

	this->boardSize = boardSize;
}
