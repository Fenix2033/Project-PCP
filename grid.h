#ifndef GRID_H
#define GRID_H
#include <QObject>
#include <vector>
#include "filemanager.h"
#include "building.h"
#include "Position.h"


class Grid : public QObject
{
public:
    explicit Grid(QObject *parent = nullptr);
    Q_INVOKABLE Building getBuilding(Position);
private:
    std::vector<Building> m_building;
};

#endif // GRID_H
