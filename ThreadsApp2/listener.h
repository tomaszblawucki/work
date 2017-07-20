#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include <QMap>
#include <QDebug>

class Listener : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double progress READ getProgress NOTIFY progressChanged)
    Q_PROPERTY(QString result READ getResult NOTIFY resultChanged)

private:
    int threadCount;
    QMap<QString, double> threadsProgress;
    QMap<QString, bool> threadsFinished;
    long int result;
    bool resultReady();
public:
    explicit Listener(int tc, QObject *parent = nullptr);
    double progress;
    //double getProgress(){return(progress/100);}
    double getProgress(){return(progress/100);}
    QString getResult(){
        qDebug() << "RESULT: "<<result;
        return(QString::number(result));
    }
    void addThread(QString);

signals:
    void progressChanged();
    void resultChanged();
public slots:
    void listen(QString, double);
    void calculationFinish(QString, double);
};

#endif // LISTENER_H
