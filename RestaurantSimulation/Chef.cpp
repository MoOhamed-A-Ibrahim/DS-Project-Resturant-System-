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
	if (injured) return CookSpeed / 2;
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

void Chef::setInjured(bool state)
{
	injured = state;
}

bool Chef::getInjured() const
{
	return injured;
}

void Chef::restoreSpeed()
{
	CookSpeed *= 2;
}

int Chef::getBreakDuration(int currentTime)
{
	return currentTime + BD;
}

void Chef::putInBreak(bool state)
{
	inBreak = state;
}

bool Chef::needsBreak(int currentTime)
{
	
	return currentTime == BD;
}
