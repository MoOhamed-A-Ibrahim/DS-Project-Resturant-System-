#pragma once

#pragma once
#include "Order.h"
#include "Node.h"

class WaitingVIP : Order
{
	int type = 3;
	bool available;
	int Count = 0;
	Node* front = NULL;
	Node* rear = NULL;

public:
	WaitingVIP(int t = 3, double p = 0, int s = 0);
	virtual int getType() const override;
	virtual void setType(int t) override;
	virtual bool isAvailable() override;
	int getCount() const;
	void setCount(int c);
	double CalcPripority(double price, int size, int TR);
	// Queue Operations

	void Assign(double P, string S, int size, int TR); // Enquqe Operation

	Node* Serve();            //Dequeue Operation
};


