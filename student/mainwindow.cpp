#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "student.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leId->setPlaceholderText("Введіть номер по списку");
    ui->leFirstName->setPlaceholderText("Введіть ім'я");
    ui->leLastName->setPlaceholderText("Введіть прізвище");
    ui->lePaternalName->setPlaceholderText("Введіть побатькові");
    ui ->lePhoneNumber->setPlaceholderText("Введіть номер телефону");
    ui->leYear->setPlaceholderText("Введіть рік навчання");
    ui->leAddress->setPlaceholderText("Введіть домашню адресу");
    ui->leFaculty->setPlaceholderText("Введіть факультет");
    ui->leGroup->setPlaceholderText("Введіть групу");
    ui->leDate->setPlaceholderText("Введіть дату народження");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_showInfo_clicked()
{
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
    Student student(id, firstName, lastName, paternalName, date, addres, phoneNumber, year, group, faculty);
    QString info = student.toString();
    ui->lbStudentInfo->setText(info);
}

