#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QString>

#include <QDebug>
#include <QWidgetList>
#include <QThread>

class HMIEventController : public QThread
{
    Q_OBJECT

public:
    HMIEventController();
    virtual ~HMIEventController();


   Q_INVOKABLE void HMIEvent(QString );

signals:
    void playMusic();
    void stopMusic();
    void musicIsPlayed();
public slots:
   void playedMusic()
    {
        emit musicIsPlayed();
    }

};

#endif // RECEIVER_H
