#include "phonebook.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {}


void PhoneBook::add(std::string name, std::string number, std::string nickname) {

    phonebook[number] = Information(name, number, nickname);
}

void PhoneBook::search(){
    // index도 보여줘야 한다. 인덱스와 이름만 보여주기
    // 10개씩만 보여주기
    // [command] n -> next, p -> Previous, number -> index
    // 유저가 북마크를 원한다면 북마크를 해야 한다.


    int currentPage = 1;
    int totalPages = phonebook.size() / 10 + 1 ;
    std::string commandInput;

    while (1) {
        std::cout << "\n[Page " << currentPage << "]\n";
        int totalIndex = showPage(currentPage);

        std::cout << "[Command] 'n' : next page, 'p' : previous page, 'q' : quit search, '0-9' : details\n";
        std::cin >> commandInput;
        QString command = QString::fromStdString(commandInput).toLower();

        if (command == "n" && currentPage < totalPages) {
            ++currentPage;
        } else if (command == "p" && currentPage > 1) {
            --currentPage;
        } else if (command == "q") {
            break;
        } else if (isSingleValidNumber(commandInput, totalIndex)) {

            int index = std::stoi(commandInput) + (currentPage - 1) * 10;

            std::cout << "index : " << index << std::endl;

            auto it = phonebook.begin();
            std::advance(it, index);

            std::cout << "-------------------------------\n";
            std::cout << "Name : " << it->second.name << std::endl;
            std::cout << "Phone Number : " << it->first << std::endl;
            std::cout << "Nickname : " << it->second.nickname << std::endl;
            std::cout << "-------------------------------\n";
            std::cout << "'b' : bookmark , 'q' : quit\n";

            std::cin >> commandInput;
            command = QString::fromStdString(commandInput).toLower();
            if (command == "q")
                continue;
            else if (command == "b") {
                // todo 북마크 구현

            }
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }
}

void PhoneBook::remove(){

}

void PhoneBook::bookmarkList(){

}


bool PhoneBook::isSingleValidNumber(std::string command, int totalIndex) {
    std::cout << "res: " << std::stoi(command) << ", " << totalIndex << std::endl;
    if (std::all_of(command.begin(), command.end(), ::isdigit)
        && command.length() == 1
        && std::stoi(command) <= totalIndex )
        return true;
    else
        return false;
}


int PhoneBook::showPage(int pageNum) {

    int total;
    int indexPerPage = 10;
    int startIdx = (pageNum - 1) * indexPerPage;

    std::cout << "-------------------------------\n";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << " | ";
    std::cout << "Name" << std::endl;


    auto it = phonebook.begin();
    std::advance(it, startIdx);

    for (int i = 0; i < indexPerPage && it != phonebook.end(); ++i, ++it) {

        std::cout << std::setw(10) << std::right << i;
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << it->second.name << std::endl;

        total = i;
    }
    std::cout << "-------------------------------\n";

    return total;
}
