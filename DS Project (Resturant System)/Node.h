#pragma once
#include <iostream>
#include "string.h"
using namespace std;

class Node
{
public:
	Node(double p, string n, int rt, int s)
	{
		Name = n;
		price = p;
		RT = rt;
		Size = s;
	}
	~Node() {};
	void setNext(Node* N);
	void setPrice(double p);
	Node* getNext() const;
	double getPrice() const;
	string getName() const;
	int getSize() const;
	void setRT(int rt);
	int getRT() const;
	void setSize(int s);

private:
	double price = 0;
	string Name = "";
	Node* Next = NULL;
	int RT;
	int Size
};

