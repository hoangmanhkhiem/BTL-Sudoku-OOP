#include "Menu.h"

void Menu::runGame()
{
    system("cls");
    sudokuInterface.login();
    sudokuInterface.newSudoku();
    while (option != 3)
    {
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            sudokuInterface.addNumber();
            if (sudokuInterface.isComplete())
            {
                sudokuInterface.winSudoku();
                std::cin >> option;
                if (option == 1)
                    sudokuInterface.reloadSudoku();
                else
                {
                    sudokuInterface.endSudoku();
                    option = 3;
                }
                display_Menu_End_Game();
            }
            break;
        }

        case 2:
        {
            sudokuInterface.reloadSudoku();
            break;
        }
        case 3:
        {
            sudokuInterface.endSudoku();
            display_Menu_End_Game();
            break;
        }
        case 1234567890:
            sudokuInterface.cheat();
            break;
        }
    }
}

void Menu::display_Menu_login()
{
    label:
    while(option != 4)
    {
        system("cls");
        display.printChaoMung();
        display.printMenu();
        int option = 0;
        std::cin >> option;
        switch(option)
        {
            case 1:
            {
                runGame();
                break;
            }
            case 2:
            {
                printBXH();
                std::cout << "Nhan phim bat ky de quay lai menu" << std::endl;
                std::cin.ignore();
                std::cin.get();
                if (std::cin.get())
                {
                    goto label;
                }
                break;
            }
            case 3:
            {
                printHelp();
                std::cout << "Nhan phim bat ky de quay lai menu" << std::endl;
                std::cin.ignore();
                std::cin.get();
                if (std::cin.get())
                {
                    goto label;
                }
                break;
            }
            case 4:
            {
                printExit();
                display.printChaoTamBiet();
                break;
            }
        }
    }

}

void Menu::printMenu()
{
    display.printMenu();
}

void Menu::printBXH()
{
    rank.Display_BXH();
}

void Menu::printHelp()
{
    display.printHelp();
}

void Menu::printExit()
{
    display.printChaoTamBiet();
}
void Menu::display_Menu_End_Game() {
    std::mutex mtx;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + std::chrono::seconds(3);
    mtx.lock();
    while (std::chrono::high_resolution_clock::now() < end)
    {
    }
    mtx.unlock();
    display_Menu_login();
}