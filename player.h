#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <array>
#include "building.h"

class Player
{
private:
    std::array<int, 3> m_resources = {0, 0, 0};
    int m_turn = 0;
    std::array<int, 3> m_profitResources = {0, 0, 0};
public:
    Player();

    int getResources(int index);
    int getTurn();
    int getProfitResources(int index);
    void setBuilding(int buildingType);
    void setTurn(int count);
    void setProfitResources(int index, int count);
    bool checkResources(int buildingType);
    void loadResources(int index, int resourceCount);
    void loadResourcesProfit(int index, int resourceCount);
    void skipTurn();
};

#endif // PLAYER_H
