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





    Worker *worker = new Worker;
    Listener *listener = new Listener;
    QFutureWatcher<int> watcher;

    QObject::connect(&watcher, SIGNAL(finished()), worker, SLOT(deleteLater()));
    QObject::connect(&watcher, SIGNAL(finished()), worker, SLOT(deleteLater()));
    //QObject::connect(&watcher, SIGNAL(progressValueChanged(int)), listener, SLOT(listen(int)) );
    QObject::connect(worker, SIGNAL(progressed(int)), listener, SLOT(listen(int)) );

    QFuture<int> handle = QtConcurrent::run(worker, &Worker::process);

    watcher.setFuture(handle);

    return app.exec();
}
