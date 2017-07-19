#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QXmlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("/Users/int_tobl/Desktop/QtProjects/xmlQuery/task.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"file opened";
        QXmlQuery query;

        query.bindVariable("kmlFile", &file);
        qDebug()<<"file bound";
        query.setQuery("doc('/Users/int_tobl/Desktop/QtProjects/xmlQuery/task.xml')/rates/rate[from = 'AUD']");
        //doc("cookbook.xml")/rates/rate[1]
        QString result;
        qDebug()<<"before eval";
        query.evaluateTo(&result);

        qDebug()<<result;
        file.close();

    }
    else
    {
        qDebug() << "file not found";
    }


    return a.exec();
}
