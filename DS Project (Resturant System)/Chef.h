#pragma once

#include <iostream>
#include <string>
using namespace std;


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
