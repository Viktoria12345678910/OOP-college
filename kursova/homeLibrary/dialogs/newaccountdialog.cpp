#include "newaccountdialog.h"
#include "../database.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>



NewAccountDialog::NewAccountDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

void NewAccountDialog::setupUI()
{
    setWindowTitle("Створити новий акаунт");
    setMinimumWidth(400);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    m_usernameEdit = new QLineEdit();
    formLayout->addRow("Ім'я користувача*:", m_usernameEdit);

    m_passwordEdit = new QLineEdit();
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Пароль*:", m_passwordEdit);

    m_confirmPasswordEdit = new QLineEdit();
    m_confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Підтвердження паролю*:", m_confirmPasswordEdit);

    mainLayout->addLayout(formLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &NewAccountDialog::onSave);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    mainLayout->addWidget(buttonBox);
}

void NewAccountDialog::onSave()
{
    if (m_usernameEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Ім'я користувача обов'язкове!");
        return;
    }

    if (m_passwordEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Пароль обов'язковий!");
        return;
    }

    if (m_passwordEdit->text() != m_confirmPasswordEdit->text()) {
        QMessageBox::warning(this, "Помилка", "Паролі не співпадають!");
        return;
    }

    if (Database::instance().createUser(m_usernameEdit->text(), m_passwordEdit->text())) {
        QMessageBox::information(this, "Успіх", "Акаунт успішно створено!");
        accept();
    } else {
        QMessageBox::critical(this, "Помилка", "Не вдалось створити акаунт!");
    }
}
