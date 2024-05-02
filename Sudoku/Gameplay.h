#pragma once
#include "Board.h"
#include "User.h"
#include <thread> 
#include <iostream> 
#include <mutex> 
#include <chrono>




class Gameplay
{
private:
	Board puzzle;
	User gameUser;

public:
	void newGame();
	bool addNumber(int entry_row, int entry_column, int entry_num);
	void reloadGame();
	bool userLogin(std::string entry_username);
	long int getHighestScore();
	long int getCurrentScore();
	bool isComplete();
	void printBoard();
	void saveScore();
	void loadThread();
	void cheat();
};

