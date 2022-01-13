#include "building.h"

Building::Building()
{

}

int Building::getType(){
    return m_type;
}


void Building::setType(int buildingType){
    m_type = buildingType;
    if (buildingType == 2){
        m_price.at(0) = 200;
        m_price.at(1) = 50;
        m_price.at(2) = 20;
        m_profit = 20;
    } else if (buildingType == 5) {
        m_price.at(0) = 300;
        m_price.at(1) = 30;
        m_price.at(2) = 40;
        m_profit = 5;
    }
}

std::array<int, 3> Building::getPrice(){
    return m_price;
}

int Building::getProfit(){
    return m_profit;
}
