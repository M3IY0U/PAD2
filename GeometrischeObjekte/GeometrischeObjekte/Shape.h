#pragma once
class Shape
{

public:
	Shape();
	virtual ~Shape();
	virtual double getCircumference() = 0;
	virtual double getArea() = 0;

	virtual double operator-(Shape&) =0;// {
	//	return this->getArea() - a.getArea();
	//}
};