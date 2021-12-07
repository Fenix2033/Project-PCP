import QtQuick 2.0

Rectangle{
    property alias tileIndex: label.text
    property string previousState: ""
    id: homeTile
    width: 60
    height: 60
    border.width: 3
    border.color: "brown"
    color: "brown"
    radius: 4

//    var buildingCount = game.getBuildingCount(tileIndex)


    states: [
        State {
            name: "revealed"
            PropertyChanges {
                target: homeImg
                opacity: 100
            }
        }
    ]

    Image {
        id: homeImg
        opacity: 0
        source: "images/home.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent
    }

    Text {
        id: label
        text: "0"
        opacity: 0
        font {
            pixelSize: 24
            bold: true
        }
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            homeTile.state = "revealed"
            homeTile.previousState = homeTile.state
        }
    }
}
