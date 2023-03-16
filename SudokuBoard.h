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
using namespace std;

const int Blank = 0;
const int SquareSize = 3;

class SudokuBoard
{
private:
    int boardSize;              // Size of the sudoku board
    matrix<int> sdkMatrix;  // Sudoku matrix

public:
    SudokuBoard(int N = 9);     // Constructor
    void clearBoard();
    void initializeBoard(ifstream& fin);
    bool solveSudoku();
    void printSudoku();
    void findEmpty();
    void printConflict();
    void setConflict();
    int findLocation();
    void file();

};

#endif
