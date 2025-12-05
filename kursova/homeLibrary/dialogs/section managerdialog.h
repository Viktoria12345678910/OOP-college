#ifndef SECTION MANAGERDIALOG_H
#define SECTION MANAGERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

class NewSectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewSectionDialog(QWidget *parent = nullptr);

private slots:
    void onSave();

private:
    void setupUI();

    QLineEdit *m_nameEdit;
    QLineEdit *m_abbreviationEdit;
    QTextEdit *m_descriptionEdit;
    QLineEdit *m_pathEdit;
};

#endif // SECTION MANAGERDIALOG_H
