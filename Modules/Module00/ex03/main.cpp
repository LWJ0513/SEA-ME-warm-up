#include <iostream>
#include <QString>
#include <map>
#include "phonebook.h"
#include <algorithm>
#include <string>

/*
You have to make a Phonebook application. Follow the details:
User can use these commands
- ADD
    Add new contact in phonebook
    Require contents
        Name
        Phone number(unique)
        Nickname
- SEARCH
    List up the contacts with index
        User choose index display details of the contact.
        If user want can bookmark the contact
- REMOVE
    Remove a contact with an index or a phone number.
- BOOKMARK
    List up the bookmarked contact
- EXIT
    Shut down the program
 */


void getAndAddInformation(PhoneBook *phonebook) {
    // name, number (unique), nickname을 저장한다.
    std::string number;
    std::string name;
    std::string nickname;

    while (1) {

        // get number
        std::cout << "\n** enter only numbers **\n"
                     "** If you enter a number that already exists, the information will be modified. **\n"
                     "phone number : ";
        std::cin >> number;

        // check for numbers only
        if (std::all_of(number.begin(), number.end(), ::isdigit))
            break;
    }

    // get name
    std::cout << "** enter the name **\nname : ";
    std::cin >> name;

    // get nickname
    std::cout << "** enter the nickname **\nnickname : ";
    std::cin >> nickname;


    phonebook->add(name, number, nickname);

    std::cout << "The contact has been added.\n";
}


int main(int argc, char **argv)
{
    std::string input;

    PhoneBook phonebook;
    // std::map<std::string, names> phonebook;
    // std::map<std::string, bool> bookmark;

    while(1) {

        std::cout << "-------------------------------\n";
        std::cout << "[COMMAND] ADD, SEARCH, REMOVE, BOOKMARK, EXIT\n";
        std::cout << "Enter the command : ";
        std::cin >> input;

        QString qstr = QString::fromStdString(input).toUpper();


        if (!qstr.compare("ADD")) {
            std::cout << "add!\n";
            getAndAddInformation(&phonebook);

        } else if (!qstr.compare("SEARCH")) {
            std::cout << "SEARCH!\n";
            // todo 0개 일 때
            phonebook.search();

        } else if (!qstr.compare("REMOVE")) {
            std::cout << "REMOVE!\n";
            // index 또는 폰번호를 통해 연락처를 지울 수 있다.

        } else if (!qstr.compare("BOOKMARK")) {
            std::cout << "BOOKMARK!\n";
            // 북마크된 연락처들을 보여줘야 한다.
            // 북마크 해제

        } else if (!qstr.compare("EXIT")) {
            return 0;
        } else {
            std::cout << ">> Enter the correct command. <<\n";
            continue;
        }
    }
}
