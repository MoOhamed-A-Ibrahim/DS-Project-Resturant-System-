#include "Order.h"

Order::Order(string n, double p, int rt, int s)
{
    Type = n;
    price = p;
    RT = rt;
    Size = s;
}

void Order::setNext(Order* N)
{
    Next = N;
}

void Order::setPrice(double p)
{
    price = p;
}

Order* Order::getNext() const
{
    return Next;
}

double Order::getPrice() const
{
    return price;
}

string Order::getType() const
{
    return Type;
}

int Order::getSize() const
{
    return Size;
}

void Order::setRT(int rt)
{
    RT = rt;
}

int Order::getRT() const
{
    return RT;
}

void Order::setSize(int s)
{
    Size = s
}
