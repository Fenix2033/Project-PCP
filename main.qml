import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1366
    height: 720
    visible: true
    title: qsTr("Game")

    GameField{
        height: parent.height-60
        width: height
        anchors.centerIn: parent
        homeSpacing: 5
        homeSideCount: 5

    }

    NewGame {
        id: buttonNewGame
        title: "New game"
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 0
            topMargin: 0
        }
    }

}

