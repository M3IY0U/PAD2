#pragma once
#include "GeneralDevice.h"

class Heating :public GeneralDevice
{
	//friend std::ostream& operator<<(std::ostream& out, const Heating& h);

public:
	Heating(std::string dn, float temp);
	~Heating();
	virtual Heating& operator++() override;
	virtual Heating& operator--() override;
	virtual std::ostream& toString(std::ostream&) const override;
private:
	float temperature;
};
