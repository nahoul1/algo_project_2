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
    int boardSize, count = 0;              // Size of the sudoku board
    matrix<int> sdkMatrix;  // Sudoku matrix
    matrix<bool> c_rows;    // conflict matricies
    matrix<bool> c_cols;
    matrix<bool> c_sqs;
public:
    SudokuBoard(int N = 9);     // Constructor
    void clearBoard();
    void initializeBoard(ifstream& fin);
    bool solveSudoku();
    void printSudoku();
    void findEmpty(int& row, int& col);
    void printConflict();
    void setConflict();
    int findLocation(int row, int col);
    void file(const string& filename);

};

#endif
