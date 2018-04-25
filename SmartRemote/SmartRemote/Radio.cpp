#include "Radio.h"

Radio::Radio(std::string dn, double v) :GeneralDevice(dn), volume(v)
{
	std::cout << deviceName << " created!" << std::endl;
}

Radio::~Radio()
{
	std::cout << deviceName << " destroyed!" << std::endl;
}

std::ostream& Radio::toString(std::ostream& out) const
{
	std::stringstream ss;
	ss << deviceName << "\nVolume: " << volume;
	return out << ss.str();
}


Radio& Radio::operator++()
{
	volume++;
	return *this;
}



Radio& Radio::operator--()
{
	if (volume <= 0) {
		std::cout << std::endl << "Lautstärke kann nicht negativ werden!" << std::endl;
		return *this;
	}
	volume--;
	return *this;
}
/*
std::ostream & operator<<(std::ostream & out, const Radio & r)
{
	return r.toString(out);
}
*/