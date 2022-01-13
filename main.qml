import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: windowGame
    width: 1366
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
        id: buttonExit
        title: "Exit"
        state: "exit"
        anchors {
            left: parent.left
            top: buttonNewGame.bottom
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

    Button {
        id: buttonVisibleText
        title: "x"
        state: "closeTextVisible"
        visible: false
        anchors {
            left: buttonSkipTurn.right
            top: buttonSkipTurn.bottom
            leftMargin: 375
            topMargin: 30
        }
    }


}

