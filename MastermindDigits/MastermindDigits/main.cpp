#include "MastermindDigits.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
	int choice;
	MastermindDigits md;

	setlocale(LC_ALL, "");
	srand(time(nullptr));
	bool cont = false;;
	while (!cont) {
		cout << "Testen(1) oder Spielen(2): ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Testzahl eingeben: ";
			int testNumber;
			cin >> testNumber;
			md = testNumber;
			cont = true;
			break;
		case 2:
			//md = MastermindDigits();
			md.makeDigitsToGuess();
			cont = true;
			break;

		default:
			cout << "Keine gültige Eingabe!" << endl;

			break;
		}
	}

	int guess;
	auto counter = 1;
	while (true) {

		cout << counter << ". Versuch:" << endl;
		cin >> guess;
		if (guess == 0) {
			break;
		}
		if (guess == 9999) {
			cout << md.showNumber();
		}
		if (md.locationRight(guess) == 4 && choice == 2) {
			cout << "\n\nGewonnen!" << endl;
			break;
		}
		cout << md.locationRight(guess) << " an der richtigen Stelle;" << endl;
		cout << "sonst " << md.locationWrong(guess) << " richtig." << endl;
		counter++;
	}
}