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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pbOpenNotModalDialog;
    QPushButton *pbOpenModalDialog;
    QPushButton *pbTurnOnOff;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        pbOpenNotModalDialog = new QPushButton(centralwidget);
        pbOpenNotModalDialog->setObjectName("pbOpenNotModalDialog");

        verticalLayout->addWidget(pbOpenNotModalDialog);

        pbOpenModalDialog = new QPushButton(centralwidget);
        pbOpenModalDialog->setObjectName("pbOpenModalDialog");

        verticalLayout->addWidget(pbOpenModalDialog);

        pbTurnOnOff = new QPushButton(centralwidget);
        pbTurnOnOff->setObjectName("pbTurnOnOff");

        verticalLayout->addWidget(pbTurnOnOff);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
        pbOpenNotModalDialog->setText(QCoreApplication::translate("MainWindow", "\320\246\321\216 \320\272\320\275\321\226\320\277\320\276\321\207\320\272\321\203 \321\207\321\226\320\277\320\260\321\202\320\270 \320\274\320\276\320\266\320\275\320\260", nullptr));
        pbOpenModalDialog->setText(QCoreApplication::translate("MainWindow", "\320\246\321\216 \320\272\320\275\321\226\320\277\320\276\321\207\320\272\321\203 \320\275\320\265 \321\207\321\226\320\277\320\260\320\271\321\202\320\265", nullptr));
        pbTurnOnOff->setText(QCoreApplication::translate("MainWindow", "\320\262\321\226\320\264\320\272\320\273\321\216\321\207\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
