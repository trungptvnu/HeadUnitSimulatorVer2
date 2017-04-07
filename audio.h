#ifndef AUDIO_H
#define AUDIO_H

#include <QObject>
#include "receiver.h"

class Audio
{
public:
    Audio();
signals:
    void playMusic();
};

#endif // AUDIO_H
