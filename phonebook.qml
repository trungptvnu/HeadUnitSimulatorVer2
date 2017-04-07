import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0



Rectangle
{

    id: item
    width: 640
    height: 480
    visible: true
    color : "blue"
    Image
    {
        id: img
        width: item.width
        height: item.height
        source: "qrc:/imagebackgroud/background.jpg"
    }
   TabBar
    {
        id: tabBar
        TabButton
        {
            text: qsTr("Phone List")
        }
        TabButton
        {
            text: qsTr("Recent Call")
        }
        TabButton
        {
            text: qsTr("Favorite Phone Number")
        }

    }

}
