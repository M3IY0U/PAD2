#include "GeneralDevice.h"

GeneralDevice::GeneralDevice(std::string dn):deviceName(dn)
{
	
}

GeneralDevice::~GeneralDevice()
{
}


std::ostream& operator<<(std::ostream& out, const GeneralDevice& gd)
{
	return gd.toString(out);
}
