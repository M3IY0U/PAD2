#include <fstream>
#include <iostream>
#include <string>
#include "Table.h"

using namespace std;

int main() {
	Table test;

	//Desktop
	ifstream is("E:/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios_base::in | ios_base::binary);
	//Laptop
	//ifstream is("C:/Users/Timo/Documents/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios_base::in);

	test.read(is);
	is.close();
	cout << test.toString();
	test.sort();
	cout << endl << test.toString();
	cin.ignore();
	ofstream os("output.txt", ios_base::out | ios_base::binary);
	test.write(os);
	os.close();
}