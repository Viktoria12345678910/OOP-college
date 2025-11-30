#ifndef NEWBOOKDIALOG_H
#define NEWBOOKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QTextEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>

class NewBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewBookDialog(QWidget *parent = nullptr);

private slots:
    void onSave();
    void onSelectCover();

private:
    void setupUI();
    void loadSections();

    QComboBox *m_mediumCombo;
    QLineEdit *m_titleEdit;
    QLineEdit *m_authorEdit;
    QLineEdit *m_genreEdit;
    QSpinBox *m_ratingSpin;
    QTextEdit *m_descriptionEdit;
    QCheckBox *m_readCheck;
    QComboBox *m_viewRightsCombo;
    QComboBox *m_sectionCombo;
    QPushButton *m_coverButton;
    QLabel *m_coverPreview;

    QByteArray m_coverData;
};

#endif // NEWBOOKDIALOG_H
