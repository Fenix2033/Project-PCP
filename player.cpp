#include "player.h"

Player::Player()
{

}

int Player::getResources(int index){
    return m_resources.at(index);
}

void Player::setResources(int index, int count){
    m_resources.at(index) = count;
}



