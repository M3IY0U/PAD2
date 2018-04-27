#include "Heating.h"
#include "Coffeemachine.h"
#include "Radio.h"
#include <vector>
#include <windows.h>

using namespace std;

void printMenu() {
	cout << endl << "     SmartHouse\n   Remote Control" << endl
		<< "--------------------" << endl
		<< "+ laut/warm/Becher+" << endl
		<< "- leise/kalt/Becher-" << endl
		<< "1 Tchibo KM 3" << endl
		<< "2 Radio Wohnzimmer" << endl
		<< "3 Radio Küche" << endl
		<< "4 Heizung OG" << endl
		<< "5 Heizung EG" << endl
		<< "? Übersicht" << endl
		<< "0 aus" << endl
		<< "--------------------" << endl;

}



int main() {
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<GeneralDevice*> devices;
	devices.push_back(new Radio("Tchibo KM 3", 0));
	devices.push_back(new Radio("Radio Wohnzimmer", 40));
	devices.push_back(new Radio("Radio Küche", 40));
	devices.push_back(new Radio("Heizung OG", 18));
	devices.push_back(new Radio("Heizung EG", 18));




	GeneralDevice* actualDevice = nullptr;

	char input = '?';
	while (input != '0') {
		printMenu();
		if (input != '?') {
			SetConsoleTextAttribute(hConsole, 11);
			if (actualDevice != nullptr) {
				cout << "Momentan ausgewählt: " << *actualDevice << endl;
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
		cin >> input;
		switch (input) {
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			actualDevice = devices[input - '1'];
			break;
		case '+':
			if (actualDevice == nullptr) {
				SetConsoleTextAttribute(hConsole, 4);
				cout << endl << "Kein Gerät ausgew�hlt!" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				break;
			}
			SetConsoleTextAttribute(hConsole, 4);
			++*actualDevice;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		case '-':
			if (actualDevice == nullptr) {
				SetConsoleTextAttribute(hConsole, 4);
				cout << endl << "Kein Gerät ausgew�hlt!" << endl;
				SetConsoleTextAttribute(hConsole, 7);
				break;
			}
			SetConsoleTextAttribute(hConsole, 4);
			--*actualDevice;
			SetConsoleTextAttribute(hConsole, 7);
			break;
		case '?':
			SetConsoleTextAttribute(hConsole, 10);
			for (GeneralDevice* device : devices) {
				cout << *device << endl;
			}
			SetConsoleTextAttribute(hConsole, 7);
			break;
		case '0':
			cout << endl << "Ending Program." << endl << endl;
			for (auto i = 0; i < devices.size();i++) {
				delete devices[i];
			}
			break;
		default:
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Invalid Input!" << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
	}

}