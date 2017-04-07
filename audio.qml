import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0



Rectangle
{
    id: item
    width: 640
    height: 480
    visible: true



    Image {
        id: img
        width: item.width
        height: item.height
        source: "qrc:/imagebackgroud/background.jpg"
    }
    ColumnLayout
    {
        id: column
        anchors.margins: 9
        anchors.fill: parent

        Label
        {
            id: infoLabel

            elide: Qt.ElideLeft
            verticalAlignment: Qt.AlignCenter
            Layout.minimumHeight: infoLabel.implicitHeight
            Layout.fillWidth: true
            Layout.fillHeight: true

        }
        RowLayout
        {
            id: row


//            ToolButton
//            {
//                tooltip: qsTr("Rewind")
//                iconSource: "qrc:/imageaudio/media-seek-backward-32.png"
//                onClicked:
//                {

//                    audioController.seekBackward()
//                    console.log("seekBackward")
//                }
//            }
//            ToolButton
//            {
//                tooltip: qsTr("Forward")
//                iconSource: "qrc:/imageaudio/media-seek-forward-32.png"
//                onClicked:
//                {

//                    audioController.seekForward()
//                    console.log("seekForward")
//                }
//            }
            ToolButton
            {

            }
            ToolButton
            {

            }

            ToolButton
            {

            }

            ToolButton
            {
                id: previousButon
                tooltip: qsTr("previous")
                iconSource: "qrc:/imageaudio/previous-32.png"
                onClicked:
                {
                    audioController.previous()
                    console.log("previous")
                }
            }
            ToolButton
            {

            }
            ToolButton
            {

            }

            ToolButton
            {
                id: playPauseButton
                Layout.preferredWidth: playPauseButton.implicitHeight
                iconSource: "qrc:/imageaudio/media-play-32.png"
                // enable audio

//                Connections
//                {
//                    target: receiver
//                    onPlayState: {
//                        console.log("Received in QML from C++: " + mgs)
//                    }
//                }
                MouseArea
                {
                    id: mouseArea
                    anchors.fill: parent
                    onClicked:
                    {
                        receiver.play("play");
                    }

                }

            }
            ToolButton
            {

            }
            ToolButton
            {

            }

            ToolButton
            {
                id: stopButton
                Layout.preferredWidth: stopButton.implicitHeight
                iconSource: "qrc:/imageaudio/media-stop-32.png"
                onClicked:
                {
                    audioController.stop()
                    console.log("Stop")
                }
            }
            ToolButton
            {

            }
            ToolButton
            {

            }

            ToolButton
            {
                tooltip: qsTr("Next")
                iconSource: "qrc:/imageaudio/next-32.png"
                onClicked:
                {
                    audioController.next()
                    console.log("next")
                }
            }


        }
        RowLayout
        {
            id: rowLayout2
            Slider
            {
                id: positionSlider
                Layout.minimumWidth: 75
                Layout.fillWidth: true

            }
        }

        ColumnLayout
        {
            id: playlist

            ScrollView
            {
                Layout.fillWidth: true
                Layout.fillHeight: true
                flickableItem.interactive: true

                ListView
                {
                    id: playlistView
                    anchors.fill: parent
                    model: playlistModel
                    delegate: playlistDelegate
//                    delegate: PlaylistDelegate {  }
                    highlight: playlistHighlight
                }
            }
            RowLayout
            {
                ToolButton
                {
                    text: qsTr("Add music files")
                    iconSource: "qrc:/imageaudio/plus-32.png"
                    onClicked: addingMusicDialog.open()

                    FileDialog
                    {
                        id: addingMusicDialog
                        //folder : musicUrl
                        title: qsTr("Open audio files")
                        nameFilters: [qsTr("MP3 files (*.mp3)"), qsTr("All files (*.*)")]
                        selectMultiple: true
                        onAccepted:
                        {
                            var file_protocol = "file:///"
                            for (var i = 0; i < fileUrls.length; i++)
                            {
                                var path = fileUrls[i].toString()
                                path = path.substring(file_protocol.length, path.length)
                                playlistModel.append( { "path" : path, } )
                            }
                        }
                    }
                }

            }
            Component
            {
                id: playlistDelegate

                Item
                {
                    width: parent.width
                    height: 30

                    Rectangle
                    {
                        id : rectItem
                        anchors.fill: parent
                        color: "#33000000"
                        radius: 5
                        visible: mouse.pressed
                    }

                    Text {
                        x: 10
                        y: 10
                        text: path
                    }

                    MouseArea
                    {
                        id: mouse
                        anchors.fill: parent
                        onClicked: playlistView.currentIndex = index
                        onDoubleClicked: mediaPlayer.source = path
                    }
                }
            }
            Component
            {
                id: playlistHighlight
                Rectangle
                {
                    color: "gray"
                    radius: 5
                    y: playlistView.currentItem.y
                    Behavior on y
                    {
                        SpringAnimation
                        {
                            spring: 3
                            damping: 0.2
                        }
                    }
                }
            }
            ListModel
            {
                id: playlistModel
            }
        }

    }

}
