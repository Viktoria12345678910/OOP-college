#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QComboBox>
#include "database.h"

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

private:
    void setupUI();
    void loadSections();
    void loadBooks(int sectionId = -1);

    QTabWidget *m_tabWidget;
    QTableView *m_booksTable;
    QTableView *m_sectionsTable;
    QTableView *m_usersTable;
    QSqlTableModel *m_booksModel;
    QSqlTableModel *m_sectionsModel;
    QSqlTableModel *m_usersModel;
    QComboBox *m_sectionFilter;

    int m_currentUserId;
};

#endif // MAINWINDOW_H
