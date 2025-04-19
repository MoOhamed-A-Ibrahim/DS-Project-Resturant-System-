#pragma once
#include <iostream>
#include "string.h"
#include "Node.h"
using namespace std;

template <typename T>
class Order : Node<T>
{
public:
	Order(string n, double p, int rt, int s);
	~Order() {};
	void setNext(Order* N);
	void setPrice(double p);
	Order* getNext() const;
	double getPrice() const;
	string getType() const;
	int getSize() const;
	void setRT(int rt);
	int getRT() const;
	void setSize(int s);

private:
	double price = 0;
	string Type = "";
	Order* Next = NULL;
	int RT;
	int Size;
};

