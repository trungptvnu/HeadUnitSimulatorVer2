#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

#include <QDebug>
#include <QWidgetList>
#include <QThread>

class ReceiveFromHMI : public QThread
{
    Q_OBJECT

public:
    ReceiveFromHMI();
    virtual ~ReceiveFromHMI();

   Q_INVOKABLE void play(QString );

signals:
    void playMusic();

};

#endif // RECEIVER_H
