#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <regex>
#include <filesystem>
#include "Users.h"
class User : public Users
{
private:
	std::string username;
	long int currentScore;
	long int highestScore;
public:
	bool setUsername(std::string name_entry);
	bool openUserFile();
	bool setNewUserFile();
	void incCurrent(int i);
	long int getHighest();
	long int getCurrent();
	std::string saveScore();
};

