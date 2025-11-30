#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include "dbmanager.h"
#include <QSqlError>
#include <vector>

MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , dbManager(dbManager)
    , ui(new Ui::MainWindow)
    , student(nullptr)

{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    if (student != nullptr) {
          delete student;
      }
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
    bool success;
    if (student != nullptr) {
            delete student;
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
                   student = new Student(id, firstName, lastName, paternalName,
                                       date, addres, phoneNumber, year, group, faculty);
                   Student student2(id, firstName, lastName, paternalName,
                                    date, addres, phoneNumber, year, group, faculty);
                   dbManager->inserIntoTable(student2);

               }
            if(student != nullptr){
                // if(dbManager->inserIntoTable(*student)){
                    // QString info = student->toString();
                    // QMessageBox::information(this, "Успіх", "Об'єкт Student створено! \n"+info);
                // }
                // else{
                     // QMessageBox::warning(this, "Помилка", "Не вдалося вставити в БД! Перевірте консоль.");
                // }
                QString info = student->toString();
                QMessageBox::information(this, "Успіх", "Об'єкт Student створено! \n"+info);
                success = true;
            }
            else{
                success = false;
                QMessageBox::information(this, "Успіх", "student is nullptr");
            }
        return success;
    }

}

// void MainWindow::showObject(){
//     if(student == nullptr) {
//             QMessageBox::warning(this, "Помилка", "Спочатку створіть об'єкт Student!");
//             return;
//         }
//     QString info = student->toString();
// }


void MainWindow::on_aCreateObject_triggered()
{
     createObject();
}


void MainWindow::on_aQuit_triggered()
{
    QApplication::exit();
}




void MainWindow::setupModel(const QString& tableName, const QStringList& headers) {
    /* Виконуємо ініціалізацію моделі представлення даних
     * з вказанням імені таблиці в базі даних, до якої
     * буде виконуватись звернення
     * */
    model = new QSqlTableModel(this, dbManager->getDB());
    model->setTable(tableName);

    // Встановлюємо назви стовпців в таблиці із сортуванням даних
    for (int i = 0, j = 0; i < model->columnCount(); i++, j++) {
        model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }
    // Встановлюємо сортування по збільшення даних по нульовому стовпцю
    model->setSort(0, Qt::AscendingOrder);
}

void MainWindow::createUI() {
    // Встановлюємо модель для TableView
    ui->tableView->setModel(model);
    // Приховуємо колонку з id таблиці БД
    ui->tableView->setColumnHidden(0, true);
    // Дозволяємо виділення рядків
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Встановлюємо режим виділення лише одного рядка в таблиці
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Встановлюємо розмір колонок по вмісту
    ui->tableView->resizeColumnsToContents();
    // Встановлюємо стратегію редагування - при подвійному кліку
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    // Розтягуємо останній стовпчик tableView на всю ширину вікна
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    // Виконуємо вибірку даних із таблиці
    model->select();
}

