#include "player.h"

Player::Player(){}

int Player::getResources(int index){
    return m_resources.at(index);
}

int Player::getTurn(){
    return m_turn;
}

int Player::getProfitResources(int index){
    return m_profitResources.at(index);
}

int Player::getScore(){
    return m_score;
}

void Player::setBuilding(int buildingType){
    if (checkResources(buildingType) == true){
        Building *building = new Building;
        building->setType(buildingType);  
        m_resources.at(0) -= building->getPrice().at(0);
        m_resources.at(1) -= building->getPrice().at(1);
        m_resources.at(2) -= building->getPrice().at(2);
        skipTurn();
        try {
            switch (buildingType){
              case 2:
                m_profitResources.at(0) += building->getProfit();
                m_score += 5;
                break;
              case 3:
                m_profitResources.at(0) += -5 + building->getProfit();
                m_score += 5;
                break;
              case 5:
                m_profitResources.at(1) += building->getProfit();
                m_score += 5;
                break;
              case 6:
                m_profitResources.at(1) += -5 + building->getProfit();
                m_score += 10;
                break;
              case 8:
                m_profitResources.at(2) += building->getProfit();
                m_score += 10;
                break;
              case 9:
                m_profitResources.at(2) += -5 + building->getProfit();
                m_score += 10;
                break;
              case 0:
                std::cout << "You Win" << std::endl;
                m_score += 100;
                break;
               default:  throw std::invalid_argument("Building type does not exist");
            }
        } catch(std::invalid_argument){
            ErrorLoger::writeError("Class: Player. method: setBuilding. Building type does not exist");
        }
        delete building;
    }


}

void Player::skipTurn(){
    for (unsigned int i = 0; i < m_resources.size(); i++){
        m_resources.at(i) += m_profitResources.at(i);
    }
   m_turn++;
}

void Player::setScore(int count){
    m_score += count;
}

bool Player::checkResources(int buildingType){
    bool check;
    Building *building = new Building;
    building->setType(buildingType);
    if (m_resources.at(0) >= building->getPrice().at(0) and
            m_resources.at(1) >= building->getPrice().at(1) and
            m_resources.at(2) >= building->getPrice().at(2)){
        check = true;
    } else check = false;
    delete building;
    return check;
}

void Player::loadResources(int index, int resourceCount){
    m_resources.at(index) = resourceCount;
}

void Player::loadResourcesProfit(int index, int resourceCount){
    m_profitResources.at(index) = resourceCount;
}

void Player::loadTurn(int countTurn){
    m_turn = countTurn;
}

void Player::loadScore(int countScore){
    m_score = countScore;
}

void Player::setResources(int index, int count){
    m_resources.at(index) += count;
}
