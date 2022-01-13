
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

    Image {
        id: woodImg
        opacity: 0
        source: "images/wood.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent

    }

    Image {
        id: stoneImg
        opacity: 0
        source: "images/stone.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent

    }

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

    states: [

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
            name: "placeForHome"
            PropertyChanges {
                target: buildingTile
                border.color: "red"
                color: "red"
            }
        },
        State {
            name: "simpleGoldBuilding"
            PropertyChanges {
            target: goldImg
            opacity: 100
            }
        },
        State {
            name: "simpleWoodBuilding"
            PropertyChanges {
            target: woodImg
            opacity: 100
            }
        },
        State {
            name: "simpleStoneBuilding"
            PropertyChanges {
            target: stoneImg
            opacity: 100
            }
        },
        State {
            name: "home"
            PropertyChanges {
            target: homeImg
            opacity: 100
            }
        }
  ]

    state: {
        if (buildingCount === 1) {
            state: "placeForGold"
       } else if (buildingCount === 2){
            state: "simpleGoldBuilding"
        } else if (buildingCount === 3){
             state: "updateGoldBuilding"
        } else if (buildingCount === 4){
             state: "placeForWood"
        } else if (buildingCount === 5){
             state: "simpleWoodBuilding"
        } else if (buildingCount === 6){
             state: "updateWoodBuilding"
        } else if (buildingCount === 7){
             state: "placeForStone"
       } else if (buildingCount === 8){
            state: "simpleBuildingStone"
       } else if (buildingCount === 9){
            state: "updateBuildingStone"
       } else if (buildingCount === 10){
            state: "placeForHome"
       } else if (buildingCount === 0){
            state: "win"
       } else {
            state: "field"
        }
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            if (buildingTile.state === "placeForGold"){
                if (game.getResources(0) >= 200
                    && game.getResources(1) >= 50 && game.getResources(2) >= 20) {
                        buildingTile.state = "simpleGoldBuilding"
                        game.setBuilding(tileIndex, 2)
                } else {
                    visibileField()
                }
            } else if (buildingTile.state === "placeForWood"){
                if(game.getResources(0) >= 300
                  && game.getResources(1) >= 30 && game.getResources(2) >= 40){
                    buildingTile.state = "simpleWoodBuilding"
                    game.setBuilding(tileIndex, 5)
                } else {
                    visibileField()
                }

            } else if (buildingTile.state === "placeForStone"){
                if(game.getResources(0) >= 500
                  && game.getResources(1) >= 100 && game.getResources(2) >= 20){
                    buildingTile.state = "simpleStoneBuilding"
                    game.setBuilding(tileIndex, 8)
                } else {
                    visibileField()
                }
            } else if (buildingTile.state === "placeForHome"){
                if(game.getResources(0) >= 2500
                  && game.getResources(1) >= 800 && game.getResources(2) >= 300){
                    buildingTile.state = "home"
                    game.setBuilding(tileIndex, 0)
                    winText.visible = true
                    gameField.visible = false;
                    buttonSkipTurn.visible = false;
                    playerResources.visible = false;
            } else {
                    visibileField()
                }

            } else {

            }
            playerResources.fillPlayer()
        }
    }

    function visibileField(){
        resourcesText.visible = true;
        buttonVisibleText.visible = true;
        gameField.visible = false;
        buttonNewGame.visible = false;
        buttonExit.visible = false;
        buttonSkipTurn.visible = false;
        playerResources.visible = false;
        priceBuilding.visible = false;
    }
}


