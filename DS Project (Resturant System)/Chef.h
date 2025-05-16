#pragma once

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;



class Chef
{
public:
    Chef(int id, string T, int s, int rt, int bd)
    {
        ID = id;
        CookType = stringToOrderType(T);
        CookSpeed = s;
        RT = rt;
        BD = bd;
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
    int getBD() const;
    bool getInjured() const;
private:
    int ID;
    int CookSpeed;
    Type CookType;
    int RT;
    int BD;
    bool injured = false;
};