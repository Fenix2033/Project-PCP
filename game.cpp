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

int Game::getTurn(){
    int turn = m_player.getTurn();
    return turn;
}

int Game::getProfitResources(int index){
    int resourceProfit = m_player.getProfitResources(index);
    return resourceProfit;
}

void Game::setBuilding(int index, int buildingN){
    m_buildings.at(index).setType(buildingN);
    m_player.setBuilding(buildingN);
    FileManager::writeBuildings(index, buildingN);
    FileManager::writePlayer(m_player);
}


void Game::skipTurn(){
    m_player.skipTurn();
}

void Game::newGame(){
    FileManager::newGame();
}

void Game::gameExit(){
    exit(0);
}

bool Game::checkResources(int buildingType){
    bool check = m_player.checkResources(buildingType);
    return check;
}
