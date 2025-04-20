#pragma once
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Order.h"
#include <fstream>
#include <sstream>
#include <string>

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
	void Run() {
		ReadFromFile();
		int choice;
		cout << "================== Welcome The Resturant Simulation ==================\n";
		cout << "Choose one of the following modes: \n(1) Silent Mode\n(2) Interactive Mode\n Your choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Simulation started in Silent Mode";
			// Call function to output file
			cout << "Simulation ended, Output file is created";
		}

	}
	void ReadFromFile() {
		ifstream file;
		file.open("Input.txt");
		string line;
		if (getline(file, line)) {
			istringstream iss(line);
			iss >> N >> G>>V;
		}
		if (getline(file, line)) {
			istringstream iss(line);
			iss >> SN >> SG >> SV;
		}
		if (getline(file, line)) {
			istringstream iss(line);
			iss >> M;
		}

		
		
		for (int i = 0; i < M && getline(file, line); ++i) {
			istringstream iss(line);
			string Name;
			double price;
			int size, id;
			int RT;
			iss >> Name >> RT >> id >>  size >> price ;
			ASSign(Name, price, RT,  size, id);			
		}
	}
	void ASSign(string Name, double Price,int RT,  int Size,int ID)
	{
		Order* NewOrder = new Order(Name, Price, RT, Size,ID);
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
	int N=0, G=0, V=0, SN=0, SV=0, SG=0, M=0;
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
