#include "worker.h"
#include <QDebug>

Worker::Worker()
{

}

void Worker::run()
{
    qDebug() << "Greets from worker";
}

int Worker::process()
{


     qDebug() << "Worker is hard working now";
     int i;
     static int prev = 1;
     for(i = 0; i < 1000000; i++)
     {
        //qDebug() << "index " << i;
         if(prev != int((double)i/(10000-10)) )
         {
             prev = int((double)i/(10000-10));
             emit progressed(prev);
         }
     }
     return i;
}
