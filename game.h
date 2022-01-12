#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>
#include "filemanager.h"
#include "building.h"
#include "player.h"
#include "position.h"


class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    Q_INVOKABLE int getBuildingCount(int index);
    Q_INVOKABLE void setBuilding(int index, int buildingN);
    Q_INVOKABLE void newGame();
    Q_INVOKABLE int getResources(int index);
    Q_INVOKABLE void gameExit();
signals:

private:
    std::vector<Building> m_buildings;
    Player m_player;
public:
};

#endif // GAME_H
