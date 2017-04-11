#ifndef RECEIVERESULT_H
#define RECEIVERESULT_H

#include <QObject>
#include <QSharedMemory>
#include <QThread>

class ReceiveFromAppMain :public QThread
{
    Q_OBJECT


public:
    ReceiveFromAppMain();
    void loadFromMemory();
    void runCheckMemory();

signals:
    void musicPlayedEvent();

 private:
    QThread workerThread;
    QSharedMemory sharedMemory;
};

#endif // RECEIVERESULT_H
