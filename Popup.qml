
import QtQuick 2.0

Rectangle{
    property string gameText: ""

    anchors.fill: parent
    opacity: 0.8

    Rectangle {
        color: "black"
        width: 600
        height: 80
        radius: 10
        anchors.centerIn: parent

        Text {
            id: resourcesText
            text: gameText
            color: "white"
            anchors.centerIn: parent
            font.pixelSize: 26
        }

        Text {
            id: winText
            text: gameText
            color: "white"
            anchors.centerIn: parent
            font.pixelSize: 26
        }
    }

}
