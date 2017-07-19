#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "sumthread.h"
#include "sumlistener.h"
#include <QQmlContext>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    int n = 5000;

    int tab[n];
    for(int i =0; i<n; i++)tab[i] = i*6;

    SumThread *sumThr = new SumThread(tab, n);/* =  new SumThread(tab, 50);*/
    SumListener *sumLis = new SumListener;
    QObject::connect(sumThr, SIGNAL(notify(int, int, int)), sumLis, SLOT(listen(int, int, int)));
    //QThreadPool::globalInstance()->setMaxThreadCount(2);
    QThreadPool::globalInstance()->start(sumThr);


    //qDebug() << QThreadPool::globalInstance()->maxThreadCount();
    //qDebug() <<"Working threads: " <<QThreadPool::globalInstance()->activeThreadCount();



    //qmlRegisterType<SumListener>("io.qt.sumlistener", 1, 0, "SumLis");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myProgress", sumLis);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //QThreadPool::globalInstance()->releaseThread(&sumThr);


    return app.exec();
}
