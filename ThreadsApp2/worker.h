#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QVector>


class Worker : public QThread
{

    Q_OBJECT
public:
    Worker(QVector<int>::iterator b,
           QVector<int>::iterator e,
           QVector<int> &v);
    void run();
    long int getSum();
    bool ready = false;
    QString getId();

public slots:
    //int process();

signals:
    //void finished();
    void progressed(QString, double);
    void fin(QString, double);

private:
    long int partial_sum;
    long int size;
    QVector<int>::iterator begin;
    QVector<int>::iterator end;
    QVector<int> *vector;
    QString id;

};

#endif // WORKER_H
