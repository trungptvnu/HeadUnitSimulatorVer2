#ifndef RECEIVERESULT_H
#define RECEIVERESULT_H

#include <QObject>
#include <QSharedMemory>
#include <QThread>
#include <QTimer>

class ReceiveFromAppMain :public QObject
{
    Q_OBJECT


public:
    ReceiveFromAppMain();



signals:
    void musicPlayedEvent();
public slots:
     void readSharedMemory();

 private:
    QTimer timer;
    QSharedMemory sharedMemory;
};

#endif // RECEIVERESULT_H
