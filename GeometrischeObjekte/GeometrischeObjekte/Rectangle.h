#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double l, double w);
	virtual ~Rectangle();
	virtual double getArea() override;
	virtual double getCircumference() override;
	virtual double operator-(Shape& a) override;
private:
	double length;
	double width;
};
