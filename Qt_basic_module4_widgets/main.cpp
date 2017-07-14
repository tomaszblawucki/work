#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
//    translator.load("QtLanguage_pl_PL", ".");
//    qApp->installTranslator(&translator);
    qDebug() << translator.load("QtLanguage_pl_PL", ".");
    qDebug() <<  a.installTranslator(&translator);
    qDebug() << translator.isEmpty();



    MainWindow w;
    w.show();

    return a.exec();
}
