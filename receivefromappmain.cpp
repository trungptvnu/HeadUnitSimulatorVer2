#include "receivefromappmain.h"
#include "hmieventcontroller.h"
#include<QBuffer>
#include<QtCore/QDebug>
#include<QDataStream>
#include <Qtimer>
#include<QThread>

ReceiveFromAppMain::ReceiveFromAppMain()
{

}

ReceiveFromAppMain::~ReceiveFromAppMain()
{
    mutex.lock();
    condition.wakeOne();
    mutex.unlock();
    wait();
}
void ReceiveFromAppMain::readSharedMemory()
{
    sharedMemory.setKey("server1");
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
         //comunication thread
         emit musicIsPlayed();
         qDebug()   << "dang choi nhac";
     }
     buffer.close();
}
void ReceiveFromAppMain::run()
{


   while(1)
    {
      this ->readSharedMemory();
       sleep(1);
   }
}



