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
    mMediumCombo = new QComboBox();
    mMediumCombo->addItems({"Паперова", "Електронна", "Аудіокнига"});
    formLayout->addRow("Тип носія:", mMediumCombo);

    // Назва
    mTitleEdit = new QLineEdit();
    formLayout->addRow("Назва*:", mTitleEdit);

    // Автор
    mAuthorEdit = new QLineEdit();
    formLayout->addRow("Автор:", mAuthorEdit);

    // Жанр
    mGenreEdit = new QLineEdit();
    formLayout->addRow("Жанр:", mGenreEdit);

    // Рейтинг
    mRatingSpin = new QSpinBox();
    mRatingSpin->setRange(1, 5);
    mRatingSpin->setValue(3);
    formLayout->addRow("Рейтинг:", mRatingSpin);

    // Опис
    mDescriptionEdit = new QTextEdit();
    mDescriptionEdit->setMaximumHeight(100);
    formLayout->addRow("Опис:", mDescriptionEdit);

    // Прочитано
    mReadCheck = new QCheckBox("Прочитано");
    formLayout->addRow("", mReadCheck);

    // Права перегляду
    mViewRightsCombo = new QComboBox();
    mViewRightsCombo->addItems({"Всі", "Тільки я", "Вибрати групу"});
    formLayout->addRow("Права перегляду:", mViewRightsCombo);

    // Секція
    mSectionCombo = new QComboBox();
    formLayout->addRow("Секція*:", mSectionCombo);

    // Обкладинка
    QHBoxLayout *coverLayout = new QHBoxLayout();
    mCoverButton = new QPushButton("Вибрати обкладинку");
    connect(mCoverButton, &QPushButton::clicked, this, &NewBookDialog::onSelectCover);
    coverLayout->addWidget(mCoverButton);

    mCoverPreview = new QLabel();
    mCoverPreview->setFixedSize(100, 150);
    mCoverPreview->setFrameStyle(QFrame::Box);
    mCoverPreview->setScaledContents(true);
    coverLayout->addWidget(mCoverPreview);
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
        mSectionCombo->addItem(name, id);
    }
}

void NewBookDialog::onSelectCover()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, "Вибрати обкладинку", "", "Зображення (*.png *.jpg *.jpeg)");

    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            mCoverPreview->setPixmap(pixmap);

            QBuffer buffer(&mCoverData);
            buffer.open(QIODevice::WriteOnly);
            pixmap.save(&buffer, "PNG");
        }
    }
}

void NewBookDialog::onSave()
{
    if (mTitleEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Назва книги обов'язкова!");
        return;
    }

    if (mSectionCombo->currentIndex() == -1) {
        QMessageBox::warning(this, "Помилка", "Оберіть секцію!");
        return;
    }

    QString medium = mMediumCombo->currentText();
    QString title = mTitleEdit->text();
    QString author = mAuthorEdit->text();
    QString genre = mGenreEdit->text();
    int rating = mRatingSpin->value();
    QString description = mDescriptionEdit->toPlainText();
    bool read = mReadCheck->isChecked();
    QString viewRights = mViewRightsCombo->currentText();
    int sectionId = mSectionCombo->currentData().toInt();

    int bookId = Database::instance().createBook(
        medium, title, author, genre, rating, description,
        read, viewRights, mCoverData, sectionId);

    if (bookId > 0) {
        QMessageBox::information(this, "Успіх", "Книгу успішно додано!");
        accept();
    } else {
        QMessageBox::critical(this, "Помилка", "Не вдалось додати книгу!");
    }
}
