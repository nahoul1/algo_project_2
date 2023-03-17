/**************************************************************************
* Project 1 TEAM 2
* author: Ajinkya Joshi, Anthony Chamoun
* Date : March 15, 2023
* File name: SodukoBoard.cpp - Solve Sudoku Puzzles using recursive algorithms
* Purpose : Reads in a puzzle of more from a files and solves them
* Usage : g++ SudokuBoard.cpp -o output
****************************************************************************/

#include "SudokuBoard.h"
#include <fstream>

using namespace std;

/**************************************************************************
 * Constructor
****************************************************************************/

SudokuBoard::SudokuBoard(int N) : boardSize(N)
{
    // Resize conflict matricies
    sdkMatrix.resize(N, N);
	c_rows.resize(N, N);
	c_cols.resize(N, N);
	c_sqs.resize(N, N);
    clearBoard();

}


/**************************************************************************
 * Starter methods
****************************************************************************/

void SudokuBoard::clearBoard()
{
	// clears conflict matricies
	count = 0;
    for (int row = 0; row < boardSize; row++)
		for (int col = 0; col < boardSize; col++) {
			sdkMatrix[row][col] = Blank;
			c_rows[row][col] = Blank;
			c_cols[row][col] = Blank;
			c_sqs[row][col] = Blank;
		}
}


void SudokuBoard::initializeBoard(ifstream& fin)
{
    int digit;
    char ch; // holds each value read from file
    clearBoard(); // clear the board first
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            fin >> ch;
            // If the read char is not Blank
            if (ch != '.') {
                digit = ch - '0';// Convert char to int
                sdkMatrix[i][j] = digit;
            }
        }
    }
}


/**************************************************************************
 * Methods involved in the algorithm
****************************************************************************/

// Function checks if the place in the matrix is empty or not.
bool SudokuBoard::findEmpty(int &row, int &col)
{
    //blank indicates that the place in the matrix is empty.
    if (sdkMatrix[row][col] == Blank)
    {
        return true;
    }

        // if not then its the place in the matrix is not empty.
    else
    {
        return false;
    }
}

//checks if move is valid
bool SudokuBoard::checkConflicts(int &number, int &row, int &col)
{


    // checking for the row by iterating through each column in the row
    for(int colitr = 0; colitr < boardSize; colitr++)
    {
        if ((sdkMatrix[row][colitr] == number) && (colitr != col))
        {
            return false;
        }
    }


    // checking for the column by iterating through each row in the column
    for(int rowitr = 0; rowitr < boardSize; rowitr++)
    {
        if ((sdkMatrix[rowitr][col] == number) && (rowitr != row))
        {
            return false;
        }
    }

    // Checking each 3x3 square to find the box square integer division has been utilized.
    int box_y = row / 3; // y value is the row
    int box_x = col / 3; // x value is the col
    for(int colitr = (box_x*3); colitr < (box_x*3)+3; colitr++ )
        for(int rowitr = (box_y*3); rowitr < (box_y*3)+3; rowitr++ )
        {
            if ((sdkMatrix[rowitr][colitr] == number) && (colitr != col) && (rowitr != row))
            {
                return false;
            }
        }

    // if all for loops are satisfied - no conflict exists.
    return true;
}

// Two methods find the blackspace row and col
int SudokuBoard::emptyFinderrow()
{
    for(int row = 0; row < boardSize; row++)
        for(int col = 0; col < boardSize; col++)
        {
            if(findEmpty(row, col) == true)
            {
                return row;
            }
        }

    return 10;
}
int SudokuBoard::emptyFindercol()
{
    for(int row = 0; row < boardSize; row++)
        for(int col = 0; col < boardSize; col++)
        {
            if(findEmpty(row, col) == true)
            {
                return col;
            }
        }

    return 10;
}

// Solves the sudokuboard.
bool SudokuBoard::solveSudoku(int& recur, int& backtrack)
{

	recur += 1;
    if(emptyFindercol() == 10 || emptyFinderrow() == 10)
    {
        return true;
    }
    else
    {
        int row = emptyFinderrow();
        int col = emptyFindercol();

        for(int number = 1; number < boardSize + 1; number++)
        {

            if (checkConflicts(number,row,col))
            {
                sdkMatrix[row][col] = number;

                bool solution = solveSudoku(recur, backtrack);
                if (solution == false)
                {
                    backtrack++;
                }
                if (solution == true)
                {
                    return true;
                }

                sdkMatrix[row][col] = Blank;
            }
        }

        return false;
    }


}
/**************************************************************************/



void SudokuBoard::printSudoku(ofstream& out)
{
    for (int i = 1; i <= boardSize; i++)
    {
        if ((i - 1) % SquareSize == 0)
        {
            for (int j = 1; j <= boardSize + 1; j++)
                cout << "---";
            cout << endl;
        }
        for (int j = 1; j < boardSize + 1; j++)
        {
            if ((j - 1) % SquareSize == 0)
                cout << "|";
            if (sdkMatrix[i - 1][j - 1] != Blank)
                cout << " " << sdkMatrix[i - 1][j - 1] << " "; // prints out number
            else
                cout << " - ";  // prints blank indicating no number.
        }
        cout << "|";
        cout << endl;
    }
    cout << " -";
    for (int j = 1; j <= boardSize - 1; j++)
        cout << "---";
    cout << "-";
    cout << endl;

    // prints same thing to textfile
    for (int i = 1; i <= boardSize; i++)
    {
        if ((i - 1) % SquareSize == 0)
        {
            for (int j = 1; j <= boardSize + 1; j++)
                out << "---";
            out << endl;
        }
        for (int j = 1; j < boardSize + 1; j++)
        {
            if ((j - 1) % SquareSize == 0)
                out << "|";
            if (sdkMatrix[i - 1][j - 1] != Blank)
                out << " " << sdkMatrix[i - 1][j - 1] << " "; // prints out number
            else
                out << " - ";  // prints blank indicating no number.
        }
        out << "|";
        out << endl;
    }
    out << " -";
    for (int j = 1; j <= boardSize - 1; j++)
        out << "---";
    out << "-";
    out << endl;
}

void SudokuBoard::setConflict() {
	// does exactly that
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (sdkMatrix[i][j] != 0) {
				int k = sdkMatrix[i][j];
				int a = findLocation(j, i);
				c_rows[j][k - 1] = 1;
				c_cols[i][k - 1] = 1;
				c_sqs[a][k - 1] = 1;
			}
		}
	}
}

void SudokuBoard::printConflict(ofstream& out) {
	cout << "square conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_sqs[i][j];
		}
		cout << endl;
	}
	cout << "row conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_cols[i][j];
		}
		cout << endl;
	}
	cout << "col conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_rows[i][j];
		}
		cout << endl;
	}

	// prints same thing to textfile
	out << "square conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			out << c_sqs[i][j];
		}
		out << endl;
	}
	out << "col conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			out << c_cols[i][j];
		}
		out << endl;
	}
	out << "row conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			out << c_rows[i][j];
		}
		out << endl;
	}
}

// determines which square
int SudokuBoard::findLocation(int row, int col) {
	if (row + 1 <= boardSize / 3) {
		if (col + 1 <= boardSize / 3) {
			return 0;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 3;
		}
		else if (col + 1 <= boardSize) {
			return 6;
		}
	}
	if (row + 1 <= 2 * (boardSize / 3)) {
		if (col + 1 <= boardSize / 3) {
			return 1;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 4;
		}
		else if (col + 1 <= boardSize) {
			return 7;
		}
	}
	if (row + 1 <= boardSize) {
		if (col + 1 <= boardSize / 3) {
			return 2;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 5;
		}
		else if (col + 1 <= boardSize) {
			return 8;
		}
	}
}


