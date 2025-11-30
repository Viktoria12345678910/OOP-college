#ifndef STUDENTREPOSITORY_H
#define STUDENTREPOSITORY_H

#include "student.h"
#include <QList>
#include <QMessageBox>

class IStudentRepository
{
public:
    virtual ~IStudentRepository() {}
    virtual bool addStudent(const Student& student) = 0;
    virtual QList<Student> getAllStudents() = 0;
    virtual bool deleteStudent(int id) = 0;
    virtual bool updateStudent(const Student& student) = 0;
};

class StudentRepository : public IStudentRepository
{
public:
    StudentRepository();

    bool addStudent(const Student& student) override;
    QList<Student> getAllStudents() override;
    bool deleteStudent(int id) override;
    bool updateStudent(const Student& student) override;
};

#endif // STUDENTREPOSITORY_H
