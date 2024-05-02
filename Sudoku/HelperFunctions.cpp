#include "HelperFunctions.h"
bool HelperFunctions::FindUnassignedLocation(int grid[9][9], int& row, int& col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == UNASSIGNED)
            {
                return true;
            }

        }

    }

    return false;
}

bool HelperFunctions::UsedInRow(int grid[9][9], int row, int num)
{
    if (std::ranges::find(grid[row], num) != std::end(grid[row]))
        return true;
    return false;
}
bool HelperFunctions::UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool HelperFunctions::UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }

    return false;
}

bool HelperFunctions::isSafe(int grid[9][9], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num);
}
