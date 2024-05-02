#include "Gameplay.h"

void Gameplay::cheat()
{
    puzzle.printSolvedGrid();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            puzzle.editGrid(i, j, puzzle.getSolvedNumber(i, j));
        }
    }
    puzzle.printGrid();
}

void Gameplay::newGame()
{
    puzzle.createSeed();
    puzzle.genPuzzle();
    puzzle.printGrid();
}

bool Gameplay::addNumber(int entry_row, int entry_column, int entry_num)
{
    if (puzzle.getSolvedNumber(entry_row, entry_column) == entry_num)
    {
        if (puzzle.getOriginalNumber(entry_row, entry_column) == entry_num)
        {
            puzzle.printGrid();
            return true;
        }
        else
        {
            puzzle.editGrid(entry_row, entry_column, entry_num);
            puzzle.printGrid();
            gameUser.incCurrent(100);
            return true;
        }
    }
    else
    {
        gameUser.incCurrent(-50);
        puzzle.printGrid();
        return false;
    }
}

void Gameplay::reloadGame()
{
    puzzle.reloadGrid();
    puzzle.createSeed();
    puzzle.genPuzzle();
    puzzle.printGrid();
}

bool Gameplay::userLogin(std::string entry_username)
{
    if (gameUser.setUsername(entry_username))
    {
        gameUser.openUserFile();
        return true;
    }
    else
        return false;
}

long int Gameplay::getHighestScore()
{
    return gameUser.getHighest();
}

long int Gameplay::getCurrentScore()
{
    return gameUser.getCurrent();
}

bool Gameplay::isComplete()
{
    return puzzle.checkComplete();
}

void Gameplay::printBoard()
{
    puzzle.printGrid();
}

void Gameplay::saveScore()
{
    std::ofstream ofs(gameUser.saveScore());
    ofs << puzzle.getGrid();
    ofs.close();
}

std::mutex mtx;
void threadFunc()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + std::chrono::seconds(3);
    mtx.lock();
    while (std::chrono::high_resolution_clock::now() < end)
    {
        std::cout << "\nLoading.. " << std::endl;
        system("cls");
        std::cout << "\nLoading... " << std::endl;
        system("cls");
        std::cout << "\nLoading.. " << std::endl;
        system("cls");
        std::cout << "\nLoading. " << std::endl;
        system("cls");
    }
    mtx.unlock();
}
void Gameplay::loadThread()
{
    std::thread t(threadFunc);
    t.join();
}