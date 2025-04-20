#pragma once
#include <iostream>
#include "string.h"
#include <ostream>
using namespace std;

class Chef;
enum Type
{
	Normal=1, Vegan=2, VIP=3
};
class Order 
{
public:
	Order(string n, double p, int rt, int s,int ID) 
	{
		OrderType = stringToOrderType(n);
		price = p;
		RT = rt;
		Size = s;
		id = ID;

		///Priority Setting///
		if (OrderType == 3)
		{


			Priority = ((price / 1500) * 100 + (Size / static_cast<double>(10)) * 100 - RT); // Assuming Price range of 1500 EGP, Size of maximum 10 Dishes

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
	void setST(int ft)
	{
		ST = ft;
	}
	int getST() const
	{
		return ST;
	}
	int getFT() const
	{
		return FT;
	}
	void setID(int ID)
	{
		id = ID;
	}
	int getID() const
	{
		return id;
	}
	void setAT(int currentTime)
	{
		AT = currentTime;
	}
	int getAT()
	{
		return AT;
	}
	void calcWT() {
		WT = AT - RT;
	}
	void calcFT() {
		FT = RT + WT + ST;
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
		if (str == "G") return Vegan;
		else if (str == "V") return VIP;
		else return Normal;
	}
	double getPriority() const
	{
		return Priority;
	}
	friend ostream& operator<<(ostream& os, const Order& order);
	void setAssignedChef(Chef* chef) {
		AssignedChef = chef;
	}

	Chef* getAssignedChef() const {
		return AssignedChef;
	}


private:
	double price = 0;
	Type OrderType;
	int RT;
	int id;
	int WT=0;
	int FT=0;
	int AT;
	int ST;
	int Size;
	double Priority;
	Chef* AssignedChef = nullptr;

};


