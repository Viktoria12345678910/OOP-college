#include "section managerdialog.h"
#include "../database.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>

NewSectionDialog::NewSectionDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

void NewSectionDialog::setupUI()
{
    setWindowTitle("Додати нову секцію");
    setMinimumWidth(400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    m_nameEdit = new QLineEdit();
    formLayout->addRow("Назва*:", m_nameEdit);

    m_abbreviationEdit = new QLineEdit();
    formLayout->addRow("Абревіатура:", m_abbreviationEdit);

    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setMaximumHeight(100);
    formLayout->addRow("Опис:", m_descriptionEdit);
    m_pathEdit = new QLineEdit();
    formLayout->addRow("Шлях:", m_pathEdit);

    mainLayout->addLayout(formLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &NewSectionDialog::onSave);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    mainLayout->addWidget(buttonBox);
    }
void NewSectionDialog::onSave()
{
    if (m_nameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Назва секції обов'язкова!");
    return;
        }
    QString name = m_nameEdit->text();
    QString abbreviation = m_abbreviationEdit->text();
    QString description = m_descriptionEdit->toPlainText();
    QString path = m_pathEdit->text();

    int sectionId = Database::instance().createSection(
        name, abbreviation, description, path);

    if (sectionId > 0) {
        QMessageBox::information(this, "Успіх", "Секцію успішно додано!");
        accept();
    } else {
        QMessageBox::critical(this, "Помилка", "Не вдалось додати секцію!");
    }
}
