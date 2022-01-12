#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    m_buildings = FileManager::loadBuildings();
    m_player = FileManager::loadPlayer();
}

int Game::getBuildingCount(int index){
    return m_buildings.at(index).getType();
}

int Game::getResources(int index){
    int resource = m_player.getResources(index);
    return resource;
}

void Game::setBuilding(int index, int buildingN){
    m_buildings.at(index).setType(buildingN);
    FileManager::writeXml(index, buildingN);
}

void Game::newGame(){
    FileManager::newGame();
    m_buildings = FileManager::getBuildings();
    exit(0);
}
