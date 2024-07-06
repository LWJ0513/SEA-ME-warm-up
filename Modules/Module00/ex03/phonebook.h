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
    std::map<std::string, Information> bookmarks;

    int showPhonebookPage(int pageNum);
    int showBookmarkPage(int pageNum);
    bool isSingleValidNumber(std::string, int);
    void saveToBookmark(std::map<std::string, Information>::iterator);
    bool removeTheNumber(std::string);
    void removeByIndex(int, int);
    void removeByNumber(int, int);

public:
    PhoneBook();

    void add(std::string name, std::string number, std::string nickname);
    void search();
    void remove();
    void bookmarkList();
    bool isAllNumber(std::string);

};
#endif // PHONEBOOK_H
