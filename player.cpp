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

void Player::setResources(int index, int count){
    m_resources.at(index) += count;
}

void Player::setTurn(int count){
    m_turn += count;
}


void Player::setProfitResources(int index, int count){
    m_profitResources.at(index) += count;
}

void Player::addTurn(){
    m_turn++;
}
