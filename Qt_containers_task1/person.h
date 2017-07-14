#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:

    std::string name, surname;
    int age;

    explicit Person(std::string nm = "not defined", std::string snm = "not defined", int ag = 0 , QObject *parent = nullptr);

signals:

public slots:
};

#endif // PERSON_H
