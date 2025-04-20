#pragma once
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Order.h"
#include "Chef.h"
#include <fstream>

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

	// Use All functions to run the game //
	void Run()
	{

	}

	// Read Line From File // 
	void ReadFromFile(const string& FileName)
	{
		ifstream inputFile(FileName);


	}


	// Assign Waiting Orders Loaded From File to Waiting Lists//
	void ASSignWaiting(string Name, double Price, int Size)
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


	void PutInService() {}


private:

	int CurrentTime;
	int VIPcooks;
	int NormalCooks;
	int VeganCooks;

	///  Orders Lists ///

	LinkedQueue<Order*> AllOrdersList;
	LinkedQueue<Order*> WaitingVegan;
	LinkedQueue<Order*> WaitingNormal;
	LinkedQueue<Order*> DeliveredOrders;
	priQueue<Order*> WaitingVIP;
	priQueue<Order*> InserviceOrders;

	//// Cooks Lists ///

	LinkedQueue<Chef*> ReadyVIP;
	LinkedQueue<Chef*> ReadyVegan;
	LinkedQueue<Chef*> ReadyNormal;
};
