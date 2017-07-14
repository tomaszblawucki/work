#include <QCoreApplication>
#include <QList>
#include <QMap>
#include "person.h"
#include <string>
#include <QDebug>
#include <QMutableListIterator>
#include <QMutableMapIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QList<Person> qPersonList;
    QMap<int, Person> qPersonMap;
    for(int i = 1; i < 21; i++)
    {
        std::string name = ("Tom");
        name += char('a' + i);
        Person p1(name, "Anon", i + 10);
        //Person p(("John" + std::to_string(i)), ("Smith" + std::string(i)), (i+10)) ;
        qPersonList.append(p1);
        qPersonMap.insert(i , p1);
    }

    qDebug("\n\tQLIST\n");
    for(Person item : qPersonList)
    {
        qDebug() << "NAME: " << item.name.c_str() << " AGE: " << item.age;
    }

    qDebug("\n\tQMAP\n");
    QMap<int, Person>::iterator mapIterator;
    for(mapIterator = qPersonMap.begin(); mapIterator != qPersonMap.end(); ++mapIterator)
    {
        qDebug() << "KEY: " << mapIterator.key() << "NAME: " <<mapIterator.value().name.c_str() << "SURNAME: " <<mapIterator.value().surname.c_str();
    }

    QMutableListIterator<Person> qListIterator(qPersonList);
    int even = 0;
    do{
        qListIterator.next();
        even++;
        if(even%2)
            qListIterator.remove();

    }while(qListIterator.hasNext());
    qDebug("\n\tQLIST AFTER REMOVE\n");
    for(Person item : qPersonList)
    {
        qDebug() << "NAME: " << item.name.c_str() << " AGE: " << item.age;
    }


    QMutableMapIterator<int, Person> qMapIterator(qPersonMap);
    do{
        qMapIterator.next();
        if(qMapIterator.key()%2 != 0)
            qMapIterator.remove();
    }while(qMapIterator.hasNext());


    qDebug("\n\tQMAP AFTER REMOVE\n");
    for(mapIterator = qPersonMap.begin(); mapIterator != qPersonMap.end(); ++mapIterator)
    {
        qDebug() << "KEY: " << mapIterator.key() << "NAME: " <<mapIterator.value().name.c_str() << "SURNAME: " <<mapIterator.value().surname.c_str();
    }



    return a.exec();
}
