/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :March 15th, 2023
* File name       :main.cpp
* Purpose         :
 **************************************************************************/

#include <fstream>
#include <iostream>
#include "SudokuBoard.h"

using namespace std;

int main() {
    int recursiveCount; // # of recursive calls
    int backtracksCount; // # of backtracks involved for each board
    int boardCount = 0; // # of Boards from file solved
    int boardSize = 9;


    // Create SudokuBoard object
    SudokuBoard* sdk = new SudokuBoard(boardSize);
    // Open the data file and verify it opens successfully

    ifstream fin;
    fin.open("/Users/ajinkyajoshi/CLionProjects/algo_project_2/Sudoku3Puzzles.txt");
    if (!fin)
    {
        cerr << "Cannot open 'sudoku1.txt'" << endl;
        exit(1);
    }

    // Each iterations solves a NEW board from the input file
    while (fin && fin.peek() != 'Z') {
        recursiveCount = 0; // Reset # of recursive calls
        backtracksCount = 0; // Reset # of backtrack calls
        boardCount++; // New board to be solved
        // Initialize sudoku matrix

        sdk->initializeBoard(fin); // reads Sudoku from file
        // Print sudoku
        cout << "\n***** NEW SUDOKU PUZZLE... ******" << endl;

        sdk->printSudoku(); // print the board on the terminal
        // ******** Evaluate and print conflicts *****
        // If found, print out the resulting solution and final conflicts

        if (sdk->solveSudoku())
        {
            // Print on the terminal
            cout << "\nComplete Solution Found." << endl;
            cout << "\nCompleted board ..." << endl;
            sdk -> printSudoku();
            /* Print completed board
             * print the conflicts
             * print # of recursive calls
             * print # of backtrack calls
             * */
        }

        else {
            cout << "\nNo Solution Found...!" << endl;
            cout << "\nIncomplete board ..." << endl;
            /* Print incompleted board */
        }
    }

    cout << "Number of boards solved: " << boardCount << endl;
    // ****** Post processing **********
    // Determine the min, max, and average of the recursives calls and backtract
    // calls for the boards solved and print this information into the
    // file as well.
    cout << "\n***** Solver Terminating... ******" << endl;
    fin.close();
    delete sdk;
    return 0;
}