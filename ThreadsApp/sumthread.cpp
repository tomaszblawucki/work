#include "sumthread.h"
#include <unistd.h>
#include <QDebug>

SumThread::SumThread(int *arr, int size, QObject *parent) : QObject(parent)
{
    this->tabSize = size;
    this->arrayPtr = arr;
    this->sum=0;
}

void SumThread::run()
{
    for(int i =0; i<tabSize; i++)\
    {
        this->sum += arrayPtr[i];
        emit notify(i, sum, tabSize);
        //qDebug() << "sending data";
        usleep(1000);
    }
}
