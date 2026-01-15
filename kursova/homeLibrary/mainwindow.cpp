#include "mainwindow.h"
#include "dialogs/newbookdialog.h"
#include "dialogs/newsectiondialog.h"
#include "dialogs/newaccountdialog.h"
#include "dialogs/logindialog.h"
#include "qapplication.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mCurrentUserName("guest")
{
    if (!Database::instance().connect()) {
        QMessageBox::critical(this, "Критична помилка",
                            "Не вдалось підключитись до бази даних!");
        QApplication::quit();
        return;
    }
    else Database::instance().createUser("admin", "123");

    LoginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted) {
        mCurrentUserName = loginDialog.username();

        setupUI();
        loadSections();
        loadBooks();

        statusBar()->showMessage(QString("Вітаємо, %1!").arg(mCurrentUserName));
    } else {
        QApplication::quit();
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    setWindowTitle("Картотека домашньої бібліотеки");
    resize(1200, 700);

    QMenu *fileMenu = menuBar()->addMenu("&Файл");

    QAction *newBookAction = new QAction("&Нова книга", this);
    newBookAction->setShortcut(QKeySequence::New);
    connect(newBookAction, &QAction::triggered, this, &MainWindow::onNewBook);
    fileMenu->addAction(newBookAction);

    QAction *newSectionAction = new QAction("Нова &секція", this);
    connect(newSectionAction, &QAction::triggered, this, &MainWindow::onNewSection);
    fileMenu->addAction(newSectionAction);

    fileMenu->addSeparator();

    QAction *exitAction = new QAction("&Вихід", this);
    exitAction->setShortcut(QKeySequence::Quit);
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
    fileMenu->addAction(exitAction);


    // Створення вкладок
    mTabWidget = new QTabWidget(this);
    mTabWidget->setTabPosition(QTabWidget::North);
    setCentralWidget(mTabWidget);

    // Вкладка "Каталог"
    QWidget *catalogWidget = new QWidget();
    QVBoxLayout *catalogLayout = new QVBoxLayout(catalogWidget);
    catalogLayout->setContentsMargins(10, 10, 10, 10);

    // Фільтр по секціях
    QHBoxLayout *filterLayout = new QHBoxLayout();
    QLabel *filterLabel = new QLabel("Секція:");
    filterLabel->setStyleSheet("font-weight: bold;");
    filterLayout->addWidget(filterLabel);

    mSectionFilter = new QComboBox();
    mSectionFilter->setMinimumWidth(200);
    connect(mSectionFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onSectionChanged);
    filterLayout->addWidget(mSectionFilter);
    filterLayout->addStretch();

    mSearchBar = new QLineEdit();
    mSearchBar->setPlaceholderText("Пошук книг...");
    mSearchBar->setMaximumWidth(300);
    connect(mSearchBar, &QLineEdit::textChanged, this, &MainWindow::onSearch);
    filterLayout->addWidget(mSearchBar);

    catalogLayout->addLayout(filterLayout);

    mBooksTable = new QTableView();
    mBooksModel = new QSqlTableModel(this, Database::instance().getDatabase());
    mBooksModel->setTable("books");
    mBooksModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Встановлення заголовків
    mBooksModel->setHeaderData(1, Qt::Horizontal, "Носій");
    mBooksModel->setHeaderData(2, Qt::Horizontal, "Назва");
    mBooksModel->setHeaderData(3, Qt::Horizontal, "Автор");
    mBooksModel->setHeaderData(4, Qt::Horizontal, "Жанр");
    mBooksModel->setHeaderData(5, Qt::Horizontal, "Рейтинг");
    mBooksModel->setHeaderData(6, Qt::Horizontal, "Опис");
    mBooksModel->setHeaderData(7, Qt::Horizontal, "Прочитано");
    mBooksModel->setHeaderData(8, Qt::Horizontal, "Права перегляду");
    mBooksModel->select();

    mBooksTable->setModel(mBooksModel);
    mBooksTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    mBooksTable->setSelectionMode(QAbstractItemView::SingleSelection);
    mBooksTable->setAlternatingRowColors(true);
    mBooksTable->horizontalHeader()->setStretchLastSection(true);
    mBooksTable->verticalHeader()->hide();
    mBooksTable->hideColumn(0); // Приховати ID
    mBooksTable->hideColumn(9); // Приховати обкладинку
    mBooksTable->hideColumn(10);
    catalogLayout->addWidget(mBooksTable);

    mDeleteBook = new QPushButton("Видалити книгу");
    connect(mDeleteBook, &QPushButton::clicked, this, &MainWindow::onDeleteBook);
    catalogLayout->addWidget(mDeleteBook);


    mTabWidget->addTab(catalogWidget, "📚 Каталог");

    // Вкладка "Секції"
    QWidget *sectionsWidget = new QWidget();
    QVBoxLayout *sectionsLayout = new QVBoxLayout(sectionsWidget);
    sectionsLayout->setContentsMargins(10, 10, 10, 10);

    mSectionsTable = new QTableView();
    mSectionsModel = new QSqlTableModel(this, Database::instance().getDatabase());
    mSectionsModel->setTable("sections");
    mSectionsModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    mSectionsModel->setHeaderData(1, Qt::Horizontal, "Назва");
    mSectionsModel->setHeaderData(2, Qt::Horizontal, "Абревіатура");
    mSectionsModel->setHeaderData(3, Qt::Horizontal, "Опис");
    mSectionsModel->setHeaderData(4, Qt::Horizontal, "Шлях");
    mSectionsModel->setHeaderData(5, Qt::Horizontal, "Кількість книг");
    mSectionsModel->setHeaderData(6, Qt::Horizontal, "Групи які мають доступ");
    mSectionsModel->select();

    mSectionsTable->setModel(mSectionsModel);
    mSectionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    mSectionsTable->setAlternatingRowColors(true);
    mSectionsTable->horizontalHeader()->setStretchLastSection(true);
    mSectionsTable->verticalHeader()->hide();
    mSectionsTable->hideColumn(0); // Приховати ID

    sectionsLayout->addWidget(mSectionsTable);

    mDeleteSection = new QPushButton("Видалити секцію");
    connect(mDeleteSection, &QPushButton::clicked, this, &MainWindow::onDeleteSection);
    sectionsLayout->addWidget(mDeleteSection);

    mTabWidget->addTab(sectionsWidget, "📂 Секції");


    QWidget *usersWidget = new QWidget();
    QVBoxLayout *usersLayout = new QVBoxLayout(usersWidget);
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    usersLayout->setContentsMargins(10, 10, 10, 10);

    mUsersTable = new QTableView();
    mUsersModel = new QSqlTableModel(this, Database::instance().getDatabase());
    mUsersModel->setTable("users");
    mUsersModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    mUsersModel->setHeaderData(1, Qt::Horizontal, "Користувач");
    mUsersModel->setHeaderData(4, Qt::Horizontal, "Дата створення");
    mUsersModel->setHeaderData(5, Qt::Horizontal, "Останній вхід");
    mUsersModel->select();

    mUsersTable->setModel(mUsersModel);
    mUsersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    mUsersTable->setAlternatingRowColors(true);
    mUsersTable->horizontalHeader()->setStretchLastSection(true);
    mUsersTable->verticalHeader()->hide();
    mUsersTable->hideColumn(0); // ID
    mUsersTable->hideColumn(2); // password_hash
    mUsersTable->hideColumn(3); // salt

    usersLayout->addWidget(mUsersTable);

    mDeleteUser = new QPushButton("Видалити користувача");
    mCreateUser = new QPushButton("Додати користувача");
    connect(mDeleteUser, &QPushButton::clicked, this, &MainWindow::onDeleteUser);
    connect(mCreateUser, &QPushButton::clicked, this, &MainWindow::onNewAccount);

    buttonsLayout->addWidget(mDeleteUser);
    buttonsLayout->addWidget(mCreateUser);
    usersLayout->addLayout(buttonsLayout);

    mTabWidget->addTab(usersWidget, "👤 Користувачі");

    QWidget *helpWidget = new QWidget();
    QVBoxLayout *helpLayout = new QVBoxLayout(helpWidget);
    helpLayout->setContentsMargins(10, 10, 10, 10);

    mHelp = new QTextBrowser();
    QUrl help("/home/cheshyrka/OOP/kursova/homeLibrary/help.html");
    mHelp->setSource(help);

    helpLayout->addWidget(mHelp);
    mTabWidget->addTab(helpWidget, "❓Допоміжна інформація");

    if(mCurrentUserName != "admin"){
            mTabWidget->tabBar()->setTabVisible(2, false);
    }
    statusBar()->show();
}

void MainWindow::loadSections()
{
    mSectionFilter->clear();
    mSectionFilter->addItem("📚 Всі секції", -1);

    QSqlQuery query("SELECT section_id, name, book_count FROM sections ORDER BY name");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int bookCount = query.value(2).toInt();

        mSectionFilter->addItem(
            QString("%1 (%2)").arg(name).arg(bookCount), id);
    }
}

void MainWindow::loadBooks(int sectionId)
{
    if (sectionId == -1) {
        mBooksModel->setFilter("");
    } else {
        mBooksModel->setFilter(QString("section_id = %1").arg(sectionId));
    }
    mBooksModel->select();

    statusBar()->showMessage(
        QString("Показано книг: %1").arg(mBooksModel->rowCount()), 3000);
}


void MainWindow::onNewBook()
{
    NewBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        mBooksModel->select();
        mSectionsModel->select();
        loadSections();
        statusBar()->showMessage("Книгу успішно додано!", 3000);
    }
}

void MainWindow::onNewSection()
{
    NewSectionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        mSectionsModel->select();
        loadSections();
        statusBar()->showMessage("Секцію успішно додано!", 3000);
    }

}

void MainWindow::onNewAccount()
{
    NewAccountDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        mUsersModel->select();
        statusBar()->showMessage("Акаунт успішно створено!", 3000);
    }
}

void MainWindow::onSectionChanged(int index)
{
    int sectionId = mSectionFilter->itemData(index).toInt();
    loadBooks(sectionId);
}

void MainWindow::onSearch(const QString &text)
{
    if (text.isEmpty()) {
           // Show all books in current section
           if (mSectionFilter->currentIndex() > 0) {
               int sectionId = mSectionFilter->currentData().toInt();
               mBooksModel->setFilter(QString("section_id = %1").arg(sectionId));
           } else {
               mBooksModel->setFilter("");
           }
       } else {
           QString filter = QString("(title LIKE '%%1%' OR author LIKE '%%1%' OR rating LIKE '%%1%' OR genre LIKE '%%1%')").arg(text);

           // Combine with section filter if selected
           if (mSectionFilter->currentIndex() > 0) {
               int sectionId = mSectionFilter->currentData().toInt();
               filter = QString("section_id = %1 AND %2").arg(sectionId).arg(filter);
           }

           mBooksModel->setFilter(filter);
       }
       mBooksModel->select();
}


void MainWindow::onDeleteBook()
{
    QModelIndex index = mBooksTable->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Помилка", "Оберіть книгу для видалення");
        return;
    }

    int row = index.row();
    int bookId = mBooksModel->record(row).value("book_id").toInt();
    QString title = mBooksModel->record(row).value("title").toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Підтвердження",
        QString("Ви впевнені, що хочете видалити книгу '%1'?").arg(title),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::instance().deleteBook(bookId)) {
            QMessageBox::information(this, "Успіх", "Книгу видалено!");
            mBooksModel->select();
        } else {
            QMessageBox::critical(this, "Помилка", "Не вдалось видалити книгу");
        }
    }
    loadBooks();
}

void MainWindow::onDeleteSection()
{
    QModelIndex index = mSectionsTable->currentIndex();
    if(!index.isValid()){
        QMessageBox::warning(this, "Помилка", "Оберіть секцію для видалення");
        return;
    }

    int row = index.row();
    int sectionId = mSectionsModel->record(row).value("section_id").toInt();
    QString name = mSectionsModel->record(row).value("name").toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Підтвердження",
        QString("Ви впевнені, що хочете видалити секцію '%1'?").arg(name),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::instance().deleteSection(sectionId)) {
            QMessageBox::information(this, "Успіх", "Секцію видалено!");
            mBooksModel->select();
        } else {
            QMessageBox::critical(this, "Помилка", "Не вдалось видалити книгу");
        }
    }
    void loadSections();
}

void MainWindow::onDeleteUser()
{
    QModelIndex index = mUsersTable->currentIndex();
    if(!index.isValid()){
        QMessageBox::warning(this, "Помилка", "Оберіть користувача для видалення");
        return;
    }

    int row = index.row();
    int userId = mUsersModel->record(row).value("user_id").toInt();
    QString userName = mUsersModel->record(row).value("username").toString();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Підтвердження",
        QString("Ви впевнені, що хочете видалити користувача '%1'?").arg(userName),
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Database::instance().deleteUser(userId)) {
            QMessageBox::information(this, "Успіх", "Користувача видалено!");
            mUsersModel->select();
        } else {
            QMessageBox::critical(this, "Помилка", "Не вдалось видалити Користувача");
        }
    }
}
