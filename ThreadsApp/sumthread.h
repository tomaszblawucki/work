#ifndef SUMTHREAD_H
#define SUMTHREAD_H

#include <QObject>
#include <QtCore>

class SumThread : public QObject, public QRunnable
{
    Q_OBJECT

private:
    int *arrayPtr;
    int sum;
    int tabSize;

public:
    explicit SumThread(int *arr, int size ,QObject *parent = nullptr);
    void run();

signals:
    void notify(int index, int sum, int tabS);

public slots:
};

#endif // SUMTHREAD_H
