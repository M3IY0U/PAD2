#pragma once
#include "Shape.h"

class Circle : public Shape
{
	public:
	explicit Circle(double radius);
	virtual ~Circle();
	virtual double getCircumference() override;
	virtual double getArea() override;
	virtual double operator-(Shape& a) override;
private:
	double radius;
};
