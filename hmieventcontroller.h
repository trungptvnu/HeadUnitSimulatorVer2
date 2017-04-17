#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

#include <QDebug>
#include <QWidgetList>
#include <QThread>

class HMIEventController : public QObject
{
    Q_OBJECT

public:
    HMIEventController();
    virtual ~HMIEventController();


   Q_INVOKABLE void HMIEvent(QString );

signals:
    void playMusic();
    void stopMusic();
    void played();
public slots:
   void MusicSlot()
    {
        emit played();
        qDebug()<<"da ket noi";
    }

};

#endif // RECEIVER_H
