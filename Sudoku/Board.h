#pragma once
#include <iostream>
#include <string>
#include <random>
#include"HelperFunctions.h"

#define UNASSIGNED 0
class Board
{
private:
    int n = 10;
    int original_grid[9][9];
    int grid[9][9];
    int solnGrid[9][9];
    int guessNum[9];
    int gridPos[81];
    bool grid_status;
    HelperFunctions solveFunc;

public:
    Board();
    void createSeed();
    void printGrid();
    void printSolvedGrid();
    bool solveGrid();
    std::string getGrid();
    void countSoln(int& number);
    void genPuzzle();
    void editGrid(int row, int column, int entry);
    void reloadGrid();
    int getSolvedNumber(int row, int column);
    int getOriginalNumber(int row, int column);
    bool checkComplete();
};

