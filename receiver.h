#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

#include <QDebug>
#include <QWidgetList>
#include <QThread>

class ReceiverFromQML : public QThread
{
    Q_OBJECT

public:
    ReceiverFromQML();
    virtual ~ReceiverFromQML();

   Q_INVOKABLE void play(QString );
signals:
    void playMusic();

};

#endif // RECEIVER_H
