#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showInfo_clicked();

    void on_aCreateObject_triggered();

    void on_aQuit_triggered();

    void on_aShowObject_triggered();

private:
    Ui::MainWindow *ui;
    Student *student;
    void notNumeric(int i);
    void notAllFilled();
    bool createObject();
    void showObject();

};
#endif // MAINWINDOW_H
