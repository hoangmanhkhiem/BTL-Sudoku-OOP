#include "Board.h"

Board::Board()
{

    for (int i = 0; i < 81; i++)
    {
        this->gridPos[i] = i;
    }

    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::ranges::shuffle(this->gridPos, (this->gridPos) + 81, gen);


    for (int i = 0; i < 9; i++)
    {
        this->guessNum[i] = i + 1;
    }

    std::ranges::shuffle(this->guessNum, (this->guessNum) + 9, gen);


    for (int i = 0; i < 9; i++)
    {
        std::ranges::fill(std::begin(this->grid[i]), std::end(this->grid[i]), 0);
    }

    grid_status = true;
}

void Board::createSeed()
{
    this->solveGrid();

    for (int i = 0; i < 9; i++)
    {
        std::ranges::copy(std::begin(this->grid[i]), std::end(this->grid[i]), std::begin(this->solnGrid[i]));
    }
}

bool Board::solveGrid()
{
    int row, col;

    if (!solveFunc.FindUnassignedLocation(this->grid, row, col))
        return true;

    for (int num = 0; num < 9; num++)
    {
        if (solveFunc.isSafe(this->grid, row, col, this->guessNum[num]))
        {
            this->grid[row][col] = this->guessNum[num];

            if (solveGrid())
                return true;

            this->grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

void Board::countSoln(int& number)
{
    int row, col;

    if (!solveFunc.FindUnassignedLocation(this->grid, row, col))
    {
        number++;
        return;
    }


    for (int i = 0; i < 9 && number < 2; i++)
    {
        if (solveFunc.isSafe(this->grid, row, col, this->guessNum[i]))
        {
            this->grid[row][col] = this->guessNum[i];
            countSoln(number);
        }

        this->grid[row][col] = UNASSIGNED;
    }

}

void Board::genPuzzle()
{
    for (int i = 0; i < 81; i++)
    {
        int x = (this->gridPos[i]) / 9;
        int y = (this->gridPos[i]) % 9;
        int temp = this->grid[x][y];
        this->grid[x][y] = UNASSIGNED;

        int check = 0;
        countSoln(check);
        if (check != 1)
        {
            this->grid[x][y] = temp;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        std::ranges::copy(std::begin(this->grid[i]), std::end(this->grid[i]), std::begin(this->original_grid[i]));
    }
}

void Board::printGrid()
{
    std::cout << "   0  1  2  3  4  5  6  7  8" << std::endl;
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << "   -----------------------" << std::endl;
        }
        std::cout << i << " ";
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                std::cout << "| ";
            }
            if (grid[i][j] == 0)
                std::cout << ". ";
            else
                std::cout << grid[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " -----------------------" << std::endl;
    std::cout << std::endl;

}


void Board::printSolvedGrid()
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (solnGrid[i][j] == 0)
                std::cout << ".";
            else
                std::cout << solnGrid[i][j];
            std::cout << "|";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

}


std::string Board::getGrid()
{
    std::string s = "";
    for (int row_num = 0; row_num < 9; ++row_num)
    {
        for (int col_num = 0; col_num < 9; ++col_num)
        {
            s = s + std::to_string(grid[row_num][col_num]);
        }
    }
    return s;
}


void Board::editGrid(int row, int column, int entry)
{
    this->grid[row][column] = entry;

}

void Board::reloadGrid()
{

    for (int i = 0; i < 81; i++)
    {
        this->gridPos[i] = i;
    }

    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::ranges::shuffle(this->gridPos, (this->gridPos) + 81, gen);


    for (int i = 0; i < 9; i++)
    {
        this->guessNum[i] = i + 1;
    }

    std::ranges::shuffle(this->guessNum, (this->guessNum) + 9, gen);


    for (int i = 0; i < 9; i++)
    {
        std::ranges::fill(std::begin(this->grid[i]), std::end(this->grid[i]), 0);
    }

    grid_status = true;
}

int Board::getSolvedNumber(int row, int column)
{
    return solnGrid[row][column];
}

int Board::getOriginalNumber(int row, int column)
{
    return original_grid[row][column];
}

bool Board::checkComplete()
{
    bool decision = true;
    for (int i = 0; i < 9; i++)
    {
        if (!std::ranges::equal(grid[i], solnGrid[i]))
            decision = false;
    }
    return decision;
}