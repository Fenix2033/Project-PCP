import QtQuick 2.0


Rectangle {
    id: button
    property string title: ""

    color: "black"
    width: parent.width * 0.2
    height: parent.height * 0.1

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            if (button.state === "newGame"){
                game.newGame();
                gameField.fillGrid();
            } else if (button.state === "exit"){
                game.gameExit();
            } else if (button.state === "skipTurn"){
                game.skipTurn();
                if (game.getTurn() > 150){
                    lostText.visible = true;
                    visibleFalse();
                    buttonNewGame.visible = true;
                    buttonExit.visible = true;
                    game.newGame();
                }
            } else if (button.state === "closeTextVisible"){
                resourcesText.visible = false;
                buttonVisibleText.visible = false;
                visibleTrue();


            } else if (button.state === "sellWood"){
                if (game.getResources(1) >= 10){
                    game.market(1);
                } else {
                    visibleFalse();
                    resourcesText.visible = true;
                    buttonVisibleText.visible = true;
                }
            } else if (button.state === "sellStone"){
                if (game.getResources(2) >= 10){
                    game.market(2);
                } else {
                    visibleFalse();
                    resourcesText.visible = true;
                    buttonVisibleText.visible = true;
                }
            } else if (button.state === "buyWood"){
                if (game.getResources(0) >= 80){
                    game.market(3);
                } else {
                    visibleFalse();
                    resourcesText.visible = true;
                    buttonVisibleText.visible = true;
                }
            } else if (button.state === "buyStone"){
                if (game.getResources(0) >= 80){
                    game.market(4);
                } else {
                    visibleFalse();
                    resourcesText.visible = true;
                    buttonVisibleText.visible = true;
                }
            } else if (button.state === "save"){
                game.saveGame();
            }

            else {}
            playerResources.fillPlayer();
        }
    }

    Text {
        text: button.title
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.centerIn: parent
    }

    states: [

        State {
            name: "newGame"
            PropertyChanges {
                target: button
                color: "black"
            }
        },

        State {
            name: "exit"
            PropertyChanges {
                target: button
                color: "red"
            }
        },

        State {
            name: "skipTurn"
            PropertyChanges {
                target: button
                color: "magenta"
        }
      },

        State {
            name: "closeTextVisible"
            PropertyChanges {
                target: button
                color: "red"
                width: parent.width * 0.05
            }
        },

        State {
            name: "sellWood"
            PropertyChanges {
                target: button
                color: "gold"
        }
      },

        State {
            name: "sellStone"
            PropertyChanges {
                target: button
                color: "gold"
        }
      },

        State {
            name: "buyWood"
            PropertyChanges {
                target: button
                color: "brown"
        }
      },

        State {
            name: "buyStone"
            PropertyChanges {
                target: button
                color: "grey"
        }
      },
        State {
            name: "save"
            PropertyChanges {
                target: button
                color: "darkgreen"
        }
      }

   ]

    function visibleFalse(){
        buttonNewGame.visible = false;
        gameField.visible = false;
        buttonExit.visible = false;
        buttonSkipTurn.visible = false;
        playerResources.visible = false;
        priceBuilding.visible = false;
        buttonSaveGame.visible = false;
        buttonBuyWood.visible = false;
        buttonVisibleText.visible = false;
        buttonBuyStone.visible = false;
        buttonSellWood.visible = false;
        buttonSellStone.visible = false;
    }

    function visibleTrue(){
        gameField.visible = true;
        buttonNewGame.visible = true;
        buttonExit.visible = true;
        buttonSkipTurn.visible = true;
        playerResources.visible = true;
        priceBuilding.visible = true;
        buttonSaveGame.visible = true;
        buttonBuyWood.visible = true;
        buttonBuyStone.visible = true;
        buttonSellWood.visible = true;
        buttonSellStone.visible = true;
    }
}
