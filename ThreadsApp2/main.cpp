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
#include <QQmlContext>

const int THREAD_COUNT = 1;
const int VECTOR_SIZE = 1000;

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

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
        resource.append(i*24);
    }


    //Worker work( resource.begin()+(0*(THREAD_COUNT/VECTOR_SIZE)),resource.begin()+((0+1)*(THREAD_COUNT/VECTOR_SIZE)),resource);

    QList<Worker*> threadList;

    Listener *listener = new Listener(THREAD_COUNT);



    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myProgress", listener);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


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
       QObject::connect(w, SIGNAL(progressed(QString, double)), listener, SLOT(listen(QString, double)));
       QObject::connect(w, SIGNAL(fin(QString, double)), listener, SLOT(calculationFinish(QString,double)));

       listener->addThread(w->getId());
       w->start();
    }

    return app.exec();
}
