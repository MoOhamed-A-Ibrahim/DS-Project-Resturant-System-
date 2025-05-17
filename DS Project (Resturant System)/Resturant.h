#pragma once
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Order.h"
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h> 
#include <algorithm>
#include <vector>
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
	void Run() 
	{
		ReadFromFile();
		int choice;
		cout << "================== Welcome The Resturant Simulation ==================\n";
		cout << "Choose one of the following modes: \n(1) Silent Mode\n(2) Interactive Mode\nYour choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Simulation started in Silent Mode";
			// Call function to output file
			for (int i = 0; i <= 10000; i++) {
				CurrentTime = i;
				ReturnFinishedCooks();
				PutInService();
			}
			runSilentMode();
			cout << "Simulation ended, Output file is created";
		}
		else if (choice == 2) {
			for (int i = 0; i <= 10000; i++) {
				CurrentTime = i;
				ReturnFinishedCooks();
				cout << "===========================================================================\n";
				cout << "Current Timestep: " << i << "\n========================= Available Orders =========================\n";
				cout << WaitingNormal.numberOfElements(CurrentTime) << " NRM orders:\n";
				WaitingNormal.printQueueRTBased(CurrentTime);
				cout << WaitingVegan.numberOfElements(CurrentTime) << " VGN orders:\n";
				WaitingVegan.printQueueRTBased(CurrentTime);
				cout << WaitingVIP.numberOfElements(CurrentTime) << " VIP orders:\n";
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
				
				PutInService();
				cout << "\n=========================  In Service  =========================\n";
				InserviceOrders.printQueue();
				cout << "\n=========================  Delivered Orders =========================\n";
				DeliveredOrders.printQueue();
				cout << "\n\n\nPress any key to continue...\n";
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
			int size, id, Rt;
			iss >> Name >> Rt >> id >>  size >> price ;
			ASSign(Name, price, Rt,size, id);			
		}
	}
	void ASSign(string Name, double Price, int RT,int Size,int ID)
	{
		Order* NewOrder = new Order(Name, Price, RT, Size,ID);
		int type = NewOrder->stringToOrderType(Name);
		AllOrdersList.enqueue(NewOrder);
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
	void runSilentMode() {
		ofstream outFile("Output.txt");
		if (!outFile) {
			cerr << "Error opening output file.\n";
			return;
		}

		vector<Order*> orders;
		Order* o;

		while (!DeliveredOrders.isEmpty()) {
			DeliveredOrders.dequeue(o);
			orders.push_back(o);
		}

		sort(orders.begin(), orders.end(), [](Order* a, Order* b) {
			return a->getFT() > b->getFT();
			});

		outFile << "FT\tID\tAT\tWT\tST\n";
		double totalWT = 0, totalST = 0;
		int countNormal = 0, countVegan = 0, countVIP = 0;

		for (Order* ord : orders) {
			int FT = ord->getFT();
			int ID = ord->getID();
			int RT = ord->getAT();
			int ST = ord->getST();
			int WT = ord->getWT();
			int ST_duration = FT - ST;

			outFile << FT << "\t" << ID << "\t" << RT << "\t" << WT << "\t" << ST_duration << "\n";

			totalWT += WT;
			totalST += ST_duration;

			switch (ord->getType()) {
			case Normal: countNormal++; break;
			case Vegan: countVegan++; break;
			case VIP: countVIP++; break;
			}
		}

		int totalOrders = orders.size();
		outFile << "\n\n====================================================\n";
		outFile << "Orders: " << totalOrders << " [Normal: " << countNormal << ", Vegan: " << countVegan << ", VIP: " << countVIP << "]\n";
		outFile << "Cooks: " << (N + G + V) << " [Normal: " << N << ", Vegan: " << G << ", VIP: " << V << "]\n";
		outFile << "Avg Wait = " << (totalOrders ? totalWT / totalOrders : 0) << "\n";
		outFile << "Avg Serv = " << (totalOrders ? totalST / totalOrders : 0) << "\n";
		outFile << "====================================================\n";

		outFile.close();
	}

	void PutInService()
	{
		while (!WaitingVIP.isEmpty())
		{
			Order* vipOrder;
			int pri;
			if (!WaitingVIP.peek(vipOrder,pri)) break;

			if (vipOrder->getRT() > CurrentTime) break;

			Chef* cook = nullptr;

			
			if (!ReadyVIP.isEmpty())
			{
				ReadyVIP.dequeue(cook);
				
			}
			else if (!ReadyNormal.isEmpty())
			{
				ReadyNormal.dequeue(cook);
				
			}
			else if (!ReadyVegan.isEmpty())
			{
				ReadyVegan.dequeue(cook);
				
			}

			if (cook)
			{
				WaitingVIP.dequeue(vipOrder, pri);
				int duration = static_cast<int>(ceil((double)vipOrder->getSize() / cook->getSpeed()));
				int seriveTime = CurrentTime + duration;
				vipOrder->setAT(CurrentTime);
				vipOrder->calcWT();
				vipOrder->setST(seriveTime);
				vipOrder->calcFT();
				vipOrder->setAssignedChef(cook);
				int pri = vipOrder->getPriority();
				InserviceOrders.enqueue(vipOrder, pri);
				
				BusyChefs.enqueue(cook);
				if(V!= 0 ) V--;
			}
			else break;
		}

		// --- Handle Vegan Orders ---
		while (!WaitingVegan.isEmpty())
		{
			Order* veganOrder;
			if (!WaitingVegan.peek(veganOrder)) break;

			if (veganOrder->getRT() > CurrentTime) break;

			Chef* cook = nullptr;

			if (!ReadyVegan.isEmpty())
				ReadyVegan.dequeue(cook);

			if (cook)
			{
				WaitingVegan.dequeue(veganOrder);

				int duration = static_cast<int>(ceil((double)veganOrder->getSize() / cook->getSpeed()));
				int seriveTime = CurrentTime + duration;
				veganOrder->setAT(CurrentTime);

				veganOrder->calcWT();
				veganOrder->setST(seriveTime);
				veganOrder->calcFT();
				veganOrder->setAssignedChef(cook);
				int pri = veganOrder->getPriority();
				InserviceOrders.enqueue(veganOrder, pri);

				BusyChefs.enqueue(cook);
				if(G !=0) G--;
			}
			else break;
		}

		// --- Handle Normal Orders ---
		while (!WaitingNormal.isEmpty())
		{
			Order* normalOrder;
			if (!WaitingNormal.peek(normalOrder)) break;

			if (normalOrder->getRT() > CurrentTime) break;

			Chef* cook = nullptr;

			
			if (!ReadyNormal.isEmpty())
				ReadyNormal.dequeue(cook);
			else if (!ReadyVIP.isEmpty())
				ReadyVIP.dequeue(cook);

			if (cook)
			{
				WaitingNormal.dequeue(normalOrder);

				int duration = static_cast<int>(ceil((double)normalOrder->getSize() / cook->getSpeed()));
				int seriveTime = CurrentTime + duration;
				normalOrder->setAT(CurrentTime);
				normalOrder->calcWT();
				normalOrder->setST(seriveTime);
				normalOrder->calcFT();
				normalOrder->setAssignedChef(cook);
				int pri = normalOrder->getPriority();
				InserviceOrders.enqueue(normalOrder, pri);

				BusyChefs.enqueue(cook);
				if(N != 0) N--;
			}
			else break;
		}
	}
	void ReturnFinishedCooks()
	{
		priQueue<Order*> tempQueue;
		Order* finishedOrder;
		int pri;

		while (!InserviceOrders.isEmpty())
		{
			InserviceOrders.dequeue(finishedOrder, pri);

			if (finishedOrder->getFT() == CurrentTime)
			{

				Chef* returnedCook = finishedOrder->getAssignedChef();

				if (returnedCook)
				{
					Type type = returnedCook->getType();

					if (type == Normal)
					{
						ReadyNormal.enqueue(returnedCook);
						N++;
					}
					else if (type == Vegan)
					{
						ReadyVegan.enqueue(returnedCook);
						G++;
					}
					else if (type == VIP)
					{
						ReadyVIP.enqueue(returnedCook);
						V++;
					}
				}

				DeliveredOrders.enqueue(finishedOrder);
			}
			else
			{
				tempQueue.enqueue(finishedOrder, pri);
			}
		}

		Order* order;
		
		while (!tempQueue.isEmpty())
		{
			tempQueue.dequeue(order, pri);
			InserviceOrders.enqueue(order, pri);
		}
	}




private:

	int CurrentTime;
	int N=0, G=0, V=0, SN=0, SV=0, SG=0, M=0;
	///  Orders Lists ///

	LinkedQueue<Order*> AllOrdersList; // done
	LinkedQueue<Order*> WaitingVegan; // done
	LinkedQueue<Order*> WaitingNormal; // done
	LinkedQueue<Order*> DeliveredOrders; //done
	priQueue<Order*> WaitingVIP; // done
	priQueue<Order*> InserviceOrders; //done

	//// Cooks Lists ///
	LinkedQueue<Chef*> ReadyVIP; // done
	LinkedQueue<Chef*> ReadyVegan; // done
	LinkedQueue<Chef*> ReadyNormal; // done
	LinkedQueue<Chef*> BusyChefs; // done
};
