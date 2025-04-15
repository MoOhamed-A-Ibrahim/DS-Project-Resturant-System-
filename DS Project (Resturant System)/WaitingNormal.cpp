#include "WaitingNormal.h"


WaitingNormal::WaitingNormal(int t = 1, double p = 0)
{
    type = 1; 
    price = p;
}
int WaitingNormal::getType() const
{
    return 1;
}

void WaitingNormal::setType(int t)
{
    type = 1;
}

bool WaitingNormal::isAvailable()
{
    return available;
}

int WaitingNormal::getCount() const
{
    return Count;
}

void WaitingNormal::setCount(int c)
{
    Count = c;
}

void WaitingNormal::setRT(int rt)
{
	RT = rt;
}

int WaitingNormal::getRT() const
{
	return RT;
}

void WaitingNormal::Assign(double P, string S)
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

Node* WaitingNormal::Serve()
{
	if (front)
	{
		Node* TopOfLine = front;
		front->setNext(front->getNext());
		Count--;
		return TopOfLine;
	}
}
