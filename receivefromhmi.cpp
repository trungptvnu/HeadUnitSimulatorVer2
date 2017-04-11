#include "receivefromhmi.h"
#include "audio.h"
#include <QDebug>


ReceiveFromHMI::ReceiveFromHMI()
{

}

ReceiveFromHMI::~ReceiveFromHMI()
{

}

void ReceiveFromHMI::play(QString event )
{
    if (event=="play")
    {
        emit playMusic();
    }
}
