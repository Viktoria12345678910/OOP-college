#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "student.h"
#include <QSqlDatabase>

class DBManager {
public:
    virtual void connectToDataBase() = 0;
    virtual QSqlDatabase& getDB() = 0;
    virtual bool insertIntoTable(const Student& student) = 0;

};

#endif // DBMANAGER_H
