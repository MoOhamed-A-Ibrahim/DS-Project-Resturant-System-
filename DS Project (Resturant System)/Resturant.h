#pragma once
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Order.h"
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h> 
#include "Chef.h"
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
		cout << "Choose one of the following modes: \n(1) Silent Mode\n(2) Interactive Mode\nYour choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Simulation started in Silent Mode";
			// Call function to output file
			cout << "Simulation ended, Output file is created";
		}
		else if (choice == 2) {
			for (int i = 0; i <= 100; i++) {
				CurrentTime = i;
				cout << "Current Timestep: " << i << "\n========================= Available Orders =========================\n";
				cout << WaitingNormal.numberOfElements(CurrentTime) << " NRM orders:\n";
				WaitingNormal.printQueueRTBased(CurrentTime);
				cout << WaitingVegan.numberOfElements(CurrentTime) << " VGN orders:\n";
				WaitingVegan.printQueueRTBased(CurrentTime);
				cout << WaitingVIP.numberOfElements(CurrentTime) << " VGN orders:\n";
				WaitingVIP.printQueueRTBased(CurrentTime);
				cout <<  "\n========================= Available Cooks =========================\n";
				cout << N << " NRM cooks: ";
				ReadyNormal.printQueue();
				cout << endl;
				cout << G << " VGN cooks: ";
				ReadyVegan.printQueue();
				cout << endl;
				cout << V << " VIP cooks: ";
				ReadyVIP.printQueue();
				cout << "\nPress any key to continue...\n";
				_getch();
			}
			
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
		for (int i = 1; i <= N;i++) {
			Chef* c = new Chef(i, "Normal", SN);
			ReadyNormal.enqueue(c);
		}
		for (int i = 1; i <= G;i++) {
			Chef* c = new Chef(i, "Vegan", SN);
			ReadyVegan.enqueue(c);
		}
		for (int i = 1; i <= V;i++) {
			Chef* c = new Chef(i, "VIP", SN);
			ReadyVIP.enqueue(c);
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
			iss >> Name >> CurrentTime >> id >>  size >> price ;
			ASSign(Name, price, size, id);			
		}
	}
	void ASSign(string Name, double Price, int Size,int ID)
	{
		Order* NewOrder = new Order(Name, Price, CurrentTime, Size,ID);
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
	LinkedQueue<Chef*> ReadyVIP;
	LinkedQueue<Chef*> ReadyVegan;
	LinkedQueue<Chef*> ReadyNormal;
};
