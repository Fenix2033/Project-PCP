#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>
#include "filemanager.h"
#include "building.h"
#include "position.h"


class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    Q_INVOKABLE int getBuildingCount(int index);
    Q_INVOKABLE void setBuilding(int index, int buildingN);
    Q_INVOKABLE void newGame();
signals:

private:
    std::vector<int> m_building;
    std::vector<Building> m_buildings;
public:
};

#endif // GAME_H
