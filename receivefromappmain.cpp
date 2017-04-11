#include "receivefromappmain.h"
#include<QBuffer>
#include<QtCore/QDebug>
#include<QDataStream>

ReceiveFromAppMain::ReceiveFromAppMain()
{

}
void ReceiveFromAppMain::loadFromMemory()
{
    sharedMemory.setKey("server 1");
    if (!sharedMemory.attach())
    {
        return ;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QString string;

    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >>string;
    sharedMemory.unlock();

     if (string=="Hi")
     {
         emit musicPlayedEvent();
     }
}

void ReceiveFromAppMain::runCheckMemory()
{
    ReceiveFromAppMain *receiveFromAppMain = new ReceiveFromAppMain;
    receiveFromAppMain->moveToThread(& workerThread);
    workerThread.start();
    while(true)
    {
        receiveFromAppMain->loadFromMemory();
        sleep(1);
    }
}
