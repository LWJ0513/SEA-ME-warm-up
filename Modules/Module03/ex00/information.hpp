#ifndef INFORMATION_HPP
#define INFORMATION_HPP

#include <string>
#include <QString>

class Information
{
private:
    std::string name;
    std::string number;
    std::string nickname;

public:
    void setName(std::string);
    void setNumber(std::string);
    void setNickname(std::string);
    std::string getName();
    std::string getNumber();
    std::string getNickname();

    Information();
    Information(QString, QString, QString);
};

#endif // INFORMATION_HPP
