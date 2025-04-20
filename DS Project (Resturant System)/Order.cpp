#include "Order.h"

ostream& operator<<(ostream& os, const Order& order) {
	if(order.getType() == 3){
		os << "ID:" << order.getID()
			<< ", Type: " << order.getType()
			<< ", RT: " << order.getRT()
			<< ", Price: " << order.getPrice()
			<< ", Size: " << order.getSize()
			<< ", Priority: " << order.getPriority()
			<< endl;
	}
	else {
		os << "ID: " << order.getID()
			<< ", Type: " << order.getType()
			<< ", RT: " << order.getRT()
			<< ", Price: " << order.getPrice()
			<< ", Size: " << order.getSize()
			<< endl;
	}
	return os;
}