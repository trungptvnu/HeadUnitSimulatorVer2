
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QWindow>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QQuickItem>
#include <QObject>
#include <QQmlContext>
#include <QQuickView>

#include "audio.h"
#include "hmieventcontroller.h"
#include"sendtoappmain.h"
#include "receivefromappmain.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQuickView view;
     HMIEventController hMIEventController;
    ReceiveFromAppMain receiveFromAppMain;

    view.rootContext()->setContextProperty("hMIEventController",&hMIEventController);
    view.rootContext()->setContextProperty("receiveFromAppMain",&receiveFromAppMain);
    view.setSource(QUrl("qrc:/main.qml"));


   Thread thread;
   thread.start();

    SendToAppMain sendToAppMain;

   QObject::connect(&hMIEventController, HMIEventController::playMusic, &sendToAppMain, SendToAppMain::writeSharedMemory);
   QObject::connect(&receiveFromAppMain,ReceiveFromAppMain::musicPlayedEvent,&hMIEventController,HMIEventController::playedMusic);

   return app.exec();
}
