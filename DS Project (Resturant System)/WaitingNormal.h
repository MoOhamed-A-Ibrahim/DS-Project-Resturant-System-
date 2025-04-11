#pragma once
#include "Order.h"
#include "Node.h"

class WaitingNormal : Order
{
	int type=1;								
	bool available;
	int Count = 0;
	Node* front = NULL;
	Node* rear = NULL;

public:
	WaitingNormal(int t = 1, double p = 0);
	virtual int getType() const override;
	virtual void setType(int t) override;
	virtual bool isAvailable() override;
	int getCount() const;
	void setCount(int c);

	// Queue Operations
	
	void Assign(double P, string S); // Enquqe Operation

	Node* Serve();            //Dequeue Operation
};

