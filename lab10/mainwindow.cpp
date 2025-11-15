#include "mainwindow.h"
#include "ui_mainwindow.h"
bool on = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->pbOpenModalDialog, &QPushButton::clicked,this, &MainWindow::OpenModalDialog);
    connect(ui->pbOpenNotModalDialog, &QPushButton::clicked,this, &MainWindow::OpenNotModalDialog);
    connect(ui->pbTurnOnOff, &QPushButton::clicked, this, &MainWindow::TurnOnOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenModalDialog(){

    QMessageBox msgBox;
    msgBox.setText("Ви натиснули ту кніпочку, яку вам сказали не чіпати... Тепер вас рознесе на... молекули");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::OpenNotModalDialog(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                "/home",
                tr("Images (*.png *.xpm *.jpg)"));

}

bool MainWindow::TurnOnOff(){
    if(on){
        ui->pbTurnOnOff->setText("Підключити");
        disconnect(ui->pbOpenModalDialog, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
        disconnect(ui->pbOpenNotModalDialog, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
        on = false;
    }
    else
    {
        ui->pbTurnOnOff->setText("Відключити");
        connect(ui->pbOpenModalDialog, &QPushButton::clicked,this, &MainWindow::OpenModalDialog);
        connect(ui->pbOpenNotModalDialog, &QPushButton::clicked,this, &MainWindow::OpenNotModalDialog);
        on = true;
    }
    return on;
}


