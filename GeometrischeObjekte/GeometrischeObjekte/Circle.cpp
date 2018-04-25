#define _USE_MATH_DEFINES

#include "Circle.h"
#include <cmath>


Circle::Circle(double radius) :Shape(), radius(radius)
{
}

Circle::~Circle()
{
}

double Circle::getArea() {
	return M_PI * std::pow(radius, 2);
}

double Circle::operator-(Shape & a)
{
	if (this->getArea() < a.getArea()) {
		return a.getArea() - this->getArea();
	}
	return this->getArea() - a.getArea();
}


double Circle::getCircumference() {
	return 2 * M_PI * radius;
}
