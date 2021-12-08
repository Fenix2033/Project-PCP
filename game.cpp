#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    m_building = FileManager::loadXml();
}

int Game::getBuildingCount(int index){
    return m_building.at(index);
}

void Game::setBuilding(int index, int buildingN){
    m_building.at(index) = buildingN;
}
