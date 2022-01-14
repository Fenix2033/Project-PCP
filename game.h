#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>
#include "filemanager.h"
#include "building.h"
#include "player.h"
#include "errorloger.h"

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    Q_INVOKABLE int getBuildingCount(int index);
    Q_INVOKABLE void setBuilding(int index, int buildingTyp);
    Q_INVOKABLE void newGame();
    Q_INVOKABLE int getResources(int index);
    Q_INVOKABLE int getTurn();
    Q_INVOKABLE int getProfitResources(int index);
    Q_INVOKABLE int getScore();
    Q_INVOKABLE void skipTurn();
    Q_INVOKABLE void gameExit();
    Q_INVOKABLE bool checkResources(int buildingType);
    Q_INVOKABLE void market(int index);
    Q_INVOKABLE void saveGame();

signals:

private:
    std::vector<Building> m_buildings;
    Player m_player;
public:
};

#endif // GAME_H
