#include "worker.h"
#include <QVector>
#include <QDebug>
#include <unistd.h>

Worker::Worker(QVector<int>::iterator begin, QVector<int>::iterator end, QVector<int> &vector)
{
    this->begin = begin;
    this->end = end;
    this->vector = &vector;
    partial_sum = 0;
    id = QString::number(qrand());
}

void Worker::run()
{
    qDebug() << "Greets from worker number:" << this->currentThreadId();
    qDebug() << "begin" << *begin << "end" << *(end-1);
    QVector<int>::iterator i;
    for(i=begin; i != end; i++){
        this->partial_sum += *i;
        //qDebug()<< "Iterator content"<<  *i;
        //qDebug()<<std::distance(begin, i);
        if(std::distance(begin, i)%(std::distance(begin, end)/1000 +1) == 0){
            //qDebug() << (100*(double(std::distance(begin, i))/std::distance(begin, end)));

            emit progressed(id, 100*(double(std::distance(begin, i))/std::distance(begin, end)));
            usleep(1000);
        }

    }
    ready = true;
    emit progressed(id, 100);
    emit fin(id, partial_sum);
}

long Worker::getSum()
{
    return partial_sum;
}

QString Worker::getId()
{
    return this->id;
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

