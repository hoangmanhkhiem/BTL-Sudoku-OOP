#pragma once
#include <ranges>
#include <thread> 
#include <iostream> 
#include <mutex> 
#include <atomic> 
#include <condition_variable> 
#include <vector>

#define UNASSIGNED 0

class HelperFunctions
{
public:
    bool FindUnassignedLocation(int grid[9][9], int& row, int& col);

    bool UsedInRow(int grid[9][9], int row, int num);

    bool UsedInCol(int grid[9][9], int col, int num);

    bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num);

    bool isSafe(int grid[9][9], int row, int col, int num);
};

