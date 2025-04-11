#include "WaitingVegan.h"

WaitingVegan::WaitingVegan(int t, double p)
{
	type = 2;
	price = p;
}

int WaitingVegan::getType() const
{
	return 2;
}

void WaitingVegan::setType(int t)
{
	type=1
}

bool WaitingVegan::isAvailable()
{
	return available;
}

int WaitingVegan::getCount() const
{
	return Count;
}

void WaitingVegan::setCount(int c)
{
	Count = c;
}

void WaitingVegan::Assign(double P, string S)
{
	if (!front)
	{
		Node* NewNode = new Node(P, S);
		front = rear = NewNode;
		Count++;
	}
	if (front)
	{
		Node* NewNode = new Node(P, S);
		rear = NewNode;
	}
}

Node* WaitingVegan::Serve()
{
	if (front)
	{
		Node* TopOfLine = front;
		front->setNext(front->getNext());
		Count--;
		return TopOfLine;
	}
}
