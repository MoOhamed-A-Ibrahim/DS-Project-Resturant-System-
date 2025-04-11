#pragma once
#include <iostream>
#include "string.h"
using namespace std;

class Node
{
public:
	Node(double p, string n)
	{
		Name = n;
		price = p;
	}
	~Node() {};
	void setNext(Node* N)
	{
		Next = N;
	}
	void setPrice(double p)
	{
		price = p;
	}
	Node* getNext() const
	{
		return Next;
	}
	double getPrice() const
	{
		return price;
	}
	string getName() const
	{
		return Name;
	}
private:
	double price = 0;
	string Name = "";
	Node* Next = NULL;
};

