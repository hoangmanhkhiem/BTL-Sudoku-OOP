#pragma once
#include "Interface.h"
#include "Display_frame.h"
#include <windows.h>
#include <string>
#include <thread> 
#include <iostream> 
#include <mutex> 
#include <chrono>

class Menu
{
protected:
	int option;
	Interface sudokuInterface;
	Display_frame display;
	BXH rank;
public:
	void runGame();
	void printMenu();
	void printBXH();
	void printHelp();
	void printExit();
	void display_Menu_login();
	void display_Menu_End_Game();
};

