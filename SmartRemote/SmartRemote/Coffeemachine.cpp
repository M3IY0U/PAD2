#include "Coffeemachine.h"

CoffeeMachine::CoffeeMachine(std::string deviceName, unsigned int numberOfCups) :GeneralDevice(deviceName), numberOfCups(numberOfCups)
{
	std::cout << deviceName << " created!" << std::endl;
}

CoffeeMachine::~CoffeeMachine()
{
	std::cout << deviceName << " destroyed!" << std::endl;
}

CoffeeMachine& CoffeeMachine::operator++()
{
	numberOfCups++;
	return *this;
}



CoffeeMachine& CoffeeMachine::operator--()
{
	if (numberOfCups <= 0) {
		std::cout << std::endl << "Number of Cups kann nicht negativ werden!" << std::endl;
		return *this;
	}
	numberOfCups--;
	return *this;
}



std::ostream& CoffeeMachine::toString(std::ostream& out) const {
	std::stringstream ss;
	ss << deviceName << "\nNumber of Cups: " << numberOfCups;
	return out << ss.str();
}
/*
std::ostream & operator<<(std::ostream & out, const CoffeeMachine & c)
{
	return c.toString(out);
}
*/