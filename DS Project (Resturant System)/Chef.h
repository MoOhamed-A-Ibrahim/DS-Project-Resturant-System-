#pragma once

#include <iostream>
#include <string>
using namespace std;


enum Type
{
	Normal = 1, Vegan = 2, VIP = 3
};
class Chef
{
public:
	Chef(string T, int s)
	{
		CookType = stringToOrderType(T);
		CookSpeed = s;
	}
	~Chef() {}
	Type stringToOrderType(const string& str)
	{
		if (str == "Normal") return Normal;
		else if (str == "Vegan") return Vegan;
		else if (str == "VIP") return VIP;
	}
private:
	int CookSpeed;
	Type CookType;
};
