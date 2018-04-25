#pragma once
#include<string>
#include <iostream>
#include <sstream>

class GeneralDevice
{

	friend std::ostream& operator<<(std::ostream& out, const GeneralDevice& gd);

public:
	GeneralDevice(std::string dn);
	virtual ~GeneralDevice();
	virtual GeneralDevice& operator++() = 0;//prefix ++
	virtual GeneralDevice& operator--()=0;//prefix --
	std::string getDeviceName() const { return deviceName; };
	virtual std::ostream& toString(std::ostream&) const=0;
protected:
	std::string deviceName;
};