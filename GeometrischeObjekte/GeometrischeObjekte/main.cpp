#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Circle circle1(30);
	Rectangle rect1(60, 20);
	Square sq1(30);
	cout << "Kreis Fläche: " << circle1.getArea() << endl << "Square Umfang: " << circle1.getCircumference() << endl;
	cout << "Rect Fläche: " << rect1.getArea() << endl << "Rect Umfang: " << rect1.getCircumference() << endl;
	cout << "Square Fläche: " << sq1.getArea() << endl << "Square Umfang: " << sq1.getCircumference() << endl;
	cout << endl << "Differenz Kreis-Rect: " << endl << circle1 - rect1 << endl;
	cout << endl << "Differenz Kreis-Square: " << endl << circle1 - sq1 << endl;
	cout << endl << "Differenz Square-Rect: " << endl << sq1 - rect1 << endl;

}