#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <map>
#include "information.h"
#include <QString>

class PhoneBook
{
private:
    std::map<std::string, Information> phonebook;

    void showPage(int pageNum);
    bool isSingleValidNumber(std::string);

public:

    // std::map<std::string, Information> phonebook;
    PhoneBook();

    void add(std::string name, std::string number, std::string nickname);
    void search();
    void remove();
    void bookmarkList();


};
#endif // PHONEBOOK_H
