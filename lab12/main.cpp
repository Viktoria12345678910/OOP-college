#include "mainwindow.h"
#include "mysqldbmanager.h"
#include "sqlitedbmanager.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBManager* dbManager = MySqlDBManager::getInstance();
    dbManager->connectToDataBase();

    MainWindow window(dbManager);
    window.show();
    return a.exec();
}
