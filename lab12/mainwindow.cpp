#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentStudent(nullptr)
    , repository(new StudentRepository())
    , tableModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    DatabaseManager* dbManager = DatabaseManager::getInstance();
    if (dbManager->openDatabase()) {
        dbManager->initializeDatabase();
        refreshTableView();
    } else {
        QMessageBox::critical(this, "Помилка",
                              "Не вдалося підключитися до бази даних!");
    }
    qDebug()<<"it works";
}

MainWindow::~MainWindow()
{
    if (currentStudent != nullptr) {
        delete currentStudent;
    }
    delete repository;
    delete ui;
}



void MainWindow::on_aShowStudent_triggered()
{
    if (currentStudent == nullptr) {
        QMessageBox::information(this, "Інформація",
                                 "Пацієнт ще не створений.\nСпочатку створіть об'єкт.");
        return;
    }

    QString info = "Інформація про створеного пацієнта:\n\n";
    info += currentStudent->toString();

    QMessageBox::information(this, "Інформація про пацієнта", info);
}

void MainWindow::on_aQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::refreshTableView()
{
    tableModel->setQuery("SELECT id AS 'ID', "
                         "lastName AS 'Прізвище', "
                         "firstName AS 'Ім''я', "
                         "paternalName AS 'По батькові', "
                         "addres AS 'Адреса', "
                         "date AS 'Дата',"
                         "phoneNumber AS 'Номер телефон', "
                         "faculty AS 'Факультет', "
                         "year AS 'Курс', "
                         "groupName AS 'Група' "
                         "FROM students");

    ui->tableView->setModel(tableModel);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::notNumeric( int i){
    QMessageBox msgBox;
    QString notNumeric = " ";
    switch(i){
    case 0:
        {
        notNumeric = "номер по списку";
        break;
        }
    case 1:
        {
        notNumeric = "дата народження";
        break;
        }
    case 2:
        {
        notNumeric = "номер телефону";
        break;
        }
    case 3:
        {
        notNumeric = "рік навчання";
        break;
        }
    }
    msgBox.setText("Поле "+notNumeric+" має бути числом");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::notAllFilled(){
    QMessageBox msgBox;
    msgBox.setText("Значення усіх параметрів мають бути НЕ порожні");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

bool MainWindow::createObject(){
    bool success = false;
    if (currentStudent != nullptr) {
        delete currentStudent;
        currentStudent = nullptr;
    }


    QString id, firstName, lastName, paternalName, phoneNumber, year, addres, faculty, group, date;
    id = ui->leId->text();
    firstName = ui->leFirstName->text();
    lastName = ui->leLastName->text();
    paternalName = ui->lePaternalName->text();
    phoneNumber = ui ->lePhoneNumber->text();
    year = ui->leYear->text();
    addres = ui->leAddress->text();
    faculty = ui->leFaculty->text();
    group = ui->leGroup->text();
    date = ui->leDate->text();

    if(ui->leId->text().isEmpty() ||
        ui->leYear->text().isEmpty() ||
        ui->lePhoneNumber->text().isEmpty() ||
        ui->lePaternalName->text().isEmpty() ||
        ui->leLastName->text().isEmpty() ||
        ui->leGroup->text().isEmpty() ||
        ui->leFirstName->text().isEmpty() ||
        ui->leFaculty->text().isEmpty() ||
        ui->leDate->text().isEmpty() ||
        ui->leAddress->text().isEmpty())
    {
        notAllFilled();
        return false;
    }

    else{
        bool ok;
            bool allValid = true;

            id.toInt(&ok);
            if(!ok) {
                notNumeric(0); // id
                allValid = false;
            }

            date.toInt(&ok);
            if(!ok) {
                notNumeric(1); // date
                allValid = false;
            }

            phoneNumber.toInt(&ok);
            if(!ok) {
                notNumeric(2); // phoneNumber
                allValid = false;
            }

            year.toInt(&ok);
            if(!ok) {
                notNumeric(3); // year
                allValid = false;
            }

            if(allValid) {
                currentStudent = new Student(id, firstName, lastName, paternalName,
                                                 date, addres, phoneNumber, year, group, faculty);

                    QMessageBox::information(this, "Debug", "Перед addStudent");

                    bool result = repository->addStudent(*currentStudent);

                    QMessageBox::information(this, "Debug",
                        "Після addStudent. Result: " + QString(result ? "true" : "false"));

                    if(result) {
                        QString info = currentStudent->toString();
                        QMessageBox::information(this, "Успіх", "Студента створено!\n" + info);
                        refreshTableView();
                        success = true;
                    } else {
                        QMessageBox::critical(this, "Помилка", "addStudent повернув false!");
                    }
               }
            else
                success = false;
        return success;
    }

}




void MainWindow::on_aCreateObject_triggered()
{
    QMessageBox::information(this, "Успіх", "button works");
    createObject();
}

