#ifndef RECEIVERESULT_H
#define RECEIVERESULT_H

#include <QObject>
#include <QSharedMemory>
#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QWaitCondition>

class ReceiveFromAppMain :public QThread
{
    Q_OBJECT


public:
    ReceiveFromAppMain();
    ~ReceiveFromAppMain();
    void run() override;
    void readSharedMemory();

//comunication
signals:
    void musicIsPlayed();

 private:

     QMutex mutex;
     QWaitCondition condition;

    QSharedMemory sharedMemory;
};

#endif // RECEIVERESULT_H
