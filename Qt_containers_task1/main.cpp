#include "mainwindow.h"
#include <QApplication>
#include <QList>
#include <QMap>
#include "person.h"
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QList<Person> qPersonList;
    QMap<int, Person> qPersonMap;



    for(int i = 1; i < 21; i++)
    {
        Person p1("Tom", "Anon", i + 10);
        //Person p(("John" + std::to_string(i)), ("Smith" + std::string(i)), (i+10)) ;
        qPersonList.append(p1);
       // qPersonMap.insert(i , new Person(("John" + std::to_string(i)), ("Smith" + std::string(i)), (i+10) ));
    }



    return a.exec();
}
