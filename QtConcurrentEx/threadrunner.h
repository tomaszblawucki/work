#ifndef THREADRUNNER_H
#define THREADRUNNER_H

#include <QObject>
#include <QVector>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent>
#include "myint.h"

class ThreadRunner : public QObject
{
    Q_OBJECT

private:
    QVector<int> resource;
    double progress;
    int sum;
public:
    explicit ThreadRunner(QObject *parent = nullptr);
    bool filter2(const int &val);
    int add(const int &val);
    static void reduce2(int &result, const int &iteration);
    void runProcess();

signals:

public slots:
};

#endif // THREADRUNNER_H
