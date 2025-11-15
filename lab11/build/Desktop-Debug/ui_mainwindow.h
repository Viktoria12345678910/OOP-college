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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *aCreateObject;
    QAction *aShowObject;
    QAction *aQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lePaternalName;
    QLabel *label_7;
    QLineEdit *leFaculty;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_2;
    QPushButton *showInfo;
    QLineEdit *leAddress;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *leLastName;
    QLineEdit *leDate;
    QLabel *label;
    QLabel *label_10;
    QLineEdit *leFirstName;
    QLineEdit *lePhoneNumber;
    QLineEdit *leGroup;
    QLineEdit *leId;
    QLabel *label_6;
    QLineEdit *leYear;
    QLabel *label_11;
    QLabel *lbStudentInfo;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        aCreateObject = new QAction(MainWindow);
        aCreateObject->setObjectName("aCreateObject");
        aShowObject = new QAction(MainWindow);
        aShowObject->setObjectName("aShowObject");
        aQuit = new QAction(MainWindow);
        aQuit->setObjectName("aQuit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        lePaternalName = new QLineEdit(centralwidget);
        lePaternalName->setObjectName("lePaternalName");

        gridLayout->addWidget(lePaternalName, 3, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        leFaculty = new QLineEdit(centralwidget);
        leFaculty->setObjectName("leFaculty");

        gridLayout->addWidget(leFaculty, 1, 3, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 5, 2, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 2, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        showInfo = new QPushButton(centralwidget);
        showInfo->setObjectName("showInfo");

        gridLayout->addWidget(showInfo, 9, 3, 1, 1);

        leAddress = new QLineEdit(centralwidget);
        leAddress->setObjectName("leAddress");

        gridLayout->addWidget(leAddress, 2, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        leLastName = new QLineEdit(centralwidget);
        leLastName->setObjectName("leLastName");

        gridLayout->addWidget(leLastName, 2, 1, 1, 1);

        leDate = new QLineEdit(centralwidget);
        leDate->setObjectName("leDate");

        gridLayout->addWidget(leDate, 5, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        leFirstName = new QLineEdit(centralwidget);
        leFirstName->setObjectName("leFirstName");

        gridLayout->addWidget(leFirstName, 1, 1, 1, 1);

        lePhoneNumber = new QLineEdit(centralwidget);
        lePhoneNumber->setObjectName("lePhoneNumber");

        gridLayout->addWidget(lePhoneNumber, 5, 1, 1, 1);

        leGroup = new QLineEdit(centralwidget);
        leGroup->setObjectName("leGroup");

        gridLayout->addWidget(leGroup, 0, 3, 1, 1);

        leId = new QLineEdit(centralwidget);
        leId->setObjectName("leId");

        gridLayout->addWidget(leId, 0, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        leYear = new QLineEdit(centralwidget);
        leYear->setObjectName("leYear");

        gridLayout->addWidget(leYear, 3, 3, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        lbStudentInfo = new QLabel(centralwidget);
        lbStudentInfo->setObjectName("lbStudentInfo");
        lbStudentInfo->setWordWrap(true);

        gridLayout->addWidget(lbStudentInfo, 7, 1, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(aCreateObject);
        menu->addSeparator();
        menu->addAction(aShowObject);
        menu->addSeparator();
        menu->addAction(aQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        aCreateObject->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\236\320\261'\321\224\320\272\321\202", nullptr));
        aShowObject->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
        aQuit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\321\201\320\260", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\200\320\276\320\264\320\266\320\265\320\275\320\275\321\217(\320\262 \321\204\320\276\321\200\320\274\320\260\321\202\321\226 \320\264\320\264\320\274\320\274\321\200\321\200):", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\240\321\226\320\272 \320\275\320\260\320\262\321\207\320\260\320\275\320\275\321\217:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\226\320\267\320\262\320\270\321\211\320\265:", nullptr));
        showInfo->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276-\320\261\320\260\321\202\321\214\320\272\320\276\320\262\321\226:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260 \320\277\320\276 \321\201\320\277\320\270\321\201\320\272\321\203:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\206\320\274'\321\217:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\203:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\272\321\203\320\273\321\214\321\202\320\265\321\202:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\206\320\275\321\204\320\276\321\200\320\274\320\260\321\206\321\226\321\217 \320\277\321\200\320\276 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        lbStudentInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261'\321\224\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
