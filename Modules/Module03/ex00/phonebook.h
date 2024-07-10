#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//연락처 목록에 대한 멤버 변수와 목록에서 연락처를 추가, 제거 및 검색하는 멤버 함수가 있어야 합니다.
#include <QMainWindow>
#include "information.hpp"
#include <map>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class PhoneBook;
}
QT_END_NAMESPACE

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private slots:

    std::map<QString, Information> phonebook;
    std::map<QString, Information> bookmarks;

    void on_addButton_clicked();

    void addToPhonebook(const QString, const QString, const QString);
    void populateTableView();   // QTableView에 연락처 목록을 표시하는 함수

private:
    Ui::PhoneBook *ui;
    QStandardItemModel *model;
};
#endif // PHONEBOOK_H
