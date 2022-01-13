
import QtQuick 2.0

Rectangle{
    property int tileIndex: 0
    property int buildingSideCount: 5
    property int buildingCount: tileIndex

    id: buildingTile
    width: 60
    height: 60
    border.width: 3
    radius: 4

    Image {
        id: goldImg
        opacity: 0
        source: "images/gold.png"
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
            if (buildingTile.state == "placeForGold" && game.getResources(0) >= 200){
                buildingTile.state = "simpleGoldBuilding"
                game.setBuilding(tileIndex, 1)
                player.fillPlayer()
            } else {

            }
        }
    }

    states: [
        State {
            name: "simpleGoldBuilding"
            PropertyChanges {
            target: goldImg
            opacity: 100
            }   
        },

        State {
            name: "field"
            PropertyChanges {
                target: buildingTile
                color: "grey"
            }
       },
        State {
            name: "placeForGold"
            PropertyChanges {
                target: buildingTile
                border.color: "gold"
                color: "gold"
            }
        },
        State {
            name: "placeForWood"
            PropertyChanges {
                target: buildingTile
                border.color: "brown"
                color: "brown"
            }
        },
        State {
            name: "placeForStone"
            PropertyChanges {
                target: buildingTile
                border.color: "grey"
                color: "grey"
            }
        },
        State {
            name: "win"
            PropertyChanges {
                target: buildingTile
                border.color: "red"
                color: "red"
            }
        }


  ]

    state: {
        if (buildingCount === 1){
            state: "placeForGold"
       } else if(buildingCount === 2){
            state: "simpleGoldBuilding"
       } else if (buildingCount === 4){
            state: "placeForWood"
       } else if (buildingCount === 7){
            state: "placeForStone"
       } else if (buildingCount === 0){
            state: "win"
       } else {
            state: "field"
        }
    }
}



