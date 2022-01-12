import QtQuick 2.0


Rectangle {
    id: buttonNewGame
    property string title: "New Game"

    color: "black"
    width: parent.width * 0.2
    height: parent.height * 0.1

    Text {
        text: buttonNewGame.title
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.centerIn: parent
    }


    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            game.newGame()
        }
    }



}
