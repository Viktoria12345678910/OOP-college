#include "mainwindow.h"
#include "dialogs/newbookdialog.h"
#include "dialogs/newsectiondialog.h"
#include "dialogs/newaccountdialog.h"
#include "dialogs/logindialog.h"
#include "dialogs/groupmanagerdialog.h"
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
    , m_currentUserId(-1)
{
    // Ініціалізація бази даних
    if (!Database::instance().connect()) {
        QMessageBox::critical(this, "Критична помилка",
                            "Не вдалось підключитись до бази даних!");
        QApplication::quit();
        return;
    }

    // Показати діалог логіну
    LoginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted) {
        m_currentUserId = loginDialog.userId();
        QString username = loginDialog.username();

        setupUI();
        loadSections();
        loadBooks();

        statusBar()->showMessage(QString("Вітаємо, %1!").arg(username));
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

    // Створення меню
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

    // Меню управління
    QMenu *manageMenu = menuBar()->addMenu("&Управління");

    QAction *manageUsersAction = new QAction("&Користувачі", this);
    connect(manageUsersAction, &QAction::triggered, this, &MainWindow::onNewAccount);
    manageMenu->addAction(manageUsersAction);

    QAction *manageGroupsAction = new QAction("&Групи", this);
    connect(manageGroupsAction, &QAction::triggered, this, &MainWindow::onManageGroups);
    manageMenu->addAction(manageGroupsAction);

    // Створення вкладок
    m_tabWidget = new QTabWidget(this);
    m_tabWidget->setTabPosition(QTabWidget::North);
    setCentralWidget(m_tabWidget);

    // Вкладка "Каталог"
    QWidget *catalogWidget = new QWidget();
    QVBoxLayout *catalogLayout = new QVBoxLayout(catalogWidget);
    catalogLayout->setContentsMargins(10, 10, 10, 10);

    // Фільтр по секціях
    QHBoxLayout *filterLayout = new QHBoxLayout();
    QLabel *filterLabel = new QLabel("Секція:");
    filterLabel->setStyleSheet("font-weight: bold;");
    filterLayout->addWidget(filterLabel);

    m_sectionFilter = new QComboBox();
    m_sectionFilter->setMinimumWidth(200);
    connect(m_sectionFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onSectionChanged);
    filterLayout->addWidget(m_sectionFilter);
    filterLayout->addStretch();
    catalogLayout->addLayout(filterLayout);

    m_booksTable = new QTableView();
    m_booksModel = new QSqlTableModel(this, Database::instance().getDatabase());
    m_booksModel->setTable("books");
    m_booksModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Встановлення заголовків
    m_booksModel->setHeaderData(1, Qt::Horizontal, "Носій");
    m_booksModel->setHeaderData(2, Qt::Horizontal, "Назва");
    m_booksModel->setHeaderData(3, Qt::Horizontal, "Автор");
    m_booksModel->setHeaderData(4, Qt::Horizontal, "Жанр");
    m_booksModel->setHeaderData(5, Qt::Horizontal, "Рейтинг");
    m_booksModel->setHeaderData(6, Qt::Horizontal, "Опис");
    m_booksModel->setHeaderData(7, Qt::Horizontal, "Прочитано");
    m_booksModel->select();

    m_booksTable->setModel(m_booksModel);
    m_booksTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_booksTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_booksTable->setAlternatingRowColors(true);
    m_booksTable->horizontalHeader()->setStretchLastSection(true);
    m_booksTable->verticalHeader()->hide();
    m_booksTable->hideColumn(0); // Приховати ID
    m_booksTable->hideColumn(9); // Приховати обкладинку

    catalogLayout->addWidget(m_booksTable);
    m_tabWidget->addTab(catalogWidget, "📚 Каталог");

    // Вкладка "Секції"
    QWidget *sectionsWidget = new QWidget();
    QVBoxLayout *sectionsLayout = new QVBoxLayout(sectionsWidget);
    sectionsLayout->setContentsMargins(10, 10, 10, 10);

    m_sectionsTable = new QTableView();
    m_sectionsModel = new QSqlTableModel(this, Database::instance().getDatabase());
    m_sectionsModel->setTable("sections");
    m_sectionsModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    m_sectionsModel->setHeaderData(1, Qt::Horizontal, "Назва");
    m_sectionsModel->setHeaderData(2, Qt::Horizontal, "Абревіатура");
    m_sectionsModel->setHeaderData(3, Qt::Horizontal, "Опис");
    m_sectionsModel->setHeaderData(4, Qt::Horizontal, "Шлях");
    m_sectionsModel->setHeaderData(5, Qt::Horizontal, "Кількість книг");
    m_sectionsModel->select();

    m_sectionsTable->setModel(m_sectionsModel);
    m_sectionsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_sectionsTable->setAlternatingRowColors(true);
    m_sectionsTable->horizontalHeader()->setStretchLastSection(true);
    m_sectionsTable->verticalHeader()->hide();
    m_sectionsTable->hideColumn(0); // Приховати ID

    sectionsLayout->addWidget(m_sectionsTable);
    m_tabWidget->addTab(sectionsWidget, "📂 Секції");

    // Вкладка "Користувачі"
    QWidget *usersWidget = new QWidget();
    QVBoxLayout *usersLayout = new QVBoxLayout(usersWidget);
    usersLayout->setContentsMargins(10, 10, 10, 10);

    m_usersTable = new QTableView();
    m_usersModel = new QSqlTableModel(this, Database::instance().getDatabase());
    m_usersModel->setTable("users");
    m_usersModel->setEditStrategy(QSqlTableModel::OnFieldChange);

    m_usersModel->setHeaderData(1, Qt::Horizontal, "Користувач");
    m_usersModel->setHeaderData(4, Qt::Horizontal, "Дата створення");
    m_usersModel->setHeaderData(5, Qt::Horizontal, "Останній вхід");
    m_usersModel->select();

    m_usersTable->setModel(m_usersModel);
    m_usersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_usersTable->setAlternatingRowColors(true);
    m_usersTable->horizontalHeader()->setStretchLastSection(true);
    m_usersTable->verticalHeader()->hide();
    m_usersTable->hideColumn(0); // ID
    m_usersTable->hideColumn(2); // password_hash
    m_usersTable->hideColumn(3); // salt

    usersLayout->addWidget(m_usersTable);
    m_tabWidget->addTab(usersWidget, "👤 Користувачі");

    // Статус бар
    statusBar()->show();
}

void MainWindow::loadSections()
{
    m_sectionFilter->clear();
    m_sectionFilter->addItem("📚 Всі секції", -1);

    QSqlQuery query("SELECT section_id, name, book_count FROM sections ORDER BY name");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        int bookCount = query.value(2).toInt();

        m_sectionFilter->addItem(
            QString("%1 (%2)").arg(name).arg(bookCount), id);
    }
}

void MainWindow::loadBooks(int sectionId)
{
    if (sectionId == -1) {
        m_booksModel->setFilter("");
    } else {
        m_booksModel->setFilter(QString("section_id = %1").arg(sectionId));
    }
    m_booksModel->select();

    statusBar()->showMessage(
        QString("Показано книг: %1").arg(m_booksModel->rowCount()), 3000);
}

void MainWindow::onNewBook()
{
    NewBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_booksModel->select();
        m_sectionsModel->select();
        loadSections();
        statusBar()->showMessage("Книгу успішно додано!", 3000);
    }
}

void MainWindow::onNewSection()
{
    NewSectionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_sectionsModel->select();
        loadSections();
        statusBar()->showMessage("Секцію успішно додано!", 3000);
    }
}

void MainWindow::onNewAccount()
{
    NewAccountDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_usersModel->select();
        statusBar()->showMessage("Акаунт успішно створено!", 3000);
    }
}

void MainWindow::onManageGroups()
{
    GroupManagerDialog dialog(this);
    dialog.exec();
}

void MainWindow::onSectionChanged(int index)
{
    int sectionId = m_sectionFilter->itemData(index).toInt();
    loadBooks(sectionId);
}
