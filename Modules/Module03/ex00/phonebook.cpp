#include "phonebook.h"
#include "./ui_phonebook.h"
#include <QMessageBox>

#include <QTableView>
#include <QStandardItemModel>


PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
    , model(new QStandardItemModel(0, 3, this)) // 초기화: 0 rows, 3 columns
{
    ui->setupUi(this);

    model->setHorizontalHeaderLabels(QStringList() << "Name" << "Phone Number" << "Nickname");

    // QTableView에 모델 설정
    ui->tableView->setModel(model);
}

PhoneBook::~PhoneBook()
{
    delete ui;
}

void PhoneBook::on_addButton_clicked()
{
    QString name = ui->nameInput->text();
    QString number = ui->numberInput->text();
    QString nickname = ui->nicknameInput->text();

    if (name.isEmpty() || number.isEmpty() || nickname.isEmpty()) {
        // 메시지 박스에 경고 표시
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
    } else {
        ui->nameInput->clear();
        ui->numberInput->clear();
        ui->nicknameInput->clear();

        if (phonebook.find(number) != phonebook.end()) {
            QMessageBox::warning(this, "Duplicate", "Name already exists!");
            return;
        }
        addToPhonebook(name, number, nickname);
        populateTableView();


    }
}

void PhoneBook::addToPhonebook(const QString name, const QString number, const QString nickname)
{
    // 중복 체크
    if (phonebook.find(name) != phonebook.end()) {
        QMessageBox::warning(this, "Duplicate", "Name already exists!");
        return;
    }

    // 연락처 목록에 추가
    phonebook[name] = Information(name, number, nickname);
}
