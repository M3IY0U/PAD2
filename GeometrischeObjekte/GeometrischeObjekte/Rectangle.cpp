#include "Rectangle.h"

Rectangle::Rectangle(double l, double w) :Shape(), width(w), length(l) {

}

Rectangle::~Rectangle() {

}

double Rectangle::getArea() {
	return width * length;
}

double Rectangle::getCircumference() {
	return (2 * width) + (2 * length);
}

double Rectangle::operator-(Shape & a)
{
	if (this->getArea() < a.getArea()) {
		return a.getArea() - this->getArea();
	}
	return this->getArea() - a.getArea();
}
