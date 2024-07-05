#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <string>
#include <QString>

int main(int argc, char *argv[])
{
    QString s;
    std::string command;

    if (argc < 2) {
        std::cout << "write the correctarguments" << std::endl;
        return 1;
    }

    command.append(argv[1]);



    for (int i = 2; i < argc ; i++){

        s.append(argv[i]);
        if (i < argc -1)
            s.append(" ");
    }

    // std::cout << "input : " << s << std::endl;


    if (!command.compare("up"))
        std::cout << s.toUpper().toStdString() << std::endl;
    else if (!command.compare("down"))
        std::cout << s.toLower().toStdString() << std::endl ;
    else
        std::cout << "use command up or down!\n";

    return 0;
}
