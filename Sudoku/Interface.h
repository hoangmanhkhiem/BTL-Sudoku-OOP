#pragma once
#include "Gameplay.h"
#include "BXH.h"
#include "Display_frame.h"
class Interface
{
private:
	std::string entry_username;
	long int currentScore;
	long int highestScore;
	Gameplay game;
	BXH rank;
	Display_frame frame;
public:
	void login();
	void newSudoku();
	void addNumber();
	bool isComplete();
	void reloadSudoku();
	void endSudoku();
	void winSudoku();
	void cheat();
	void DisplayRank();
};

