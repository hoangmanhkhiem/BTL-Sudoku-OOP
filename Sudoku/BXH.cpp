#include "BXH.h"

void printKhung(){
	for(int i = 0; i < 40; i++){
		if(i == 0 || i == 39){
			std::cout << "+";
		}
		else{
			std::cout << "-";
		}
	}
	std::cout << std::endl;
}

void BXH::exce_BXH() {
	for (const std::filesystem::directory_entry& dir_entry : std::filesystem::recursive_directory_iterator{ path })
	{
		if(dir_entry.path().extension() == ".txt"){
			continue;
		}
		else{
			std::string name = dir_entry.path().filename().string();
			int score = 0;
			std::string name_user = name.substr(name.find_last_of("\\") + 1);
			User user;
			user.setUsername(name_user);
			user.openUserFile();
			score = user.getHighest();
			list_rankling.push_back(std::make_pair(name_user, score));
		}	
	}
}
void BXH::Display_BXH(){
	exce_BXH();
	sort_BXH();
	std::cout << "+----------------------+-----------------+\n";
	std::cout << "|       Username       |      Score      |\n";
	std::cout << "+----------------------+-----------------+\n";
	for (const auto& i : list_rankling) {
		std::cout << "|" << std::setw(22) << i.first << "|" << std::setw(17) << i.second << "|\n";
	}
	std::cout << "+----------------------+-----------------+\n";
}

void BXH::sort_BXH() {
	std::sort(list_rankling.begin(), list_rankling.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
	});
}