#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QTextBrowser>
#include <QComboBox>
#include "database.h"
#include <QMessageBox>
#include <QSqlRecord>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewBook();
    void onNewSection();
    void onNewAccount();
    void onSectionChanged(int index);
    void onManageGroups();
    void onSearch(const QString &text);
    void onDeleteBook();
    void onDeleteSection();
    void onDeleteUser();

private:
    void setupUI();
    void loadSections();
    void loadBooks(int sectionId = -1);

    QTabWidget *mTabWidget;
    QTableView *mBooksTable;
    QTableView *mSectionsTable;
    QTableView *mUsersTable;
    QTextBrowser *mHelp;
    QSqlTableModel *mBooksModel;
    QSqlTableModel *mSectionsModel;
    QSqlTableModel *mUsersModel;
    QComboBox *mSectionFilter;
    QLineEdit *mSearchBar;
    QPushButton *mDeleteBook;
    QPushButton *mDeleteSection;
    QPushButton *mDeleteUser;


    int mCurrentUserId;
};

#endif // MAINWINDOW_H
