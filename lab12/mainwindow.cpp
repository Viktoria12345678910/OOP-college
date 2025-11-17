#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include "sqlitedbmanager.h"
#include "student.h"
#include <vector>

#include <QSqlTableModel>
#include <QSqlError>

MainWindow::MainWindow(DBManager* dbManager,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbManager(dbManager)
    , student(nullptr)
{
    ui->setupUi(this);
    qDebug() << "database connected "<< dbManager->getDB().isOpen();
    qDebug() << "database tables "<< dbManager->getDB().tables();
    this->setupModel(TABLE_STUDENTS,
                     QStringList() << tr("Hомер по списку")
                                   << tr("Ім'я")
                                   << tr("Прізвище")
                                   << tr("По-батькові")
                                   << tr("Дата народження")
                                   << tr("Адреса")
                                   << tr("Номер телефону")
                                   << tr("Факультет")
                                   << tr("Рік навчання")
                                   << tr("Група")
    );
    QMessageBox::information(this, "DB Status",
        QString("DB Open: %1\nTables: %2")
        .arg(dbManager->getDB().isOpen() ? "YES" : "NO")
        .arg(dbManager->getDB().tables().join(", ")));
    Student testStudent("999", "Test", "Student", "Middle", "010197", "Test Addres", "123", "engineer", "2", "a");
    bool result = dbManager->insertIntoTable(testStudent);
    QMessageBox::information(this, "test insert", result ? "SECCESS" : "FAILED:" + dbManager->getDB().lastError().text());
    this->createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (model)
        delete model;

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
    // Student student;
    bool success;
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
                Student student(id, firstName, lastName, paternalName, date, addres, phoneNumber, year, group, faculty);
                QString info = student.toString();

                if(dbManager->insertIntoTable(student)){
                    QMessageBox::information(this, "Успіх", "Об'єкт Student створено! \n"+info);
                    success = true;
                    this->createUI();
                    ui->leId->clear();
                    ui->leFirstName->clear();
                    ui->leLastName->clear();
                    ui->lePaternalName->clear();
                    ui->leDate->clear();
                    ui->leAddress->clear();
                    ui->lePhoneNumber->clear();
                    ui->leFaculty->clear();
                    ui->leYear->clear();
                    ui->leGroup->clear();
                    }
               }

        return success;
    }

}

void MainWindow::showObject(){
    QString info = student->toString();
    this->createUI();
}



void MainWindow::on_aCreateObject_triggered()
{
     createObject();
}


void MainWindow::on_aQuit_triggered()
{
    QApplication::exit();
}


void MainWindow::on_aShowObject_triggered()
{
    showObject();
}

void MainWindow::setupModel(const QString& tableName, const QStringList& headers) {
    model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    qDebug() << "Table name:"<<tableName;
    qDebug() << "brfore select row count" << model->rowCount();

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void MainWindow::createUI(){


    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    model->select();
    ui->tableView->show();
    qDebug() << "after select row count " << model->rowCount();
}
