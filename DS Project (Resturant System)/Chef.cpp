#include "Chef.h"
#include <ostream>
using namespace std;
ostream& operator<<(ostream& os, const Chef& chef) {
	os <<  chef.getID()<< " ";
	return os;
}

Type Chef::getType()const
{

	return CookType;
}

int Chef::getID() const
{
	return ID;
}

int Chef::getSpeed() const
{
	return CookSpeed;
}

int Chef::getRT() const
{
	return RT;
}

int Chef::getBD() const
{
	return BD;
}

bool Chef::getInjured() const
{
	return injured;
}
