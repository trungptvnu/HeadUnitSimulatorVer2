#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include "qobject.h"

class AudioController :public QObject
{
    Q_OBJECT
//public:
//    AudioController();
signals:
    void playMusic();
};

#endif // AUDIOCONTROLLER_H
