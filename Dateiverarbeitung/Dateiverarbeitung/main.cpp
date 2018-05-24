#include <fstream>
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

int main() {
	Table test;

	//Desktop
	//ifstream is("E:/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios::in | ios::binary);
	//Laptop
	ifstream is("C:/Users/Timo/Documents/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios_base::in);

	test.read(is);
	is.close();
	cout << test.toString();
	test.sort();
	cout << endl << test.toString();
	cin.ignore();
	ofstream os("output.txt", ios::out);
	os << test.toString() << endl;
	//test.write(os);
	os.close();
}