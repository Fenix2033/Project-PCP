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
        }
    ]


    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            if (button.state === "newGame"){
                game.newGame()
            }
            else if (button.state === "exit"){
                game.gameExit();
            } else {

            }
        }
    }
}
