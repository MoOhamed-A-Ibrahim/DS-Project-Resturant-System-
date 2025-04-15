#include "WaitingVIP.h"

WaitingVIP::WaitingVIP(int t, double p, int s = 0)
{
    type = t;
    price = p;
    Size = s;
}

int WaitingVIP::getType() const
{
    return type;
}

void WaitingVIP::setType(int t)
{
    type = t;
}

bool WaitingVIP::isAvailable()
{
    return available;
}

int WaitingVIP::getCount() const
{
    return Count;
}

void WaitingVIP::setCount(int c)
{
    Count = c;
}


void WaitingVIP::Assign(double P, string S, int size)
{
}

Node* WaitingVIP::Serve()
{
    if (front)
    {
        Node* TopOfLine = front;
        front->setNext(front->getNext());
        Count--;
        return TopOfLine;
    }
}

