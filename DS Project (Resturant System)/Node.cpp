#include "Node.h"

void Node::setNext(Node* N)
{
    Next = N;
}

void Node::setPrice(double p)
{
    price = p;
}

Node* Node::getNext() const
{
    return Next;
}

double Node::getPrice() const
{
    return price;
}

string Node::getName() const
{
    return Name;
}

int Node::getSize() const
{
    return Size;
}

void Node::setRT(int rt)
{
    RT = rt;
}

int Node::getRT() const
{
    return RT;
}

void Node::setSize(int s)
{
    Size = s
}
