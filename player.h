#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <array>

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
    void setResources(int index, int count);
    void setTurn(int count);
    void setProfitResources(int index, int count);
    void addTurn();
};

#endif // PLAYER_H
