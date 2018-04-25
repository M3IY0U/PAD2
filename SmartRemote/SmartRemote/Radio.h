#pragma once
#include "GeneralDevice.h"

class Radio:public GeneralDevice
{
	//friend std::ostream& operator<<(std::ostream& out, const Radio& r);

public:
	Radio(std::string dn,double v);
	~Radio();
	virtual Radio& operator++() override;
	virtual Radio& operator--() override;
	virtual std::ostream& toString(std::ostream&) const override;
private:
	double volume;
};
