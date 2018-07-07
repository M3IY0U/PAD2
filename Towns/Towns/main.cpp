#include "Town.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;


bool viercmp(Town& a, Town& b) { return a.getPopulation() > b.getPopulation(); }
bool cmp(Town& a, Town& b) { if (a.getLand() == b.getLand()) { return a.getName() < b.getName(); } return a.getLand() < b.getLand(); }
bool popcmp(Town& a, Town& b) { if (a.getLand() == b.getLand()) { return a.getPopulation() > b.getPopulation(); } return a.getLand() < b.getLand(); }
bool dreicmp(pair<string, unsigned>& a, pair<string, unsigned>& b) { return a.second > b.second; }


void printMenu() {
	cout << "[1] Alle Städte sortiert nach Land und Namen ausgeben" << endl
		<< "[2] Alle Städte sortiert nach Land und Einwohnerzahl ausgeben" << endl
		<< "[3] Länder und Gesamteinwohnerzahl in Millionenstädten ausgeben" << endl
		<< "[4] Alle Städte sortiert nach Einwohnerzahl im Jahr 2050 ausgeben" << endl << endl
		<< "[9] Programm beenden" << endl
		<< "Ihre Wahl :";

}

void ignoreLines(ifstream& infile, unsigned n, char d = '\n') {
	string dummy;
	for (unsigned i = 0; i < n; i++) {
		getline(infile, dummy, d);
	}
}

int main() {
	map<string, unsigned> nodupes;
	setlocale(LC_ALL, "");
	ifstream infile("Towns.txt", ios::in);
	vector<Town> towns;
	vector<pair<string, unsigned>> countries;
	//Ignore first three lines
	string temp;
	ignoreLines(infile, 3);
	//START READING IN//////////////////////
	string n, p, l, c;
	while (!infile.eof()) {
		getline(infile, n, ';');
		getline(infile, p, ';');
		getline(infile, l, ';');
		getline(infile, c);
		//break if incomplete entry or eof
		if (infile.eof())
			break;
		p.erase(remove(p.begin(), p.end(), '.'), p.end());
		l.erase(0, 3);
		c.erase(0,1);
		Town town(l, n, stoi(p), c);
		towns.push_back(town);
		pair<string, unsigned> toInsert = make_pair(l, 0);
		if (nodupes.insert(toInsert).second) {
			countries.push_back(toInsert);
		}
	}
	//FINISHED READING IN///////////////////



	char input;
	do {
		printMenu();
		cin >> input;
		switch (input) {
		case '1': {
			vector<Town> ltowns = towns;
			sort(ltowns.begin(), ltowns.end(), cmp);
			for (unsigned i = 0; i < ltowns.size(); i++) {
				cout << ltowns[i].toString();
			}
		}	break;



		case '2': {
			vector<Town> ptowns = towns;
			sort(ptowns.begin(), ptowns.end(), popcmp);
			for (unsigned i = 0; i < ptowns.size(); i++) {
				cout << ptowns[i].toString();
			}
		}	break;



		case '3': {
			for (auto& country : countries) {
				for (auto& town : towns) {
					if (country.first == town.getLand()) {
						country.second += town.getPopulation();
					}
				}
			}

			sort(countries.begin(), countries.end(), dreicmp);

			for (auto& country : countries) {
				cout << setfill('.') << country.first << setw(45 - country.first.length()) << country.second << endl;
			}

		}	break;



		case '4': {
			ifstream growth("Growth.txt", ios::in);
			vector<Town> gTowns = towns;
			map<string, double> growthMap;
			string past, future, name;
			ignoreLines(growth, 3); //Ignore first 3 lines
			while (!growth.eof()) {
				getline(growth, name, '\t');//Ignore descriptor
				getline(growth, past, '\t');//read in first value
				getline(growth, temp, '\t');//ignore middle value
				getline(growth, future);//read in last value
				if (growth.eof()) { break; }
				
				double rate = 1 + (stod(future)-stod(past))/stod(past);

				growthMap.insert(make_pair(name, rate));
			}
			
			for (auto& gTown : gTowns) {
				if (gTown.getContinent() == "Asien") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Asien"]);
				}
				else if (gTown.getContinent() == "Afrika") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Afrika"]);
				}
				else if (gTown.getContinent() == "Südamerika") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Südamerika"]);
				}
				else if (gTown.getContinent() == "Europa") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Europa"]);
				}
				else if (gTown.getContinent() == "Nordamerika") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Nordamerika"]);
				}
				else if (gTown.getContinent() == "Australien") {
					gTown.setPopulation(gTown.getPopulation()*growthMap["Australien"]);
				}
			}
			sort(gTowns.begin(), gTowns.end(), viercmp);
			for (auto& gTown : gTowns) {
				cout << gTown.toString();
			}
		}	break;

		case '9':
			cout << "Shutting down" << endl;
			break;
		default: cout << "Invalid Input!" << endl;
			break;
		}


	} while (input != '9');
}