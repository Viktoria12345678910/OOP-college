#ifndef GROUPMANAGERDIALOG_H
#define GROUPMANAGERDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class GroupManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupManagerDialog(QWidget *parent = nullptr);

private slots:
    void onCreateGroup();
    void onDeleteGroup();
    void onManageMembers();
    void refreshGroupList();

private:
    void setupUI();

    QListWidget *m_groupsList;
    QPushButton *m_createButton;
    QPushButton *m_deleteButton;
    QPushButton *m_manageMembersButton;
};

#endif // GROUPMANAGERDIALOG_H
