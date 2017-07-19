#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>


class Worker : public QThread
{

    Q_OBJECT
public:
    Worker();
    void run();

public slots:
    int process();

signals:
    //void finished();
    void progressed(int);

private:
    long int sum;
    long int size;

};

#endif // WORKER_H
