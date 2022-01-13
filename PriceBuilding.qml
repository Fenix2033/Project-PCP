import QtQuick 2.0


Rectangle {
    property string title: "PriceBuilding"

    id: priceBuilding;
    color: "blue"
    width: parent.width * 0.3
    height: parent.height * 0.4

    Image {
        id: goldBuildng
        source: "images/gold.png"
        width: 32
        height: 32
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Text {

        id: priceSimpleGold
        text: " P: G: 200, W: 50, S: 25. +gold 20"
        color: "gold"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

    Image {
        id: woodBuildng
        source: "images/wood.png"
        width: 32
        height: 32
        anchors.top: goldBuildng.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Text {
        id: priceSimpleWood
        text: "\n P: G: 300, W: 30, S: 40. +wood 5"
        color: "brown"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

    Image {
        id: stoneBuildng
        source: "images/stone.png"
        width: 32
        height: 32
        anchors.top: woodBuildng.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Text {
        id: priceSimpleStone
        text: "\n \n P: G: 500, W: 100, S: 20 +stone: 5"
        color: "grey"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }



    Image {
        id: updateGold
        source: "images/goldUpdate.png"
        width: 32
        height: 32
        anchors.top:  stoneBuildng.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }


    Text {
        id: priceUpdateGold
        text: "\n \n \n P: G: 1000, W: 200, S: 50 +gold: 35"
        color: "gold"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

    Image {
        id: updateWood
        source: "images/woodUpdate.png"
        width: 32
        height: 32
        anchors.top: updateGold.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }


    Text {
        id: priceUpdateWood
        text: "\n \n \n \n P: G: 700, W: 80, S: 100 +wood: 10"
        color: "brown"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

    Image {
        id: updateStone
        source: "images/stoneUpdate.png"
        width: 32
        height: 32
        anchors.top: updateWood.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }


    Text {
        id: priceUpdateStone
        text: "\n \n \n \n \n P: G: 1000, W: 200, S: 50 +stone: 10"
        color: "grey"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

    Image {
        id: homeBuildng
        source: "images/home.png"
        width: 32
        height: 32
        anchors.top: updateStone.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
    }


    Text {
        id: priceHome
        text: "\n \n \n \n \n \n P: G: 2500, W: 800, S: 300 WIN"
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.left: parent.left
        anchors.leftMargin: 50
    }

}

