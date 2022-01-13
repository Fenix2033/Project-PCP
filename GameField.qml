
import QtQuick 2.0

Rectangle {

    property int buildingSideCount: 5
    property alias buildingSpacing: buildingGrid.spacing

    color: "black"

    Grid{
        x: buildingSpacing
        y: buildingSpacing
        id: buildingGrid
        columns: buildingSideCount
        spacing: 10

        Repeater{
            id: repeaterBuilding
            model: buildingSideCount*buildingSideCount

            BuildingTile{
                id: repeaterBuildingTile
                tileIndex: index
                buildingCount: game.getBuildingCount(tileIndex)
                width: (gameField.width/buildingSideCount)-(buildingSpacing/(buildingSideCount-1)*buildingSideCount)
                height: (gameField.height/buildingSideCount)-(buildingSpacing/(buildingSideCount-1)*buildingSideCount)
            }
        }
    }
}
