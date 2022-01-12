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
    m_player.setResources (0, -200);
    m_player.addTurn();
    FileManager::writeBuildings(index, buildingN);
    FileManager::writePlayer(m_player);
}

void Game::addTurn(){
    m_player.addTurn();
}

void Game::newGame(){
    FileManager::newGame();
    exit(0);
}

void Game::gameExit(){
    exit(0);
}
