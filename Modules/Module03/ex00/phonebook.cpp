#include "phonebook.h"
#include "./ui_phonebook.h"
#include <QMessageBox>

#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

QString name = "Name";
QString number = "Number";
QString nickname = "Nickname";


PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
    , model(new QStandardItemModel(0, 3, this)) // 초기화: 0 rows, 3 columns
{
    ui->setupUi(this);

    ui->comboBox->addItem(name);
    ui->comboBox->addItem(number);
    ui->comboBox->addItem(nickname);
    ui->comboBox->setCurrentIndex(1);

    model->setHorizontalHeaderLabels(QStringList() << name << number << nickname);
    ui->searchTableView->setModel(model);
    ui->searchTableView->setCornerButtonEnabled(false);

    hideEditWidget();
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

        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
    } else {

        if (phonebook.find(number) != phonebook.end()) {
            QMessageBox::warning(this, "Duplicate", "Number already exists!");
            return;
        }
        addToPhonebook(name, number, nickname);

        ui->nameInput->clear();
        ui->numberInput->clear();
        ui->nicknameInput->clear();

        populateTableView();
    }
}

void PhoneBook::on_removeButton_clicked()
{
    // QString number = getSelectedNumber();
    // if (number.isNull())
    //     return;

    // get selected row
    QModelIndexList selectedIndexes = ui->searchTableView->selectionModel()->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "No item selected!");
        return;
    }

    // 첫 번째 선택된 인덱스 가져오기
    QModelIndex selectedProxyIndex = selectedIndexes.at(0);

    // check is proxyModel QSortFilterProxyModel?
    QSortFilterProxyModel* proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->searchTableView->model());
    if (proxyModel) {

        // 선택된 인덱스를 원본 모델의 인덱스로 변환
        QModelIndex selectedSourceIndex = proxyModel->mapToSource(selectedProxyIndex);

        // 원본 모델의 해당 행과 열에서 데이터 가져오기
        QString number = model->item(selectedSourceIndex.row(), 1)->text();

        removeFromPhonebook(number);
    } else {

        QString number = ui->searchTableView->model()->data(selectedProxyIndex).toString();

        removeFromPhonebook(number);
    }


    // removeFromPhonebook(number);
    populateTableView();
}

void PhoneBook::on_clearButton_clicked()
{
    ui->nameInput->clear();
    ui->numberInput->clear();
    ui->nicknameInput->clear();
}

void PhoneBook::on_searchButton_clicked()
{
    QString input = ui->searchInput->text();
    QString col = ui->comboBox->currentText();
    int colNum = -1;

    if (col == name)
        colNum = 0;
    else if (col == number)
        colNum = 1;
    else if (col == nickname)
        colNum = 2;
    else
        QMessageBox::warning(this, "Selection Error", "No box selected!");

    qDebug() << colNum;
    if (input.isEmpty())
        populateTableView();
    else
        searchColumn(input, colNum);
}

void PhoneBook::addToPhonebook(const QString name, const QString number, const QString nickname)
{
    phonebook[number] = Information(name, number, nickname);
}

void PhoneBook::populateTableView()
{
    // model reset
    model->removeRows(0, model->rowCount());

    // set the table
    int row = 0;
    for (const auto &entry : phonebook) {

        const QString number = entry.first;
        Information info = entry.second;

        QList<QStandardItem *> newRow;
        newRow.append(new QStandardItem(info.getName()));
        newRow.append(new QStandardItem(number));
        newRow.append(new QStandardItem(info.getNickname()));

        model->insertRow(row, newRow);
        ++row;
    }
    ui->searchTableView->setModel(model);
}

void PhoneBook::removeFromPhonebook(const QString &number)
{
    auto it = phonebook.find(number);

    if (it != phonebook.end())
        phonebook.erase(it);
}

void PhoneBook::searchColumn(const QString searchText, int column) {

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);

    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterKeyColumn(column);

    QRegularExpression regExp(searchText, QRegularExpression::CaseInsensitiveOption);
    proxyModel->setFilterRegularExpression(regExp);

    ui->searchTableView->setModel(proxyModel);
}

void PhoneBook::on_SaveButton_clicked()
{
    // export to CSV
    QString fileName = QFileDialog::getSaveFileName(this, "Save as", "", "CSV Files (*.csv)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

        QTextStream stream(&file);

        // input header
        for (int i = 0; i < model->columnCount(); ++i) {

            stream << model->headerData(i, Qt::Horizontal).toString();
            if (i < model->columnCount() - 1)
                stream << ",";
        }
        stream << "\n";

        // input data
        for (int i = 0; i < model->rowCount(); ++i) {
            for (int j = 0; j < model->columnCount(); ++j) {
                stream << model->data(model->index(i, j)).toString();
                if (j < model->columnCount() - 1)
                    stream << ",";
            }
            stream << "\n";
        }

        file.close();

    } else
        QMessageBox::warning(this, "File Error", "Unable to save the file.");
}


void PhoneBook::on_LoadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV Files (*.csv)");

    if (fileName.isEmpty())
        return;


    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        QTextStream stream(&file);

        // reset model
        model->removeRows(0, model->rowCount());

        // read header
        if (!stream.atEnd()) {

            QString line = stream.readLine();
            QStringList headers = line.split(",");
            model->setHorizontalHeaderLabels(headers);
        }

        // read data
        while (!stream.atEnd()) {

            QString line = stream.readLine();
            QStringList items = line.split(",");
            QList<QStandardItem *> newRow;

            for (const QString &item : items)
                newRow.append(new QStandardItem(item));

            model->appendRow(newRow);
        }

        file.close();

    } else
        QMessageBox::warning(this, "File Error", "Unable to open the file.");
}

void PhoneBook::hideEditWidget() {

    ui->editNameLabel->hide();
    ui->editNumberLabel->hide();
    ui->editNicknameLabel->hide();

    ui->editNameInput->hide();
    ui->editNumberInput->hide();
    ui->editNicknameInput->hide();

    ui->saveEditButton->hide();
}

// void PhoneBook::showEditWidget() {

//     ui->editNameLabel->show();
//     ui->editNumberLabel->show();
//     ui->editNicknameLabel->show();

//     ui->editNameInput->show();
//     ui->editNumberInput->show();
//     ui->editNicknameInput->show();

//     ui->saveEditButton->show();
// }



// void PhoneBook::on_editButton_clicked()
// {
    // ui->editButton->hide();
    // showEditWidget();

    // setTheEditNumberToWidget();
// }

// void PhoneBook::setTheEditNumberToWidget() {

//     QString number = getSelectedNumber();
//     if (number.isNull())
//         return;

//     // edit = number;

//     auto it = phonebook.find(number);
//     if (it != phonebook.end()) {
//         ui->editNameInput->setText(it->second.getName());
//         ui->editNumberInput->setText(number);
//         ui->editNicknameInput->setText(it->second.getNickname());
//     } else
//         QMessageBox::warning(this, "Selection Error", "select err");

// }

// QString PhoneBook::getSelectedNumber() {

    // // get selected row
    // QModelIndexList selectedIndexes = ui->searchTableView->selectionModel()->selectedIndexes();

    // if (selectedIndexes.isEmpty()) {
    //     QMessageBox::warning(this, "Selection Error", "No item selected!");
    //     return NULL;
    // }

    // // 첫 번째 선택된 인덱스 가져오기
    // QModelIndex selectedProxyIndex = selectedIndexes.at(0);

    // // check is proxyModel QSortFilterProxyModel?
    // QSortFilterProxyModel* proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->searchTableView->model());

    // // 선택된 인덱스를 원본 모델의 인덱스로 변환
    // if (proxyModel)
    //     selectedProxyIndex = proxyModel->mapToSource(selectedProxyIndex);

    // // 원본 모델의 해당 행과 열에서 데이터 가져오기
    // return model->item(selectedProxyIndex.row(), 1)->text();
// }

// void PhoneBook::on_saveEditButton_clicked()
// {
//     QString name = ui->editNameInput->text();
//     QString number = ui->editNumberInput->text();
//     QString nickname = ui->editNicknameInput->text();

//     // auto it = phonebook.find(edit);

//     // if (it != phonebook.end()) {
//     //     if (it->first != number) {
//     //         // 기존 번호와 입력된 번호가 다른 경우, 기존 항목을 삭제하고 새로운 항목 추가
//     //         phonebook.erase(it); // 기존 항목 삭제
//     //         addToPhonebook(name, number, nickname); // 새로운 항목 추가
//     //     } else {
//     //         // 같은 번호인 경우, 이름과 별명을 수정함
//     //         it->second.setName(name); // 이름 수정
//     //         it->second.setNickname(nickname); // 별명 수정
//     //     }
//     // }
// }

