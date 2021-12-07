import QtQuick 2.0

Rectangle{
    property alias tileIndex: label.text
    property string previousState: ""
    id: homeTile
    width: 60
    height: 60
    border.width: 3
    border.color: "black"
    color: "grey"
    radius: 4
    states: [
        State {
            name: "hovered"
            PropertyChanges {
                target: homeTile
                border.color: "white"
            }
        },
        State {
            name: "boom"
            PropertyChanges {
                target: homeImg
                opacity: 100
            }
            PropertyChanges {
                target: label
                opacity: 0
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

            var buildingCount = game.getBuildingCount(tileIndex)
            if (buildingCount == 1){
                HomeTile.state = "boom"
                HomeTile.previousState = HomeTile.state
            } else {
                label.text = buildingCount
            }
        }

        onEntered: {
            homeTile.state = "hovered"
            homeTile.previousState = homeTile.state
        }

        onExited: {
            homeTile.state = homeTile.previousState
        }
    }
}
