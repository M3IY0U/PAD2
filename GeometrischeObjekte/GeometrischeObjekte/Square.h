#pragma once
#include "Rectangle.h"

class Square :public Rectangle
{
public:
	Square(double l);
	virtual ~Square();
	virtual double getCircumference() override;
	virtual double getArea() override;
	virtual double operator-(Shape& a) override;
private:
	double length;
};
