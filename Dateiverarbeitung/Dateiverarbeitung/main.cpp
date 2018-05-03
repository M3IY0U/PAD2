#include <fstream>
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

int main() {
	//Desktop
	ifstream is("E:/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta");
	//Laptop
	//ifstream is("C:/Users/Timo/Documents/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios_base::in);
	Table test;
	test.read(is);
	cout << test.toString();
	test.sort();
	cout << endl << test.toString();
	cin.ignore();
}