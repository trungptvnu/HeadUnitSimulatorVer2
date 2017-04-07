#include "receiver.h"
#include "audio.h"
#include <QDebug>


ReceiverFromQML::ReceiverFromQML()
{

}

ReceiverFromQML::~ReceiverFromQML()
{

}

void ReceiverFromQML::play(QString event )
{
    if (event=="play")
    {
        emit playMusic();
    }
}
