#include "worker.h"
#include <QVector>
#include <QDebug>

Worker::Worker(QVector<int>::iterator begin, QVector<int>::iterator end, QVector<int> &vector)
{
    this->begin = begin;
    this->end = end;
    this->vector = &vector;
}

void Worker::run()
{
    qDebug() << "Greets from worker number:" << this->currentThreadId();
    qDebug() << "begin" << *begin << "end" << *(end-1);
    QVector<int>::iterator i;
    for(i=begin; i != end; ++i)
        this->partial_sum += *i;

    ready= true;

}

long Worker::getSum()
{
    return partial_sum;
}

//int Worker::process()
//{


//     qDebug() << "Worker is hard working now";
//     int i;
//     static int prev = 1;
//     for(i = 0; i < 1000000; i++)
//     {
//        //qDebug() << "index " << i;
//         if(prev != int((double)i/(10000-10)) )
//         {
//             prev = int((double)i/(10000-10));
//             emit progressed(prev);
//         }
//     }
//     return i;
//}

