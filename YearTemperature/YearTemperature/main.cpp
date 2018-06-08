#include "Year.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void printMenu() {
	cout << "[1] Durchschnittstemperaturen aller Jahre auf Konsole und in Datei ausgeben" << endl
		<< "[2] Kaeltesten und waermsten Monat ausgeben" << endl
		<< "[3] Durchschnittstemperaturen aller Jahreszeiten in Datei ausgeben" << endl
		<< "[4] Prozentsatz der waermsten Jahre ausgeben" << endl

		<< "[9] Programm beenden" << endl
		<< "Ihre Wahl : ";

}


bool cmp(Year& a, Year& b) {
	return a.getAverage() > b.getAverage();
}


bool seasonCmp(pair<string, pair<int, double>>& a, pair<string, pair<int, double>>& b) {
	return a.second.second > b.second.second;

}

int main() {
	setlocale(LC_ALL, "");
	setlocale(LC_NUMERIC, "");
	srand(unsigned(time(nullptr)));

	//START READING IN ///////////////////////////////////////////////
	vector<Year> years;
	vector<string> months = { "Januar","Februar","März","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember" };
	ifstream infile("Temperaturen_1881_2016.txt", ios::in);
	if (!infile) {
		cerr << "File could not be opened!";
	}

	//Ignore first line
	string tmp;
	getline(infile, tmp);


	string yn;
	while (!infile.eof()) {
		getline(infile, yn, '\t');
		Year year(stoi(yn));
		for (auto i = 0; i < 12; i++) {
			string monthTemp;
			if (i == 11) {
				getline(infile, monthTemp, '\n');
			}
			else {
				getline(infile, monthTemp, '\t');
			}
			monthTemp.replace(monthTemp.find(','), 1, ".");
			year.readTemp(months[i], stod(monthTemp));
		}
		year.calcTemps();
		years.push_back(year);
		if (yn == "2016") {
			break;
		}
	}
	//READ IN COMPLETE ///////////////////////////////////////////////

	char input;
	do {
		printMenu();
		cin >> input;
		switch (input) {
		case '1': {
			ofstream output("Durchschnittstemperaturen.txt", ios::out);
			vector<Year> sortedYears = years;
			sort(sortedYears.begin(), sortedYears.end(), cmp);
			for (size_t i = 0; i < years.size(); i++) {
				cout << years[i].printAverage();
				output << sortedYears[i].printAverage();
			}
			output.close();
		}
				  break;
		case '2': {
			Year lowest = years[0];
			Year highest = years[0];
			for (size_t i = 0; i < years.size(); i++) {
				if (years[i].getHighest().second > highest.getHighest().second) {
					highest = years[i];
				}
				if (years[i].getLowest().second < lowest.getLowest().second) {
					lowest = years[i];
				}
			}
			cout << "Kältester Monat: " << lowest.getLowest().first << " " << lowest.getYear() << " mit " << lowest.getLowest().second << " Grad Celsius Durchschnittstemperatur." << endl
				<< "Wärmster Monat: " << highest.getHighest().first << " " << highest.getYear() << " mit " << highest.getHighest().second << " Grad Celsius Durchschnittstemperatur." << endl;

		}
				  break;

		case '3': {
			vector <pair<string, pair<int, double>>> seasonTemp;
			pair<string, pair<int, double>>  toPush;
			ofstream output("Jahreszeiten.txt", ios::out);
			for (size_t i = 0; i < years.size(); i++) {
				toPush.first = "Frühling";
				toPush.second = years[i].getFruehling();
				seasonTemp.push_back(toPush);

				toPush.first = "Sommer";
				toPush.second = years[i].getSommer();
				seasonTemp.push_back(toPush);

				toPush.first = "Herbst";
				toPush.second = years[i].getHerbst();
				seasonTemp.push_back(toPush);

				toPush.first = "Winter";
				toPush.second = years[i].getWinter();
				seasonTemp.push_back(toPush);
			}
			sort(seasonTemp.begin(), seasonTemp.end(), seasonCmp);
			for (size_t i = 0; i < seasonTemp.size(); i++) {
				output << setprecision(2) << seasonTemp[i].first << " " << to_string(seasonTemp[i].second.first) << " mit " << seasonTemp[i].second.second << " Grad Celsius Durchschnittstemperatur" << endl;
				cout << setprecision(2) << seasonTemp[i].first << " " << to_string(seasonTemp[i].second.first) << " mit " << seasonTemp[i].second.second << " Grad Celsius Durchschnittstemperatur" << endl;
			}
			output.close();
		}
				  break;

		case '4': {
			vector<Year> sortedYears = years;
			vector<Year> shuffledYears = years;
			random_shuffle(shuffledYears.begin(), shuffledYears.end());
			sort(sortedYears.rbegin(), sortedYears.rend(), cmp);
			cout << "n " << setw(10) << "Prozentsatz" << setw(20) << "theoretischer Prozentsatz" << endl;
			for (auto n = 5; n < 131; n += 5) {
				double count = 0;
				double scount = 0;
				//SORTED YEARS
				for (auto i = years.size() - 1; i > years.size() - (n + 1); i--) {
					for (auto j = sortedYears.size() - 1; j >= sortedYears.size() - n; j--) {
						if (years[i].getYear() == sortedYears[j].getYear()) {
							count++;
						}
					}
				}
				//SHUFFLED YEARS
				for (auto i = years.size() - 1; i > years.size() - (n + 1); i--) {
					for (auto j = shuffledYears.size() - 1; j >= shuffledYears.size() - n; j--) {
						if (years[i].getYear() == shuffledYears[j].getYear()) {
							scount++;
						}
					}
				}



				cout << setprecision(3) << n << setw(10) << (count * 100) / n << setw(20) << (scount * 100) / n << endl;
			}


		}
				  break;

		case '9':
			break;
		default:
			cerr << "Invalid Input!" << endl;
			break;
		}





	} while (input != '9');



}
