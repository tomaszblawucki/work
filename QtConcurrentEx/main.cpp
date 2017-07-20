#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "threadrunner.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    ThreadRunner runner;
    runner.runProcess();


    return app.exec();
}
