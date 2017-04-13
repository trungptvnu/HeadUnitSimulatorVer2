#include "hmieventcontroller.h"
#include "audio.h"
#include <QDebug>


HMIEventController::HMIEventController()
{

}

HMIEventController::~HMIEventController()
{

}

void HMIEventController::HMIEvent(QString event )
{
    if (event=="play")
    {
        emit playMusic();
    }
    if (event=="stop")
    {
        emit stopMusic();
    }
}

