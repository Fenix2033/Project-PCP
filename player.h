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
    std::array<int, 3> m_resources;
public:
    Player();

    int getResources(int index);
    void setResources(int index, int count);
};

#endif // PLAYER_H
