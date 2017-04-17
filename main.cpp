
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
#include <QtConcurrent/QtConcurrent>
#include <QThread>

#include "audio.h"
#include "hmieventcontroller.h"
#include"sendtoappmain.h"
#include "receivefromappmain.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQuickView view;
    SendToAppMain sendToAppMain;
    HMIEventController hmiEventController;
    //HMIEventController hMIEventController2;


    view.rootContext()->setContextProperty("hmiEventController",&hmiEventController);
    //view.rootContext()->setContextProperty("hMIEventController2",&hMIEventController2);
    view.setSource(QUrl("qrc:/main.qml"));
 // ket noi gui di

    QObject::connect(&hmiEventController, HMIEventController::playMusic, &sendToAppMain, SendToAppMain::writeSharedMemory);


  // ket noi gui ve

    ReceiveFromAppMain receiveFromAppMain;
    QObject::connect(&receiveFromAppMain,ReceiveFromAppMain::musicIsPlayed,&hmiEventController,HMIEventController::MusicSlot);
    QObject::connect(&receiveFromAppMain,QThread::finished,&hmiEventController,QObject::deleteLater);
    receiveFromAppMain.start();
    return app.exec();
}
