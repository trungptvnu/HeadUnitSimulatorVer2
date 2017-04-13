#include <QBuffer>
#include "sendtoappmain.h"
#include <QtCore/QDebug>
#include<QObject>
#include <QDataStream>
#include "hmieventcontroller.h"


SendToAppMain::SendToAppMain()
{

}


void SendToAppMain::writeSharedMemory()
{

    sharedMemory.setKey("server");

    QString event = "Hello";
    // load into shared memory
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << event;
    int size = buffer.size();

    if (!sharedMemory.create(size))
    {
        qDebug()<<"Unable to create shared memory segment.";
        return;
    }
    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(sharedMemory.size(), size));
    sharedMemory.unlock();
}
