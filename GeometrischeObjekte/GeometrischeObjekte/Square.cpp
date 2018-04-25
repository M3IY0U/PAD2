#include "Square.h"
#include <cmath>

Square::Square(double l):Rectangle(l,l),length(l)
{
	length = l;
}

Square::~Square() {
	
}


double Square::getCircumference()
{
	return 4*length;
}

double Square::getArea()
{
	return pow(length,2);
}

double Square::operator-(Shape & a)
{
	if (this->getArea()<a.getArea()) {
		return a.getArea() - this->getArea();
	}
	return this->getArea()-a.getArea();
}
