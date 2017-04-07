
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
#include "receiver.h"
#include"sendtoservice.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    ReceiverFromQML receiverfromQML;
    view.rootContext()->setContextProperty("receiver",&receiverfromQML);

   // Audio _audio;

    SendToService sendtoservice;

   QObject::connect(&receiverfromQML, ReceiverFromQML::playMusic, &sendtoservice, SendToService::loadToShareMemory);






    return app.exec();
}
