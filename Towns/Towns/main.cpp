#include "Town.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;


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

void ignoreLines(ifstream& infile,unsigned n,char d='\n') {
	string dummy;
	for (auto i = 0; i < n; i++) {
		getline(infile, dummy,d);
	}
}

int main() {
	map<string, unsigned> nodupes;
	setlocale(LC_ALL, "");
	ifstream infile("Towns.txt", ios::in);
	vector<Town> towns;
	vector<pair<string, unsigned>> countries;
	//Ignore first two lines
	string temp;
	getline(infile, temp);
	getline(infile, temp);
	getline(infile, temp);
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
			for (auto i = 0; i < ltowns.size(); i++) {
				cout << ltowns[i].toString();
			}
		}	break;

		case '2': {
			vector<Town> ptowns = towns;
			sort(ptowns.begin(), ptowns.end(), popcmp);
			for (auto i = 0; i < ptowns.size(); i++) {
				cout << ptowns[i].toString();
			}
		}	break;

		case '3': {
			for (auto i = 0; i < countries.size(); i++) {
				for (auto j = 0; j < towns.size(); j++) {
					if (countries[i].first == towns[j].getLand()) {
						countries[i].second += towns[j].getPopulation();
					}
				}
			}



			sort(countries.begin(), countries.end(),dreicmp);

			for (auto i = 0; i < countries.size(); i++) {
				cout << setfill('.') << countries[i].first << setw(45 - countries[i].first.length()) << countries[i].second << endl;
			}

		}	break;

		case '4': {
			ifstream growth("Growth.txt", ios::in);
			string sgAsien, sgAfrika, sgSamerika, sgEuropa, sgNamerika, sgAustralien;
			double gAsien, gAfrika, gSamerika, gEuropa, gNamerika, gAustralien;
			ignoreLines(growth, 4);
			getline(growth, temp, '\t');
			getline(growth, sgAsien, '\t');
			getline(growth, temp,'\t');

			getline(growth, sgAsien, '\t');



		}	break;

		case '9':
			cout << "Shutting down" << endl;
			break;
		default: cout << "Invalid Input!" << endl;
			break;
		}


	} while (input != '9');
}