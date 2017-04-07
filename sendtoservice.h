#ifndef SENDTOSERVICE_H
#define SENDTOSERVICE_H

#include <QObject>
#include <QSharedMemory>
#include "receiver.h"

class SendToService: public QObject
{
    Q_OBJECT
public:
    SendToService();
public slots:
    void loadToShareMemory();

private:
    QSharedMemory sharedMemory;

};

#endif // SENDTOSERVICE_H
