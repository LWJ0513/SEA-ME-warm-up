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
        showPage(currentPage);

        std::cout << "[Command] 'n' : next page, 'p' : previous page, 'q' : quit search, '0-9' : details\n";
        std::cin >> commandInput;
        QString command = QString::fromStdString(commandInput).toLower();

        // todo 엔터 눌렀을 때?

        if (!command.compare("n") && currentPage < totalPages) {
            ++currentPage;
        } else if (!command.compare("p") && currentPage > 1) {
            --currentPage;
        } else if (!command.compare("q")) {
            break;
        } else if (isSingleValidNumber(commandInput)) {
            // when command is index 0~9
            // index를 선택해 세부 정보를 볼 수 있어야 한다.
            // 유저가 북마크를 원한다면 북마크를 해야 한다.

            int index = std::stoi(commandInput) + currentPage * 10;

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


bool PhoneBook::isSingleValidNumber(std::string command) {
    // todo 예외처리하세요 만약 마지막페이지라 숫자 3개만 있으면 0~2여야함.
    if (std::all_of(command.begin(), command.end(), ::isdigit) && command.length() == 1)
        return true;
    else
        return false;
}


void PhoneBook::showPage(int pageNum) {

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
    }
    std::cout << "-------------------------------\n";
}
