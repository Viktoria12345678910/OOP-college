#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QCryptographicHash>
#include <QDateTime>

class Database
{
public:
    static Database& instance();
    bool connect(const QString &path = "library.db");
    void disconnect();

    bool createTables();

    // User methods
    bool createUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    int getUserId(const QString &username);
    QList<QString> getUserGroups(int userId);

    // Section methods
    int createSection(const QString &name, const QString &abbreviation,
                      const QString &description);
    bool updateSectionBookCount(int sectionId);

    // Book methods
    int createBook(const QString &medium, const QString &title,
                   const QString &author, const QString &genre,
                   int rating, const QString &description,
                   bool read, const QString &viewRights,
                   const QByteArray &cover, int sectionId);

    // Group methods
    int createGroup(const QString &groupName);
    bool addUserToGroup(int userId, int groupId);
    bool deleteBook(int bookId);
    bool deleteSection(int bookId);
    bool deleteUser(int bookId);

    QSqlDatabase getDatabase() { return mDb; }

private:
    Database();
    ~Database();
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    QString hashPassword(const QString &password, const QString &salt);
    QString generateSalt();

    QSqlDatabase mDb;
};

#endif // DATABASE_H
