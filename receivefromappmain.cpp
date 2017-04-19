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

     if (string=="played")
     {

         emit musicIsPlayed("played");
         qDebug()   << "dang choi nhac";
     }
     else if (string=="stopped")
     {

         emit musicIsStopped("stopped");
         qDebug()   << "stop";
     }
    else if (string=="nexted")
     {
         emit musicIsNexted("nexted");
         qDebug()   << "next";
     }
     else if (string == "added")
     {
         emit musicIsAdded ("added");
         qDebug() <<"add";
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



