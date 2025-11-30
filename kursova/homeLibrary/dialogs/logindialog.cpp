#include "logindialog.h"
#include "newaccountdialog.h"
#include "../database.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , m_userId(-1)
{
    setupUI();
}

void LoginDialog::setupUI()
{
    setWindowTitle("Вхід до системи");
    setMinimumWidth(350);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    m_usernameEdit = new QLineEdit();
    formLayout->addRow("Ім'я користувача:", m_usernameEdit);

    m_passwordEdit = new QLineEdit();
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Пароль:", m_passwordEdit);

    mainLayout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    m_loginButton = new QPushButton("Увійти");
    m_loginButton->setDefault(true);
    connect(m_loginButton, &QPushButton::clicked, this, &LoginDialog::onLogin);
    buttonLayout->addWidget(m_loginButton);

    m_registerButton = new QPushButton("Реєстрація");
    connect(m_registerButton, &QPushButton::clicked, this, &LoginDialog::onRegister);
    buttonLayout->addWidget(m_registerButton);

    mainLayout->addLayout(buttonLayout);
}

void LoginDialog::onLogin()
{
    QString username = m_usernameEdit->text();
    QString password = m_passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть всі поля!");
        return;
    }

    if (Database::instance().authenticateUser(username, password)) {
        m_username = username;
        m_userId = Database::instance().getUserId(username);
        accept();
    } else {
        QMessageBox::warning(this, "Помилка", "Невірне ім'я користувача або пароль!");
    }
}

void LoginDialog::onRegister()
{
    NewAccountDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Успіх",
                               "Акаунт створено! Тепер ви можете увійти.");
    }
}
