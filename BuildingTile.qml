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

    state: {
        switch (buildingCount){
          case 1:
            state: "placeForGold"
            break;
          case 2:
            state: "simpleGoldBuilding"
            break;
          case 3:
             state: "updateGoldBuilding"
            break;
          case 4:
            state: "placeForWood"
            break;
          case 5:
            state: "simpleWoodBuilding"
            break;
          case 6:
            state: "updateWoodBuilding"
            break;
          case 7:
            state: "placeForStone"
            break;
          case 8:
            state: "simpleStoneBuilding"
            break;
          case 9:
            state: "updateStoneBuilding"
            break;
          case 10:
            state: "placeForHome"
            break;
          case 0:
            state: "win"
            break;
          default: state: "field"
        }
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            if (buildingTile.state === "placeForGold" && game.checkResources(2) === true){
                buildingTile.state = "simpleGoldBuilding";
                game.setBuilding(tileIndex, 2);
            } else if (buildingTile.state === "placeForWood" && game.checkResources(5) === true){
                buildingTile.state = "simpleWoodBuilding";
                game.setBuilding(tileIndex, 5);
            } else if (buildingTile.state === "placeForStone" && game.checkResources(8) === true){
                buildingTile.state = "simpleStoneBuilding";
                game.setBuilding(tileIndex, 8);
            } else if (buildingTile.state === "simpleGoldBuilding" && game.checkResources(3) === true){
                 buildingTile.state = "updateGoldBuilding";
                 game.setBuilding(tileIndex, 3);
            } else if (buildingTile.state === "simpleWoodBuilding" && game.checkResources(6) === true){
                 buildingTile.state = "updateWoodBuilding"
                 game.setBuilding(tileIndex, 6)
            } else if (buildingTile.state === "simpleStoneBuilding" && game.checkResources(9) === true){
                  buildingTile.state = "updateStoneBuilding"
                  game.setBuilding(tileIndex, 9)
            } else if (buildingTile.state === "placeForHome" && game.checkResources(0) === true){
                    buildingTile.state = "home"
                    game.setBuilding(tileIndex, 0)
                    winText.visible = true
                    visibileField();
                    resourcesText.visible = false;
                    buttonVisibleText.visible = false;
                    game.setWinScore();
                    playerResources.fillPlayer()
                    playerResources.visible = true;
                    buttonNewGame.visible = true;
                    buttonExit.visible = true;
                    game.newGame();
            } else if (buildingTile.state === "updateGoldBuilding" || buildingTile.state === "updateWoodBuildin"
                       || buildingTile.state === "updateStoneBuilding"){

            } else visibileField();

            if (game.getTurn() > 150){
                lostText.visible = true;
                visibileField();
                gameField.visible = false;
                buttonVisibleText.visible = false;
                playerResources.visible = true;
                buttonNewGame.visible = true;
                buttonExit.visible = true;
                resourcesText.visible = false;
                game.newGame();
            }

            playerResources.fillPlayer();
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
        buttonSaveGame.visible = false;
        buttonBuyWood.visible = false;
        buttonBuyStone.visible = false;
        buttonSellWood.visible = false;
        buttonSellStone.visible = false;
    }

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
        id: updateGoldImg
        opacity: 0
        source: "images/goldUpdate.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent

    }

    Image {
        id: updateWoodImg
        opacity: 0
        source: "images/woodUpdate.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent

    }

    Image {
        id: updateStoneImg
        opacity: 0
        source: "images/stoneUpdate.png"
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
            name: "updateGoldBuilding"
            PropertyChanges {
            target: updateGoldImg
            opacity: 100
            }
        },
        State {
            name: "updateWoodBuilding"
            PropertyChanges {
            target: updateWoodImg
            opacity: 100
            }
        },
        State {
            name: "updateStoneBuilding"
            PropertyChanges {
            target: updateStoneImg
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
}
