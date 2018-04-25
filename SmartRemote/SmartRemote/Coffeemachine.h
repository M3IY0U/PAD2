#pragma once
#include "GeneralDevice.h"

class CoffeeMachine:public GeneralDevice
{
	//friend std::ostream& operator<<(std::ostream& out, const CoffeeMachine& c);

public:
	CoffeeMachine(std::string deviceName, unsigned int numberOfCups);
	~CoffeeMachine();
	virtual CoffeeMachine& operator++() override;
	virtual CoffeeMachine& operator--() override;
	virtual std::ostream& toString(std::ostream&) const override;
private:
	unsigned int numberOfCups;
};
