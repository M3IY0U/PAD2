#include <fstream>
#include <iostream>
#include <string>
#include "Team.h"

using namespace std;

int main() {
	ifstream is("C:/Users/Timo/Documents/Programming/Git/PAD2/Dateiverarbeitung/Dateiverarbeitung/tabletennis.dta", ios_base::in);
	Team test;
	test.read(is);
	cout << test.toString();
	cin.ignore();
}