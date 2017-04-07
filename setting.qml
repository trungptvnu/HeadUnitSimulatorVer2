import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0
import QtWinExtras 1.0 as Win



Rectangle
{

    id: item
    width: 640
    height: 480
    visible: true
    color : "orange"
    Image
    {
        id: img
        width: item.width
        height: item.height
        source: "qrc:/imagebackgroud/background.jpg"
    }

}
