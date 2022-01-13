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

void Player::setBuilding(int buildingType){
    if (checkResources(buildingType) == true){
        Building *building = new Building;
        building->setType(buildingType);  
        m_resources.at(0) -= building->getPrice().at(0);
        m_resources.at(1) -= building->getPrice().at(1);
        m_resources.at(2) -= building->getPrice().at(2);
        skipTurn();
        switch (buildingType){
          case 2:
            m_profitResources.at(0) += building->getProfit();
            break;
          case 3:
            m_profitResources.at(0) += -5 + building->getProfit();
            break;
          case 5:
            m_profitResources.at(1) += building->getProfit();
            break;
          case 6:
            m_profitResources.at(1) += -5 + building->getProfit();
            break;
          case 8:
            m_profitResources.at(2) += building->getProfit();
            break;
          case 9:
            m_profitResources.at(2) += -5 + building->getProfit();
            break;
           default:  throw std::invalid_argument("Building type does not exist");
        }
        delete building;
    } else {
        std::cout << "You don't have enough resources";
    }
}

void Player::skipTurn(){
    for (unsigned int i = 0; i < m_resources.size(); i++){
        m_resources.at(i) += m_profitResources.at(i);
    }
   m_turn++;
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

void Player:: loadTurn(int count){
    m_turn = count;
}
