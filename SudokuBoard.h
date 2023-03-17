/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :March 15th, 2023
* File name       :LockBox.cpp
* Purpose         :SudokuBoard.h
 **************************************************************************/

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H
#include <iostream>
#include <vector>
#include <fstream>
#include "d_matrix-1.h"

using namespace std;

const int Blank = 0;
const int SquareSize = 3;

class SudokuBoard
{

private:
    int boardSize, count = 0; // Size of the sudoku board
    matrix<int> sdkMatrix; // Sudoku matrix
    matrix<bool> c_rows; // conflict matrices for rows
    matrix<bool> c_cols; // conflict matrices for columns
    matrix<bool> c_sqs; // conflict matrices for squares


public:

    /**
    * Constructor for SudokuBoard class.
    * @param N The size of the board. Default value is 9.
    */
    SudokuBoard(int N = 9);

    /**
    * Clears the Sudoku board.
    */
    void clearBoard();

    /**
    * Initializes the Sudoku board from a file.
    * @param fin The input file stream to read from.
    */
    void initializeBoard(ifstream& fin);

    /**
    * Solves the Sudoku board.
    * @param recur The number of recursive calls made during the solving process.
    * @param backtrack The number of times the solver backtracked during the solving process.
    * @return True if the board is solvable, false otherwise.
    */
    bool solveSudoku(int &recur, int &backtrack);

    /**
    * Prints the Sudoku board to an output file.
    * @param out The output file stream to write to.
    */
    void printSudoku(ofstream& out);

    /**
    * Finds an empty cell on the Sudoku board.
    * @param row The row of the empty cell.
    * @param col The column of the empty cell.
    * @return True if an empty cell is found, false otherwise.
    */
    bool findEmpty(int &row, int &col);

    /**
    * Checks for conflicts with a number in a given cell.
    * @param number The number to check conflicts with.
    * @param row The row of the cell.
    * @param col The column of the cell.
    * @return True if there are no conflicts, false otherwise.
    */
    bool checkConflicts(int &number, int &row, int &col);

    /**
    * Finds the row of the first empty cell.
    * @return The row of the first empty cell.
    */
    int emptyFinderrow();

    /**
    * Finds the column of the first empty cell.
    * @return The column of the first empty cell.
    */
    int emptyFindercol();

    /**
    * Prints the conflict matrices to an output file.
    * @param out The output file stream to write to.
    */
    void printConflict(ofstream& out);

    /**
    * Sets the conflict matrices for rows, columns, and squares.
    */
    void setConflict();

    /**
    * Finds the index of a given cell in the Sudoku matrix.
    * @param row The row of the cell.
    * @param col The column of the cell.
    * @return The index of the cell in the Sudoku matrix.
    */
    int findLocation(int row, int col);
};

#endif
