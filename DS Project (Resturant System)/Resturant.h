#pragma once
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Order.h"

using namespace std;

class Resturant
{
public:
	Resturant()
	{
	}
	~Resturant()
	{

	}
	void Run();
	void ReadFromFile();
	void ASSign(string Name, double Price, int Size)
	{
		Order* NewOrder = new Order(Name, Price, CurrentTime, Size);
		int type = NewOrder->stringToOrderType(Name);
		switch (type)
		{
		case 1:
			WaitingNormal.enqueue(NewOrder);
			break;
		case 2:
			WaitingVegan.enqueue(NewOrder);
			break;
		case 3:
			WaitingVIP.enqueue(NewOrder, NewOrder->getPriority());
			break;
		}

	}

private:

	int CurrentTime;

	///  Orders Lists ///

	LinkedQueue<Order*> AllOrdersList;
	LinkedQueue<Order*> WaitingVegan;
	LinkedQueue<Order*> WaitingNormal;
	LinkedQueue<Order*> DeliveredOrders;
	priQueue<Order*> WaitingVIP;
	priQueue<Order*> InserviceOrders;

	//// Cooks Lists ///

	LinkedQueue<Order*> ReadyVIP;
	LinkedQueue<Order*> ReadyVegan;
	LinkedQueue<Order*> ReadyNormal;
};
