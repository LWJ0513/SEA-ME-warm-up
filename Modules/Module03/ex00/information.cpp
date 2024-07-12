#include "information.hpp"
#include <QDebug>

Information::Information() {}

Information::Information(QString name, QString number, QString nickname) : name(name), number(number), nickname(nickname) {}

void Information::setName(QString name){
    this->name = name;
}

void Information::setNumber(QString number){
    this->number = number;
}

void Information::setNickname(QString nickname){
    this->nickname = nickname;
}

const QString Information::getName(){
    return name;
}

const QString Information::getNumber(){
    return number;
}

const QString Information::getNickname(){
    return nickname;
}

void Information::printDebug() {

    qDebug() << "name : " << name << "\n"
             << "number : " << number << "\n"
             << "nickname : " << nickname<< "\n";

}
