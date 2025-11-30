#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "dbmanager.h"
#include "student.h"
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DBManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_aCreateObject_triggered();

    void on_aQuit_triggered();


private:
    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();
    DBManager* dbManager;
    QSqlTableModel* model;
    Ui::MainWindow *ui;
    Student *student;
    void notNumeric(int i);
    void notAllFilled();
    bool createObject();
    void showObject();
    QString error;

};
#endif // MAINWINDOW_H
