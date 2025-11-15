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
    QLineEdit *leId;
    QLineEdit *leAddress;
    QLineEdit *leFirstName;
    QLineEdit *leFaculty;
    QLineEdit *lePaternalName;
    QLabel *lbStudentInfo;
    QLineEdit *lePhoneNumber;
    QLineEdit *leYear;
    QLineEdit *leLastName;
    QLineEdit *leDate;
    QLineEdit *leGroup;
    QPushButton *showInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 19, 781, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leId = new QLineEdit(gridLayoutWidget);
        leId->setObjectName("leId");

        gridLayout->addWidget(leId, 0, 0, 1, 1);

        leAddress = new QLineEdit(gridLayoutWidget);
        leAddress->setObjectName("leAddress");

        gridLayout->addWidget(leAddress, 4, 1, 1, 1);

        leFirstName = new QLineEdit(gridLayoutWidget);
        leFirstName->setObjectName("leFirstName");

        gridLayout->addWidget(leFirstName, 0, 1, 1, 1);

        leFaculty = new QLineEdit(gridLayoutWidget);
        leFaculty->setObjectName("leFaculty");

        gridLayout->addWidget(leFaculty, 6, 1, 1, 1);

        lePaternalName = new QLineEdit(gridLayoutWidget);
        lePaternalName->setObjectName("lePaternalName");

        gridLayout->addWidget(lePaternalName, 2, 1, 1, 1);

        lbStudentInfo = new QLabel(gridLayoutWidget);
        lbStudentInfo->setObjectName("lbStudentInfo");
        lbStudentInfo->setWordWrap(true);

        gridLayout->addWidget(lbStudentInfo, 11, 0, 1, 2);

        lePhoneNumber = new QLineEdit(gridLayoutWidget);
        lePhoneNumber->setObjectName("lePhoneNumber");

        gridLayout->addWidget(lePhoneNumber, 6, 0, 1, 1);

        leYear = new QLineEdit(gridLayoutWidget);
        leYear->setObjectName("leYear");

        gridLayout->addWidget(leYear, 9, 0, 1, 1);

        leLastName = new QLineEdit(gridLayoutWidget);
        leLastName->setObjectName("leLastName");

        gridLayout->addWidget(leLastName, 2, 0, 1, 1);

        leDate = new QLineEdit(gridLayoutWidget);
        leDate->setObjectName("leDate");

        gridLayout->addWidget(leDate, 4, 0, 1, 1);

        leGroup = new QLineEdit(gridLayoutWidget);
        leGroup->setObjectName("leGroup");

        gridLayout->addWidget(leGroup, 9, 1, 1, 1);

        showInfo = new QPushButton(gridLayoutWidget);
        showInfo->setObjectName("showInfo");

        gridLayout->addWidget(showInfo, 10, 0, 1, 2);

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
        lbStudentInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        showInfo->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \321\226\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\216 \320\277\321\200\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
