#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    m_building = FileManager::loadXml();
    m_buildings = FileManager::getBuildings();
}

int Game::getBuildingCount(int index){
    return m_building.at(index);
}

void Game::setBuilding(int index, int buildingN){
    m_buildings.at(index).setType(buildingN);
    FileManager::writeXml(index, buildingN);
}

void Game::newGame(){
    FileManager::newGame();
    m_building = FileManager::loadXml();
    m_buildings = FileManager::getBuildings();
    exit(0);
}
