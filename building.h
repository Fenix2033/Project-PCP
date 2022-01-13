#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <array>
#include <QString>

class Building
{
private:
int m_type;
std::array<int, 3> m_price;
int m_profit;


public:
    Building();
    int getType();
    std::array<int, 3> getPrice();
    int getProfit();
    void setType(int type);
};

#endif // BUILDING_H
