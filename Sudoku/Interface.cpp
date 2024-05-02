#include "Interface.h"
void Interface::login()
{
	system("cls");
	frame.printChaoMung();
	frame.displayLogin();
	std::cin >> entry_username;
	while (!game.userLogin(entry_username))
	{
		std::cout << "Dinh dang email sai vui long nhap lai:\n";
		std::cout << "Email: ";
		std::cin >> entry_username;
	}
	system("cls");
}

void Interface::newSudoku()
{
	game.loadThread();
	frame.printKhung();
	std::cout << "|Nguoi dung: " << std::setw(38-12) << entry_username << "|\n";
	std::cout << "|Ket Qua: " << std::setw(38-9) << game.getCurrentScore() << "|\n";
	std::cout << "|Highest Score: " << std::setw(38-15) << game.getHighestScore() << "|\n";
	frame.printKhung();
	game.newGame();
	frame.printLuaChon();
}

void Interface::addNumber()
{
	int entry, column, row = 10;
	std::cout << "Row: ";
	std::cin >> row;
	while ((8 < row) or (0 > row))
	{
		std::cout << "NHAP SO TU PHAM VI 0-8 ";
		std::cin >> row;
	}

	std::cout << "Column: ";
	std::cin >> column;
	while ((8 < column) or (0 > column))
	{
		std::cout << "NHAP SO TU PHAM VI 0-8:";
		std::cin >> column;
	}

	std::cout << "Number: ";
	std::cin >> entry;
	while ((9 < entry) or (1 > entry))
	{
		std::cout << "NHAP SO TU PHAM VI 1-9:";
		std::cin >> entry;
	}
	system("cls");

	frame.printKhung();
	std::cout << "|Nguoi dung: " << std::setw(38-12) << entry_username << "|\n";
	std::cout << "|Ket Qua: " << std::setw(38-9) << currentScore << "|\n";
	std::cout << "|Highest Score: " << std::setw(38-15) << highestScore << "|\n";
	frame.printKhung();
	if (!game.addNumber(row, column, entry))
		std::cout << "So khong hop le nen chua duoc nhap\n\n";
	frame.printLuaChon();
}

bool Interface::isComplete()
{
	return game.isComplete();
}

void Interface::reloadSudoku()
{
	system("cls");
	game.loadThread();
	frame.printLuaChon();
	game.reloadGame();
	frame.printLuaChon();
}

void Interface::endSudoku()
{
	game.saveScore();
	std::cout << "Da Luu " << entry_username << std::endl;
}

void Interface::winSudoku()
{
	system("cls");
	frame.printKhung();
	std::cout << "|Nguoi dung: " << std::setw(38-12) << entry_username << "|\n";
	std::cout << "|Ket Qua: " << std::setw(38-9) << currentScore << "|\n";
	std::cout << "|Highest Score: " << std::setw(38-15) << highestScore << "|\n";
	frame.printKhung();
	game.printBoard();
	game.saveScore();
	frame.printChucMung();
	std::cout << "1 -  Tro choi moi, 3 - Ket Thuc" << std::endl;
}

void Interface::cheat()
{
	system("cls");
	frame.printKhung();
	std::cout << "|Nguoi dung: " << std::setw(38-12) << entry_username << "|\n";
	std::cout << "|Ket Qua: " << std::setw(38-9) << currentScore << "|\n";
	std::cout << "|Highest Score: " << std::setw(38-15) << highestScore << "|\n";
	frame.printKhung();	
	game.cheat();
	frame.printLuaChon();
}

void Interface::DisplayRank()
{
	system("cls");
	std::cout << "Ranking\n";
	rank.Display_BXH();
}