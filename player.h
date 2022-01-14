#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <array>
#include "building.h"
#include "errorloger.h"

class Player{
private:
    std::array<int, 3> m_resources = {0, 0, 0};
    int m_turn = 0;
    std::array<int, 3> m_profitResources = {0, 0, 0};
    int m_score = 0;
public:
    Player();
    int getResources(int index);
    int getTurn();
    int getProfitResources(int index);
    int getScore();
    void setBuilding(int buildingType);
    void setProfitResources(int index, int count);
    void setScore(int count);
    bool checkResources(int buildingType);
    void loadResources(int index, int resourceCount);
    void loadResourcesProfit(int index, int resourceCount);
    void loadTurn(int countTurn);
    void loadScore(int countScore);
    void skipTurn();
    void setResources(int index, int count);
};

#endif // PLAYER_H
