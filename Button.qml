import QtQuick 2.0


Rectangle {
    id: button
    property string title: ""

    color: "black"
    width: parent.width * 0.2
    height: parent.height * 0.1

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
        }

   ]


    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            if (button.state === "newGame"){
                game.newGame();
                game.gameExit();
            }
            else if (button.state === "exit"){
                game.gameExit();
            }
            else if (button.state === "skipTurn"){
                game.skipTurn();
                playerResources.fillPlayer();
                if (game.getTurn() > 150){
                    lostText.visible = true
                    gameField.visible = false;
                    buttonSkipTurn.visible = false;
                    playerResources.visible = false;
                    priceBuilding.visible = false;
                    game.newGame();
                }
            }
            else if (button.state === "closeTextVisible"){
                resourcesText.visible = false;
                buttonVisibleText.visible = false;
                gameField.visible = true;
                buttonNewGame.visible = true;
                buttonExit.visible = true;
                buttonSkipTurn.visible = true;
                playerResources.visible = true;
                priceBuilding.visible = true
            } else {}
        }
    }
}
