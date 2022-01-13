#include "building.h"

Building::Building(){}

int Building::getType(){
    return m_type;
}

std::array<int, 3> Building::getPrice(){
    return m_price;
}

int Building::getProfit(){
    return m_profit;
}

void Building::setType(int buildingType){
    m_type = buildingType;
    switch (buildingType){
      case 2:
        m_price.at(0) = 200;
        m_price.at(1) = 50;
        m_price.at(2) = 20;
        m_profit = 20;
        break;
      case 3:
        m_price.at(0) = 500;
        m_price.at(1) = 100;
        m_price.at(2) = 75;
        m_profit = 35;
        break;
      case 5:
        m_price.at(0) = 300;
        m_price.at(1) = 30;
        m_price.at(2) = 40;
        m_profit = 5;
        break;
      case 6:
        m_price.at(0) = 700;
        m_price.at(1) = 80;
        m_price.at(2) = 100;
        m_profit = 10;
        break;
      case 8:
        m_price.at(0) = 500;
        m_price.at(1) = 100;
        m_price.at(2) = 20;
        m_profit = 5;
        break;
      case 9:
        m_price.at(0) = 1000;
        m_price.at(1) = 200;
        m_price.at(2) = 50;
        m_profit = 10;
        break;
      case 0:
        m_price.at(0) = 5000;
        m_price.at(1) = 1500;
        m_price.at(2) = 1000;
        break;
      case 1: case 4: case 7: case 10: break;
    default:  throw std::invalid_argument("Building type does not exist");
    }
}

