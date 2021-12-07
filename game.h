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

signals:

private:
    std::vector<int> m_building;
};

#endif // GAME_H
