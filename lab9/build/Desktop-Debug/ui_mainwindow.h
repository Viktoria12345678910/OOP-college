/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit2;
    QLabel *lbl2;
    QPushButton *pb2;
    QLineEdit *lineEdit1;
    QPushButton *pbExit;
    QPushButton *pbShow;
    QLineEdit *leEnter;
    QLabel *lbText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1042, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(370, 140, 511, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit2 = new QLineEdit(gridLayoutWidget);
        lineEdit2->setObjectName("lineEdit2");

        gridLayout->addWidget(lineEdit2, 3, 0, 1, 1);

        lbl2 = new QLabel(gridLayoutWidget);
        lbl2->setObjectName("lbl2");

        gridLayout->addWidget(lbl2, 8, 0, 1, 1);

        pb2 = new QPushButton(gridLayoutWidget);
        pb2->setObjectName("pb2");

        gridLayout->addWidget(pb2, 1, 0, 1, 1);

        lineEdit1 = new QLineEdit(gridLayoutWidget);
        lineEdit1->setObjectName("lineEdit1");

        gridLayout->addWidget(lineEdit1, 2, 0, 1, 1);

        pbExit = new QPushButton(gridLayoutWidget);
        pbExit->setObjectName("pbExit");

        gridLayout->addWidget(pbExit, 0, 0, 1, 2);

        pbShow = new QPushButton(gridLayoutWidget);
        pbShow->setObjectName("pbShow");

        gridLayout->addWidget(pbShow, 1, 1, 1, 1);

        leEnter = new QLineEdit(gridLayoutWidget);
        leEnter->setObjectName("leEnter");

        gridLayout->addWidget(leEnter, 2, 1, 1, 1);

        lbText = new QLabel(gridLayoutWidget);
        lbText->setObjectName("lbText");

        gridLayout->addWidget(lbText, 8, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1042, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl2->setText(QCoreApplication::translate("MainWindow", "Sum", nullptr));
        pb2->setText(QCoreApplication::translate("MainWindow", "Display Sum", nullptr));
        pbExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pbShow->setText(QCoreApplication::translate("MainWindow", "Display text", nullptr));
        lbText->setText(QCoreApplication::translate("MainWindow", "Your text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
