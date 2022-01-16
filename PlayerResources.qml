import QtQuick 2.0


Rectangle {
    property string title: "Player"
    property int gold: game ? game.getResources(0) : 0
    property int wood: game ? game.getResources(1) : 0
    property int stone: game ? game.getResources(2) : 0
    property int turn: game ? game.getTurn() : 0
    property int profitGold: game ? game.getProfitResources(0) : 0
    property int profitWood: game ? game.getProfitResources(1) : 0
    property int profitStone: game ? game.getProfitResources(2) : 0
    property int score: game ? game.getScore() : 0

    id: playerResources;
    color: "Blue"
    width: parent.width * 0.2
    height: parent.height * 0.38

    Text {
        id: textGold
        text: " Gold: " + gold
        color: "gold"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textWood
        text: "\n Wood: " + wood
        color: "brown"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textStone
        text: "\n \n Stone: " + stone
        color: "grey"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textTurn
        text: "\n \n \n Turn: 150/" + turn
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textProfitGold
        text: "\n \n \n \n Profit Gold: " + profitGold
        color: "gold"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textProfitWood
        text: "\n \n \n \n \n Profit Wood: " + profitWood
        color: "brown"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textProfitStone
        text: "\n \n \n \n \n \n Profit Stone: " + profitStone
        color: "grey"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    Text {
        id: textScore
        text: "\n \n \n \n \n \n \n Score: " + score
        color: "crimson"
        font.bold: true
        font.pixelSize: 30
        anchors.leftMargin: 10
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            fillPlayer()
        }
    }

    function fillPlayer(){
        gold = game ? game.getResources(0) : 0
        wood = game ? game.getResources(1) : 0
        stone = game ? game.getResources(2) : 0
        turn = game ? game.getTurn() : 0
        profitGold = game ? game.getProfitResources(0) : 0
        profitWood = game ? game.getProfitResources(1) : 0
        profitStone = game ? game.getProfitResources(2) : 0
        score = game ? game.getScore() : 0
        textGold.text = " Gold: " + gold
        textWood.text = "\n Wood: " + wood
        textStone.text = "\n \n Stone: " + stone
        textTurn.text = "\n \n \n Turn: 150/" + turn
        textProfitGold.text = "\n \n \n \n Profit Gold: " + profitGold
        textProfitWood.text = "\n \n \n \n \n Profit Wood: " + profitWood
        textProfitStone.text = "\n \n \n \n \n \n Profit Stone: " + profitStone
        textScore.text = "\n \n \n \n \n \n \n Score: " + score
    }
}


