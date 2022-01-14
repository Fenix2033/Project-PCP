#include "game.h"

Game::Game(QObject *parent) : QObject(parent){
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

int Game::getScore(){
    int score = m_player.getScore();
    return score;
}

int Game::getProfitResources(int index){
    int resourceProfit = m_player.getProfitResources(index);
    return resourceProfit;
}

void Game::setBuilding(int index, int buildingTyp){
    m_buildings.at(index).setType(buildingTyp);
    m_player.setBuilding(buildingTyp);
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

void Game::saveGame(){
    FileManager::writeBuildings(m_buildings);
    FileManager::writePlayer(m_player);
}

void Game::market(int index){
    try {
        switch (index) {
            case 1:
            m_player.setResources(0, 80);
            m_player.setResources(1, -10);
            break;
            case 2:
            m_player.setResources(0, 80);
            m_player.setResources(2, -10);
            break;
            case 3:
            m_player.setResources(0, -100);
            m_player.setResources(1, 10);
            break;
            case 4:
            m_player.setResources(0, -100);
            m_player.setResources(2, 10);
            break;
            default: throw std::invalid_argument("Market selection does not exist");
        }
    } catch (std::invalid_argument){
            ErrorLoger::writeError("Class: Game. method: market. Market selection does not exist");
        }
}

void Game::setWinScore(){
    int winScore = (150 - m_player.getTurn()) * 20;
    m_player.setScore(winScore);
}
