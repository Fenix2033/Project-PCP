#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <QString>

class Building
{
private:
int m_type;
int m_priceMoney;
int m_priceResource;
int m_profit;

public:
    Building();
    int getType();
    void setType(int type);
};

#endif // BUILDING_H
