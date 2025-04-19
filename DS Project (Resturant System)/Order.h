#pragma once
#include <iostream>
#include "string.h"

using namespace std;

enum Type
{
	Normal=1, Vegan=2, VIP=3
};
class Order 
{
public:
	Order(string n, double p, int rt, int s) 
	{
		OrderType = stringToOrderType(n);
		price = p;
		RT = rt;
		Size = s;


		///Priority Setting///
		if (OrderType == 3)
		{
			Priority = ((price / 1500) * 100 + (Size / 10) * 100 + WT); // Assuming Price range of 1500 EGP, Size of maximum 10 Orders
		}
	}
	~Order() {};
	void setPrice(double p)
	{
		price = p;
	}
	double getPrice() const
	{
		return price;
	}
	int getType() const
	{
		return OrderType;
	}
	int getSize() const
	{
		return Size;
	}
	void setRT(int rt) 
	{
		RT = rt;
	}
	int getRT() const
	{
		return RT;
	}
	void setWT(int currentTime)
	{
		WT = (currentTime - RT);
	}
	int getWT() const 
	{
		return WT;
	}
	void setSize(int s)
	{
		Size = s;
	}
	Type stringToOrderType(const string& str) {
		if (str == "Normal") return Normal;
		else if (str == "Vegan") return Vegan;
		else if (str == "VIP") return VIP;
		else return;
	}

private:
	double price = 0;
	Type OrderType;
	int RT;
	int WT;
	int Size;
	double Priority;
};

