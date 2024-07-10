#include "information.hpp"

Information::Information() {}

Information::Information(std::string name, std::string number, std::string nickname) : name(name), number(number), nickname(nickname) {}

void Information::setName(std::string name){
    this->name = name;
}

void Information::setNumber(std::string number){
    this->number = number;
}

void Information::setNickname(std::string number){
    this->number = number;
}

std::string Information::getName(){
    return name;
}

std::string Information::getNumber(){
    return number;
}

std::string Information::getNickname(){
    return nickname;
}
