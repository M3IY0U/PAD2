#include "Heating.h"

Heating::Heating(std::string dn, float temp) :GeneralDevice(dn), temperature(temp)
{
	std::cout << deviceName << " created!" << std::endl;
}

Heating::~Heating()
{
	std::cout << deviceName << " destroyed!" << std::endl;
}

std::ostream& Heating::toString(std::ostream& out) const
{
	std::stringstream ss;
	ss << deviceName << "\nTemperature: " << temperature;
	return out << ss.str();
}

Heating& Heating::operator++()
{
	if (temperature >= 25) {
		std::cout << std::endl << "Heizung schon auf maximum!" << std::endl;
		return *this;
	}
	temperature++;
	return *this;
}



Heating& Heating::operator--()
{
	if (temperature <= 0) {
		std::cout << std::endl << "Heizung schon auf minimum!" << std::endl;
		return *this;
	}
	temperature--;
	return *this;
}
/*
std::ostream & operator<<(std::ostream & out, const Heating & h)
{
	return h.toString(out);
}
*/