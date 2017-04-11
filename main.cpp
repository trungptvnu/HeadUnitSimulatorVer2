
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
#include "receivefromhmi.h"
#include"sendtoappmain.h"
#include "receivefromappmain.h"
#include "thread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQuickView view;
     ReceiveFromHMI receiveFromHMI;
    ReceiveFromAppMain receiveFromAppMain;

    view.rootContext()->setContextProperty("receiveFromHMI",&receiveFromHMI);
    view.rootContext()->setContextProperty("receiveFromAppMain",&receiveFromAppMain);
    view.setSource(QUrl("qrc:/main.qml"));

   Thread thread;
   thread.start();

    SendToAppMain sendToAppMain;

   QObject::connect(&receiveFromHMI, ReceiveFromHMI::playMusic, &sendToAppMain, SendToAppMain::writeSharedMemory);

    return app.exec();
}
