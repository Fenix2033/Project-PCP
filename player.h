#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class Player
{
private:
    int m_money;
    int m_wood;
    int m_stone;
public:
    Player();
    Player(int money, int wood, int stone);

    int getMoney();
    int getWood();
    int getStone();
    void setMoney(int money);
    void setWood(int wood);
    void setStone(int stone);
};

#endif // PLAYER_H
