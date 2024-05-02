#include "User.h"

bool User::setUsername(std::string name_entry)
{
	const std::regex mail_Type("(\\w+)(\\.|_|-)?(\\w+)@(\\w+)(\\.(\\w+))+", std::regex_constants::icase);

	if (std::regex_match(name_entry, mail_Type) == 1)
	{
		username = name_entry;
		return true;
	}

	else
		return false;
}

bool User::openUserFile()
{
	if (std::filesystem::exists(path + username))
	{
		std::string max = "0";
		for (const std::filesystem::directory_entry& dir_entry : std::filesystem::recursive_directory_iterator{ path + username })
		{
			if (dir_entry.path().stem().string() > max)
				max = dir_entry.path().stem().string();
		}
		currentScore = 0;
		highestScore = stoi(max);
		return true;
	}
	else
	{
		currentScore = 0;
		highestScore = 0;
		return setNewUserFile();
	}

}

bool User::setNewUserFile()
{
	return std::filesystem::create_directories(path + username);
}

void User::incCurrent(int i)
{
	currentScore += i;
}

long int User::getHighest()
{
	return highestScore;
}

long int User::getCurrent()
{
	return currentScore;
}

std::string User::saveScore()
{
	std::ofstream{ path + username + "\\" + std::to_string(currentScore) + ".txt" };
	return (path + username + "\\" + std::to_string(currentScore) + ".txt");
}