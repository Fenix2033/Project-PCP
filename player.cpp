#include "player.h"

Player::Player()
{

}

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
    Building *building = new Building;
    if (checkResources(buildingType) == true){
        building->setType(buildingType);
        skipTurn();
        m_resources.at(0) -= building->getPrice().at(0);
        m_resources.at(1) -= building->getPrice().at(1);
        m_resources.at(2) -= building->getPrice().at(2);
        if (buildingType == 2){
            m_profitResources.at(0) += building->getProfit();
        } else if (buildingType == 5){
            m_profitResources.at(1) += building->getProfit();
        } else if (buildingType == 8){
            m_profitResources.at(2) += building->getProfit();
        } else if (buildingType == 3){
            m_profitResources.at(0) += -5 + building->getProfit();
        } else if (buildingType == 6){
            m_profitResources.at(1) += -5 + building->getProfit();
        } else if (buildingType == 9){
            m_profitResources.at(2) += -5 + building->getProfit();
        }
    }
    delete building;
}

void Player::setTurn(int count){
    m_turn += count;
}

void Player::skipTurn(){
    for (unsigned int i = 0; i < 3; i++){
        m_resources.at(i) += m_profitResources.at(i);
    }
   m_turn++;
}


bool Player::checkResources(int buildingType){
    Building *building = new Building;
    building->setType(buildingType);
    if (m_resources.at(0) >= building->getPrice().at(0) and
            m_resources.at(1) >= building->getPrice().at(1) and
            m_resources.at(2) >= building->getPrice().at(2)){
        delete building;
        return true;
    } else {
        delete building;
        return false;
    }

}

void Player::loadResources(int index, int resourceCount){
    m_resources.at(index) = resourceCount;
}

void Player::loadResourcesProfit(int index, int resourceCount){
    m_profitResources.at(index) = resourceCount;
}
