#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "worker.h"
#include <QThread>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QFutureIterator>
#include <unistd.h>
#include "listener.h"
#include <QVector>


const int THREAD_COUNT = 2;
const int VECTOR_SIZE = 4;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


//QThread methodology
//    QThread *thread =new QThread;
//    Worker *worker = new Worker;
//    worker->moveToThread(thread);
//    QObject::connect(thread, SIGNAL(started()), worker, SLOT(process()));
//    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//    QObject::connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
//    QObject::connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
//
    //thread->start();
    //thread->quit();

    QVector<int> resource;
    for(int i=0; i<VECTOR_SIZE; i++)
    {
        resource.append(i);
    }


    //Worker work( resource.begin()+(0*(THREAD_COUNT/VECTOR_SIZE)),resource.begin()+((0+1)*(THREAD_COUNT/VECTOR_SIZE)),resource);

    QList<Worker*> threadList;

    for(int i = 0; i<THREAD_COUNT; i++)
    {
        if(i+1 != THREAD_COUNT)
        {
            auto b = resource.begin();
            auto e = resource.begin();
           // qDebug()<<"B ADDRESS:"<<b<<"E ADDRESS: "<<e;
            std::advance(b,i*(VECTOR_SIZE/THREAD_COUNT));
            std::advance(e,(i+1)*(VECTOR_SIZE/THREAD_COUNT));
            qDebug()<<"B ADDRESS:"<<b<<"E ADDRESS: "<<e<<"T/V"<<VECTOR_SIZE/THREAD_COUNT ;
            threadList.append(new Worker( b, e, resource));
        }
        else
        {
            auto b = resource.begin();
            auto e = resource.end();
           // qDebug()<<"B ADDRESS:"<<b<<"E ADDRESS: "<<e;
            std::advance(b,i*(VECTOR_SIZE/THREAD_COUNT));
            qDebug()<<"B ADDRESS:"<<b<<"E ADDRESS: "<<e<<"T/V"<<VECTOR_SIZE/THREAD_COUNT ;
            threadList.append(new Worker( b, e, resource));
        }


    }


    foreach (Worker *w, threadList) {
       w->start();
    }


    foreach (Worker *w, threadList) {
        while(!w->ready)
        {

        }
       qDebug() << "PARTIAL SUM: " << w->getSum();
    }




//    Worker *worker = new Worker;
//    Listener *listener = new Listener;
//    QFutureWatcher<int> watcher;

//    QObject::connect(&watcher, SIGNAL(finished()), worker, SLOT(deleteLater()));
//    QObject::connect(&watcher, SIGNAL(finished()), worker, SLOT(deleteLater()));
//    //QObject::connect(&watcher, SIGNAL(progressValueChanged(int)), listener, SLOT(listen(int)) );
//    QObject::connect(worker, SIGNAL(progressed(int)), listener, SLOT(listen(int)) );

//    //QFuture<int> handle = QtConcurrent::run(worker, &Worker::process);
//    QFuture<int> handle = QtConcurrent::filteredReduced(&resource, &Worker::filter, reduce);
//    watcher.setFuture(handle);

    return app.exec();
}
