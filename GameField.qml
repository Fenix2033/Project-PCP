
import QtQuick 2.0

Rectangle {
    id: homeField
    property int homeSideCount: 5
    property alias homeSpacing: homeGrid.spacing

    color: "black"

    Grid{
        x: homeSpacing
        y: homeSpacing
        id: homeGrid
        columns: homeSideCount
        spacing: 10


        Repeater{
            model: homeSideCount*homeSideCount

            HomeTile{
                tileIndex: index
                buildingCount: game.getBuildingCount(tileIndex)
                width: (homeField.width/homeSideCount)-(homeSpacing/(homeSideCount-1)*homeSideCount)
                height: (homeField.height/homeSideCount)-(homeSpacing/(homeSideCount-1)*homeSideCount)


        }
    }
}
}
