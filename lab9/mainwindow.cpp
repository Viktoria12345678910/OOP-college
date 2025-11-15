#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leEnter->setPlaceholderText("Type your text here");
    ui->lineEdit1->setPlaceholderText("Enter first number");
    ui->lineEdit2->setPlaceholderText("Enter second number");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pbShow_clicked()
{
    QString text=ui->leEnter->text();
    ui->lbText->setText(text);
}





void MainWindow::on_pb2_clicked()
{
    int num1=ui->lineEdit1->text().toInt();
    int num2=ui->lineEdit2->text().toInt();
    int sum = num1 + num2;
    ui->lbl2->setText(QString::number(sum));
}


void MainWindow::on_pbExit_clicked()
{
    QApplication::exit();
}

