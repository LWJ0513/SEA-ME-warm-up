#ifndef INFORMATION_HPP
#define INFORMATION_HPP

#include <QString>

class Information
{
private:
    QString name;
    QString number;
    QString nickname;

public:
    void setName(QString);
    void setNumber(QString);
    void setNickname(QString);
    const QString getName();
    const QString getNumber();
    const QString getNickname();

    Information();
    Information(QString, QString, QString);

    void printDebug();
};

#endif // INFORMATION_HPP
