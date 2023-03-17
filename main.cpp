/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :March 15th, 2023
* File name       :main.cpp
* Purpose         :Solve sudoku boards
 **************************************************************************/

#include <fstream>
#include <iostream>
#include "SudokuBoard.h"
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main() {
    int recursiveCount; // # of recursive calls
    int backtracksCount; // # of backtracks involved for each board
    int boardCount = 0; // # of Boards from file
    int boardSize = 9;
    int solved = 0; // # of boards solved
    int nosolve = 0; // # of boards not solved

    vector<int> recur;
    vector<int> backtr;

    // Create SudokuBoard object
    SudokuBoard* sdk = new SudokuBoard(boardSize);
    // Open the data file and verify it opens successfully


    // opens sudoku input file
    ifstream fin;
    fin.open("Sudoku3Puzzles.txt");
    if (!fin)
    {
        cerr << "Cannot open 'sudoku1.txt'" << endl;
        exit(1);
    }
    
    // opens and creates output file
    ofstream out;
    out.open("Output.txt");
    if (!out) {
        cerr << "Cannot open file << endl";
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
        out << "\n***** NEW SUDOKU PUZZLE... ******" << endl;

        sdk->printSudoku(out); // print the board on the terminal
        // ******** Evaluate and print conflicts *****
        // If found, print out the resulting solution and final conflicts
        
        // finds and prints initial conflicts of the board
        sdk->setConflict();
        sdk->printConflict(out);


        if (sdk->solveSudoku(recursiveCount, backtracksCount))
        {
            // one more solved
            solved++;
            /* Print completed board
              * print the conflicts
              * print # of recursive calls
              * print # of backtrack calls
              * */
            cout << "\nComplete Solution Found." << endl;
            cout << "\nCompleted board ..." << endl;
            out << "\nComplete Solution Found." << endl;
            out << "\nCompleted board ..." << endl;
            sdk -> printSudoku(out);

            // adds recursive and backtracks to a vector 
            recur.push_back(recursiveCount);
            backtr.push_back(backtracksCount);

            cout << "Recursive calls: " << recursiveCount << endl;
            cout << "Backtracks: " << backtracksCount << endl;
            out << "Recursive calls: " << recursiveCount << endl;
            out << "Backtracks: " << backtracksCount << endl;
            /* Print completed board
             * print the conflicts
             * print # of recursive calls
             * print # of backtrack calls
             * */
        }

        else {
            // one more not solved
            nosolve++;
            /* Print incompleted board */
            cout << "\nNo Solution Found...!" << endl;
            cout << "\nIncomplete board ..." << endl;
            out << "\nNo Solution Found...!" << endl;
            out << "\nIncomplete board ..." << endl;
            
        }
    }
    
    // ****** Post processing info **********
    cout << "Number of boards solved: " << solved << endl;
    cout << "Number of Boards with no solution: " << nosolve <<endl;
    out << "Number of boards solved: " << solved << endl;
    out << "Number of Boards with no solution: " << nosolve << endl;
    
    // calculates and puts into text file recursive and backtrack info
    cout << "Minimum # of Recursive calls: " << *min_element(recur.begin(), recur.end()) << endl;
    cout << "Maximum # of Recursive calls: " << *max_element(recur.begin(), recur.end()) << endl;
    cout << "Average # of Recursive calls: " << accumulate(recur.begin(), recur.end(), 0.0) / recur.size() << endl;
    out << "Minimum # of Recursive calls: " << *min_element(recur.begin(), recur.end()) << endl;
    out << "Maximum # of Recursive calls: " << *max_element(recur.begin(), recur.end()) << endl;
    out << "Average # of Recursive calls: " << accumulate(recur.begin(), recur.end(), 0.0) / recur.size() << endl;

    cout << "Minimum # of BackTrack calls: " << *min_element(backtr.begin(), backtr.end()) << endl;
    cout << "Maximum # of BackTrack calls: " << *max_element(backtr.begin(), backtr.end()) << endl;
    cout << "Average # of BackTrack calls: " << accumulate(backtr.begin(), backtr.end(), 0.0) / backtr.size() << endl;
    out << "Minimum # of BackTrack calls: " << *min_element(backtr.begin(), backtr.end()) << endl;
    out << "Maximum # of BackTrack calls: " << *max_element(backtr.begin(), backtr.end()) << endl;
    out << "Average # of BackTrack calls: " << accumulate(backtr.begin(), backtr.end(), 0.0) / backtr.size() << endl;

    // over
    cout << "\n***** Solver Terminating... ******" << endl;
    out << "\n***** Solver Terminating... ******" << endl;

    // closes file, deletes object and ends program
    out.close();
    fin.close();
    delete sdk;
    return 0;
}