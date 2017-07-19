#include "sumlistener.h"
#include <QDebug>

SumListener::SumListener(QObject *parent) : QObject(parent)
{
    progress = 0.6;
}

void SumListener::listen(int prog, int sum, int n)
{
    //qDebug()<<"GOT: " << prog;
    this->progress = ((double)prog/(n-1));
    //qDebug()<<"Progress in %: " << this->progress;
    emit progressChanged();
    if(progress >=1)
    {
        name = QString("RESULT: ")+QString::number(sum);
        qDebug() << "SUM: " <<sum;
        emit nameChanged();
    }
}



