#pragma once
#include <string>
using namespace std;

class Order
{
private:
	int type;					//Type of the order (1:Normal 2:Vegan 3:VIP)
	double price;				//Price
	bool available;				//Indicates weather the order is available or not
public:
	Order(int t = 1, double p = 0);
	virtual int getType() const;
	virtual double getPrice() const;
	virtual void setPrice(double p);
	virtual void setType(int t);
};

