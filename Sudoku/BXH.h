#pragma once
#include<filesystem>
#include<fstream>
#include<algorithm>
#include<vector>
#include"User.h"
class BXH
{
protected:
	std::string path = "C:\\Users\\khiem\\source\\repos\\Sudoku\\Data\\";
	std::vector<std::pair<std::string, int>> list_rankling;
public:
	void exce_BXH();
	void Display_BXH();
	void sort_BXH();
};

