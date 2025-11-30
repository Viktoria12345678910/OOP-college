#include "newbookdialog.h"
#include "../database.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QBuffer>
#include <QPixmap>
#include <QSqlQuery>

NewBookDialog::NewBookDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    loadSections();
}

void NewBookDialog::setupUI()
{
    setWindowTitle("Додати нову книгу");
    setMinimumWidth(500);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    // Тип носія
    m_mediumCombo = new QComboBox();
    m_mediumCombo->addItems({"Паперова", "Електронна", "Аудіокнига"});
    formLayout->addRow("Тип носія:", m_mediumCombo);

    // Назва
    m_titleEdit = new QLineEdit();
    formLayout->addRow("Назва*:", m_titleEdit);

    // Автор
    m_authorEdit = new QLineEdit();
    formLayout->addRow("Автор:", m_authorEdit);

    // Жанр
    m_genreEdit = new QLineEdit();
    formLayout->addRow("Жанр:", m_genreEdit);

    // Рейтинг
    m_ratingSpin = new QSpinBox();
    m_ratingSpin->setRange(1, 5);
    m_ratingSpin->setValue(3);
    formLayout->addRow("Рейтинг:", m_ratingSpin);

    // Опис
    m_descriptionEdit = new QTextEdit();
    m_descriptionEdit->setMaximumHeight(100);
    formLayout->addRow("Опис:", m_descriptionEdit);

    // Прочитано
    m_readCheck = new QCheckBox("Прочитано");
    formLayout->addRow("", m_readCheck);

    // Права перегляду
    m_viewRightsCombo = new QComboBox();
    m_viewRightsCombo->addItems({"Всі", "Тільки я", "Вибрати групу"});
    formLayout->addRow("Права перегляду:", m_viewRightsCombo);

    // Секція
    m_sectionCombo = new QComboBox();
    formLayout->addRow("Секція*:", m_sectionCombo);

    // Обкладинка
    QHBoxLayout *coverLayout = new QHBoxLayout();
    m_coverButton = new QPushButton("Вибрати обкладинку");
    connect(m_coverButton, &QPushButton::clicked, this, &NewBookDialog::onSelectCover);
    coverLayout->addWidget(m_coverButton);

    m_coverPreview = new QLabel();
    m_coverPreview->setFixedSize(100, 150);
    m_coverPreview->setFrameStyle(QFrame::Box);
    m_coverPreview->setScaledContents(true);
    coverLayout->addWidget(m_coverPreview);
    coverLayout->addStretch();

    formLayout->addRow("Обкладинка:", coverLayout);

    mainLayout->addLayout(formLayout);

    // Кнопки
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &NewBookDialog::onSave);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    mainLayout->addWidget(buttonBox);
}

void NewBookDialog::loadSections()
{
    QSqlQuery query("SELECT section_id, name FROM sections");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        m_sectionCombo->addItem(name, id);
    }
}

void NewBookDialog::onSelectCover()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, "Вибрати обкладинку", "", "Зображення (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            m_coverPreview->setPixmap(pixmap);

            QBuffer buffer(&m_coverData);
            buffer.open(QIODevice::WriteOnly);
            pixmap.save(&buffer, "PNG");
        }
    }
}

void NewBookDialog::onSave()
{
    if (m_titleEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Назва книги обов'язкова!");
        return;
    }

    if (m_sectionCombo->currentIndex() == -1) {
        QMessageBox::warning(this, "Помилка", "Оберіть секцію!");
        return;
    }

    QString medium = m_mediumCombo->currentText();
    QString title = m_titleEdit->text();
    QString author = m_authorEdit->text();
    QString genre = m_genreEdit->text();
    int rating = m_ratingSpin->value();
    QString description = m_descriptionEdit->toPlainText();
    bool read = m_readCheck->isChecked();
    QString viewRights = m_viewRightsCombo->currentText();
    int sectionId = m_sectionCombo->currentData().toInt();

    int bookId = Database::instance().createBook(
        medium, title, author, genre, rating, description,
        read, viewRights, m_coverData, sectionId);

    if (bookId > 0) {
        QMessageBox::information(this, "Успіх", "Книгу успішно додано!");
        accept();
    } else {
        QMessageBox::critical(this, "Помилка", "Не вдалось додати книгу!");
    }
}
