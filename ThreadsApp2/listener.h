#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include <QMap>

class Listener : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double progress READ getProgress NOTIFY progressChanged)

private:
    int threadCount;
    QMap<QString, double> threadsProgress;
    QMap<QString, bool> threadsFinished;
    long int result;
    bool resultReady();
public:
    explicit Listener(int tc, QObject *parent = nullptr);
    double progress;
    double getProgress(){return(progress/100);}
    void addThread(QString);

signals:
    void progressChanged();
public slots:
    void listen(QString, double);
    void calculationFinish(QString, double);
};

#endif // LISTENER_H
