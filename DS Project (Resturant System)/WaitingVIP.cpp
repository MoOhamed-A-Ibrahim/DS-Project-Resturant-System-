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

double WaitingVIP::CalcPripority(double price, int size, int TR)
{
    double priority;

    // Assuming 50 orders at a time, The RT advantage given to an order is equal to 
    //  (50/RT) *10
    // assuming price range from 100 EGP to 4500 EGP, The price advantage equals
    // (price / 4500) * 10
    // Size Could be translated into price

    price = price * size;
    priority = (price / 4500) * 10 + (50 / TR) * 10;
    return priority;
    
}


void WaitingVIP::Assign(double P, string S, int size, int TR)
{
    double score = CalcPripority(P, size, TR);

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

