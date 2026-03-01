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
        else if (str == "S") return Sea;
        else if (str == "F") return Fast;
    }
    Type getType() const;
    int getID() const;
    int getSpeed() const;
    int getRT() const;
    int getBD() const;
    void setInjured(bool state);
    bool getInjured() const;
    void restoreSpeed();
    int getBreakDuration(int currentTime);
    void putInBreak(bool state);
    bool needsBreak(int currentTime);
private:
    int ID;
    int CookSpeed;
    Type CookType;
    int RT;
    int BD;
    bool injured = false;
    bool inBreak = false;
};