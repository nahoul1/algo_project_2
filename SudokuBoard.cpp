/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date : March 15, 2023
* File name : SodukoBoard.cpp - Solve Sudoku Puzzles using
* : recursive algorithms
* Purpose : Reads in a puzzle of more from a files and solves them
* Usage : g++ SudokuBoard.cpp -o output
* : ./output (No Makefile required)
****************************************************************************/

#include "SudokuBoard.h"
#include <fstream>

using namespace std;

SudokuBoard::SudokuBoard(int N) : boardSize(N)
{
    // Resize conflict matricies
    sdkMatrix.resize(N, N);
    clearBoard();

}


void SudokuBoard::clearBoard()
{
    for (int row = 0; row < boardSize; row++)
        for (int col = 0; col < boardSize; col++)
            sdkMatrix[row][col] = Blank;
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

bool SudokuBoard::solveSudoku()
{

    return false;
}

void SudokuBoard::printSudoku()
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
                cout << " " << sdkMatrix[i - 1][j - 1] << " ";
            else
                cout << " - ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -";
    for (int j = 1; j <= boardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
}