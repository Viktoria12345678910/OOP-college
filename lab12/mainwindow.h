#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
// #include "student.h"
class Student;

class QSqlTableModel;

class DBManager;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DBManager* dbManager,QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_aCreateObject_triggered();

    void on_aQuit_triggered();

    void on_aShowObject_triggered();

private:
    Ui::MainWindow *ui;
    void notNumeric(int i);
    void notAllFilled();
    bool createObject();
    void showObject();
    DBManager* dbManager;
    QSqlTableModel* model;
    Student* student;
    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();

};
#endif // MAINWINDOW_H
