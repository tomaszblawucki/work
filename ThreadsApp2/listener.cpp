#include "listener.h"
#include <QDebug>

bool Listener::resultReady()
{
    QMap<QString, bool>::iterator i;
    for (i = threadsFinished.begin(); i != threadsFinished.end(); ++i)
    {
        if(i.value() != true)
            return false;
    }
    return true;
}
Listener::Listener(int tc, QObject *parent) : QObject(parent)
{
    this->threadCount = tc;
    result = 0;
}

void Listener::addThread(QString id)
{
    this->threadsProgress.insert(id, 0);
    this->threadsFinished.insert(id, false);
}

void Listener::listen(QString id, double prog)
{
    this->threadsProgress[id] = prog;

    //qDebug()<<"Process: "<< id <<" Current progress: " << threadsProgress[id];
    double sum = 0;
    QMap<QString, double>::iterator i;
    for (i = threadsProgress.begin(); i != threadsProgress.end(); ++i)
        sum+=i.value();

    qDebug() << "average progress:" <<sum/threadCount;

}

void Listener::calculationFinish(QString id , double partial)
{
     this->threadsFinished[id] = true;
     result += partial;
     qDebug() <<"Aquired partial = " << partial;
     qDebug() <<"IS FINISHED?" << this->resultReady();
     if(this->resultReady())
     {
         qDebug()<<"Final result: "<<QString::number(result);
     }
}
