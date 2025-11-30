#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "student.h"
#include "studentrepository.h"
#include <QMainWindow>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aShowStudent_triggered();

    void on_aQuit_triggered();


    void on_aCreateObject_triggered();

private:
    Ui::MainWindow *ui;
    Student *currentStudent;
    StudentRepository *repository;
    QSqlQueryModel *tableModel;
    void notNumeric(int i);
    void notAllFilled();
    bool createObject();
    void showObject();
    void refreshTableView();
};

#endif // MAINWINDOW_H
