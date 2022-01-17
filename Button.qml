import QtQuick 2.0



Rectangle {

    id: button
    property string title: ""

    color: "lightseagreen"
    width: parent.width * 0.2
    height: parent.height * 0.1

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            button.color = "springgreen"
        }

        onExited: {
            button.color = "lightseagreen"
        }

        onClicked: {
            if (button.state === "newGame"){
                game.newGame();
                game.gameExit();
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
        id: buttonText
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
                target: buttonText
                color: "Blue"
            }
        },

        State {
            name: "exit"
            PropertyChanges {
                target: buttonText
                color: "Navy"
            }
        },

        State {
            name: "skipTurn"
            PropertyChanges {
                target: buttonText
                color: "Black"
            }
      },

        State {
            name: "closeTextVisible"
            PropertyChanges {
                target: button
                width: parent.width * 0.05
            }
        },

        State {
            name: "sellWood"
            PropertyChanges {
                target: buttonText
                color: "Gold"
            }
      },

        State {
            name: "sellStone"
            PropertyChanges {
                target: buttonText
                color: "Gold"
            }
      },

        State {
            name: "buyWood"
            PropertyChanges {
                target: buttonText
                color: "Brown"
            }
      },

        State {
            name: "buyStone"
            PropertyChanges {
                target: buttonText
                color: "Grey"
            }
      },
        State {
            name: "save"
            PropertyChanges {
                target: buttonText
                color: "Mediumblue"
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

    function getColorState(){
        return button.state
    }
}
