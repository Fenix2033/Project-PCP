#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include <QString>

class Building
{
private:
QString m_type;
int m_priceMoney;
int m_priceResource;
int m_profit;

public:
    Building();
    QString getType();
    void setPosition(int x, int y);
};

#endif // BUILDING_H
