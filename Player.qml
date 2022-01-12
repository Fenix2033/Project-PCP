import QtQuick 2.0


Rectangle {
    property string title: "Player"
    property int money: game.getResources(0)
    property int wood: game.getResources(1)
    property int stone: game.getResources(2)
    color: "Blue"
    width: parent.width * 0.2
    height: parent.height * 0.2

    Text {
        text: "Money: " + money
        color: "gold"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }


    Text {
        text: "\n Wood: " + wood
        color: "brown"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }


    Text {
        text: "\n \n Stone: " + stone
        color: "grey"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

}
