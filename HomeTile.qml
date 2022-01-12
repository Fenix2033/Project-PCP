
import QtQuick 2.0

Rectangle{
    property int tileIndex: 0
    property int homeSideCount: 5
    property int buildingCount: tileIndex

    id: homeTile
    width: 60
    height: 60
    border.width: 3
    border.color: "brown"
    color: "brown"
    radius: 4

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
            homeTile.state = "simpleBuilding"
            game.setBuilding(tileIndex, 1)
        }
    }

    states: [
        State {
            name: "simpleBuilding"
            PropertyChanges {
            target: homeImg
            opacity: 100
            }
        },

        State {
            name: "field"
            PropertyChanges {
            }
       }

  ]

    state: {
        if (buildingCount === 1){
            state: "simpleBuilding"
       } else if (buildingCount === 0){
            state: "field"
        }
    }
}



