#pragma once

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;


enum Type
{
	Normal = 1, Vegan = 2, VIP = 3
};
class Chef
{
public:
    Chef(int id,string T, int s)
    {
        ID = id;
        CookType = stringToOrderType(T);
        CookSpeed = s;
    }
    friend ostream& operator<<(ostream& os, const Chef& order);
    ~Chef() {}
    Type stringToOrderType(const string& str)
    {
        if (str == "Normal") return Normal;
        else if (str == "Vegan") return Vegan;
        else if (str == "VIP") return VIP;
    }
    Type getType() const;
    int getID() const;
    int getSpeed() const;
    int getRT() const;
private:
    int ID;
    int CookSpeed;
    Type CookType;
};