#include "phonebook.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {}


void PhoneBook::add(std::string name, std::string number, std::string nickname) {

    phonebook[number] = Information(name, number, nickname);
}

void PhoneBook::search() {

    int currentPage = 1;
    int totalPages = phonebook.size() / 10 + 1 ;
    std::string commandInput;

    while (1) {
        std::cout << "\n[Page " << currentPage << "]\n";
        int totalIndex = showPhonebookPage(currentPage);

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
                saveToBookmark(it);
                std::cout << "Bookmarked." << std::endl;
            }
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }
}

void PhoneBook::remove(){

    int currentPage = 1;
    int totalPages = phonebook.size() / 10 + 1 ;
    std::string commandInput;

    while (1) {
        std::cout << "\n[Page " << currentPage << "]\n";
        int totalIndex = showPhonebookPage(currentPage);

        std::cout << "If you want to enter a index to remove, enter 'idx'\n"
                     "If you want to enter a phone number to remove, enter 'num'\n"
                     "'n' : next page, 'p' : previous page, 'q' : quit"
                     "[Command] : ";
        std::cin >> commandInput;
        QString command = QString::fromStdString(commandInput).toLower();

        if (command == "n" && currentPage < totalPages) {
            ++currentPage;
        } else if (command == "p" && currentPage > 1) {
            --currentPage;
        } else if (command == "q") {
            break;
        } else if (command == "idx") {
            removeByIndex(currentPage, totalIndex);
        } else if (command == "num") {
            removeByNumber(currentPage, totalIndex);
        } else {
            std::cout << "Invalid command.\n";
        }


    }
}

void PhoneBook::bookmarkList(){

    int currentPage = 1;
    int totalPages = bookmarks.size() / 10 + 1 ;
    std::string commandInput;

    while (1) {
        std::cout << "\n[Page " << currentPage << "]\n";
        int totalIndex = showBookmarkPage(currentPage);

        std::cout << "[Command] 'n' : next page, 'p' : previous page, 'q' : quit bookmark, '0-9' : details\n";
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

            auto it = bookmarks.begin();
            std::advance(it, index);

            std::cout << "-------------------------------\n";
            std::cout << "Name : " << it->second.name << std::endl;
            std::cout << "Phone Number : " << it->first << std::endl;
            std::cout << "Nickname : " << it->second.nickname << std::endl;
            std::cout << "-------------------------------\n";
            std::cout << "'r' : delete bookmark , 'q' : quit\n";

            std::cin >> commandInput;
            command = QString::fromStdString(commandInput).toLower();
            if (command == "q")
                continue;
            else if (command == "r") {
                bookmarks.erase(it->first);
                std::cout << "Delete a number from a bookmark." << std::endl;
            }
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }

}

bool PhoneBook::isAllNumber(std::string command){
    if (std::all_of(command.begin(), command.end(), ::isdigit))
        return true;
    return false;
}

bool PhoneBook::isSingleValidNumber(std::string command, int totalIndex) {
    std::cout << "res: " << std::stoi(command) << ", " << totalIndex << std::endl;

    if (isAllNumber(command)
            && command.length() == 1
            && std::stoi(command) <= totalIndex )
        return true;
    else
        return false;
}


int PhoneBook::showPhonebookPage(int pageNum) {

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

int PhoneBook::showBookmarkPage(int pageNum) {

    int total;
    int indexPerPage = 10;
    int startIdx = (pageNum - 1) * indexPerPage;

    std::cout << "-------------------------------\n";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << " | ";
    std::cout << "Name" << std::endl;


    auto it = bookmarks.begin();
    std::advance(it, startIdx);

    for (int i = 0; i < indexPerPage && it != bookmarks.end(); ++i, ++it) {

        std::cout << std::setw(10) << std::right << i;
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << it->second.name << std::endl;

        total = i;
    }
    std::cout << "-------------------------------\n";

    return total;
}


void PhoneBook::saveToBookmark(std::map<std::string, Information>::iterator it){

    bookmarks[it->first] = it->second;
}

bool PhoneBook::removeTheNumber(std::string number) {

    bookmarks.erase(number);
    if (phonebook.erase(number)) {
        std::cout << "removed the number " << number << std::endl;
        return true;
    }

    std::cout << "The number does not exist.\n";
    return false;
}

void PhoneBook::removeByIndex(int currentPage, int totalIndex){

    std::string commandInput;

    std::cout << "Enter the index of the number you want to remove.\n"
                 "[index] : ";

    while (1) {

        std::cin >> commandInput;

        if (isSingleValidNumber(commandInput, totalIndex)) {

            int index = std::stoi(commandInput) + (currentPage - 1) * 10;

            std::cout << "index : " << index << std::endl;

            auto it = phonebook.begin();
            std::advance(it, index);
            std::string number = it->first;

            removeTheNumber(number);

            break;

        } else {
            std::cout << "** enter the right index **\n"
                         "[index] : ";
        }
    }
}


void PhoneBook::removeByNumber(int currentPage, int totalIndex){

    std::string commandInput;

    std::cout << "Enter the Phone Number you want to remove. (enter only number)\n"
                 "[Phone Number] : ";

    while (1) {

        std::cin >> commandInput;

        if (isAllNumber(commandInput) && removeTheNumber(commandInput)) {
            break;

        } else {
            std::cout << "** enter the right number **\n"
                         "[Phone Number] : ";
        }
    }
}
