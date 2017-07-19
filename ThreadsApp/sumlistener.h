#ifndef SUMLISTENER_H
#define SUMLISTENER_H

#include <QObject>

class SumListener : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double progress READ getProgress NOTIFY progressChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
public:
    explicit SumListener(QObject *parent = nullptr);
    double progress;
    QString name;
    double getProgress(){return progress;}
    QString getName(){return name;}

signals:
    void progressChanged();
    void nameChanged();
public slots:
    void listen(int, int, int);

};

#endif // SUMLISTENER_H
