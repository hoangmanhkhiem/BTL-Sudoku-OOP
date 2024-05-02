#include "Users.h"

bool Users::openUserFile(std::string username)
{
	if (std::filesystem::exists(path + username))
	{
		return true;
	}
	else
	{
		return setNewUserFile(username);
	}

}

bool Users::setNewUserFile(std::string username)
{
	return std::filesystem::create_directories(path + username);
}

std::string Users::saveScore(std::string username)
{
	std::ofstream{ path + username + "\\" + "file.txt" };
	return (path + username + "\\" + "file.txt");
}