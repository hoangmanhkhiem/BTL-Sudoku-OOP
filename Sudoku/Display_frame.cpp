#include "Display_frame.h"

void Display_frame::printKhung(){
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

void Display_frame::printMenu(){
    printKhung();
    std::string menu[4] = {"1. New Game", "2. High Score", "3. Help", "4. Exit"};
    for(int i = 0; i < 4; i++){
        std::cout << "|" << std::setw(38) << menu[i] << "|\n";
    }
    printKhung();
}

void Display_frame::printLuaChon(){
    printKhung();
    std::string menu[3] = {"1. Them So", "2. New Game", "3. End Game"};
    for(int i = 0; i < 3; i++){
        std::cout << "|" << std::setw(38) << menu[i] << "|\n";
    }
    printKhung();
    std::cout << "Lua chon cua ban: ";
}

void Display_frame::printLuatChoi(){
    printKhung();
    std::cout << "|" << std::setw(38) << "Luat Choi" << "|\n";
    printKhung();
    std::string menu[3] = {"1. Nhap so tu 1-9",
     "2. Khong duoc trung so trong hang, cot, va o 3x3", 
     "3. Ket thuc khi hoan thanh"};
    for(int i = 0; i < 3; i++){
        std::cout << "|" << std::setw(38) << menu[i] << "|\n";
    }
    printKhung();
}

void Display_frame::printChucMung(){
    printKhung();
    std::cout << "|" << std::setw(38) << "Chuc Mung" << "|\n";
    printKhung();
}

void Display_frame::printChaoMung(){
    printKhung();
    std::cout << "|" << std::setw(38) << "Chao Mung" << "|\n";
    printKhung();
}

void Display_frame::printChaoTamBiet(){
    printKhung();
    std::cout << "|" << std::setw(38) << "Chao Tam Biet" << "|\n";
    printKhung();
}

void Display_frame::printHelp() {
    printKhung();
    std::cout << "|" << std::setw(38) << "Thanh Vien BTL OOP" << "|\n";
    printKhung();
    std::string menu[5] = {"1. Hoang Manh Khiem", 
    "2. Nguyen Quoc Khanh", "3. Le Xuan Anh", "4. Truong Quang Dong", "5. Nguyen Van Minh"};
    for(int i = 0; i < 5; i++){
        std::cout << "|" << std::setw(38) << menu[i] << "|\n";
    }
    printKhung();
}

void Display_frame::displayLogin() {
    printKhung();
    std::cout << "|" << std::setw(38) << "Nhap dia chi email de bat dau tro choi" << "|\n";
    printKhung();
    std::cout << "Email: ";
}


