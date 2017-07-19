#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>

class Listener : public QObject
{

    Q_OBJECT
    Q_PROPERTY(double progress READ getProgress NOTIFY progressChanged)

public:
    explicit Listener(QObject *parent = nullptr);
    double progress;
    void getProgress(){return(progress/100);}
signals:
    void progressChanged();
public slots:
    void listen(int);
    void listen(QString);
};

#endif // LISTENER_H
