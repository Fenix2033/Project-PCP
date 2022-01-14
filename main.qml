import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: windowGame
    width: 1900
    height: 720
    visible: true
    title: qsTr("Game")

    GameField{
        id: gameField
        height: parent.height-60
        width: height
        anchors.centerIn: parent
        buildingSpacing: 5
        buildingSideCount: 5

    }

    Button {
        id: buttonNewGame
        title: "New game"
        state: "newGame"
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonSaveGame
        title: "Save"
        state: "save"
        anchors {
            left: parent.left
            top: buttonNewGame.bottom
            leftMargin: 0
            topMargin: 0
        }
    }


    Button {
        id: buttonExit
        title: "Exit"
        state: "exit"
        anchors {
            left: parent.left
            top: buttonSaveGame.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonSkipTurn
        title: "Skip Turn"
        state: "skipTurn"
        anchors {
            left: parent.left
            top: buttonExit.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    PlayerResources {
        id: playerResources
        anchors {
            left: parent.left
            top: buttonSkipTurn.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    PriceBuilding {
        id: priceBuilding
        anchors {
            right: parent.right
            top: parent.top
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonSellWood
        title: "Sell wood 10 for 80 gold"
        state: "sellWood"
        anchors {
            right: parent.right
            top: priceBuilding.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonSellStone
        title: "Sell stone 10 for 80 gold"
        state: "sellStone"
        anchors {
            right: parent.right
            top: buttonSellWood.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonBuyWood
        title: "Buy wood 10 for 100 gold"
        state: "buyWood"
        anchors {
            right: parent.right
            top: buttonSellStone.bottom
            leftMargin: 0
            topMargin: 0
        }
    }

    Button {
        id: buttonBuyStone
        title: "Buy stone 10 for 100 gold"
        state: "buyStone"
        anchors {
            right: parent.right
            top: buttonBuyWood.bottom
            leftMargin: 0
            topMargin: 0
        }
    }



    Popup {
        id: resourcesText
        gameText: "You don't have enough resources"
        visible: false
    }

    Popup {
        id: winText
        gameText: "You win"
        visible: false
    }

    Popup {
        id: lostText
        gameText: "You lost"
        visible: false
    }

    Button {
        id: buttonVisibleText
        title: "x"
        state: "closeTextVisible"
        visible: false
        anchors {
            left: buttonSkipTurn.right
            top: buttonExit.bottom
            leftMargin: 500
            topMargin: 5
        }
    }


}
