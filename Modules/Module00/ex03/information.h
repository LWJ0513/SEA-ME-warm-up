#ifndef INFORMATION_H
#define INFORMATION_H

#include <string>

class Information
{
private:

public:
    std::string name;
    std::string number;
    std::string nickname;

    Information();
    Information(std::string, std::string, std::string);

};

#endif // INFORMATION_H
