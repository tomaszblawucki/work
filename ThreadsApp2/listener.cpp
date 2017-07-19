#include "listener.h"
#include <QDebug>

Listener::Listener(QObject *parent) : QObject(parent)
{

}

void Listener::listen(int prog)
{
    progress = prog;
    qDebug()<<"Current progress: " << progress;
}


void Listener::listen(QString prog)
{
    qDebug()<<"Current progress string: " << prog;
}
