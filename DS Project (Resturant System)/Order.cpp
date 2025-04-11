#include "Order.h"

Order::Order(int t, double p)
{
	type = t;
	price = p;
	available = true;
}

int Order::getType() const
{
	return type;
}

double Order::getPrice() const
{
	return price;
}

void Order::setPrice(double p)
{
	price = p;
}

void Order::setType(int t)
{
	type = t;
}

bool Order::isAvailable()
{
	return available;
}
