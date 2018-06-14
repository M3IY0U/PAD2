#include "Episode.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void printMenu() {
	cout
		<< "[1] Englische Episodentitel und Inhalt einer beliebigen Episode ausgeben" << endl
		<< "[2] Nur Rückblicke einer beliebigen Episode ausgeben" << endl
		<< "[3] Die 15 häufigsten Wörter der Rückblicke einer Episode ausgeben" << endl
		<< "[4] Hauptpersonen aller Episoden ausgeben" << endl
		<< "[9] Programm beenden" << endl
		<< "Ihre Wahl:";

}


int main() {
	setlocale(LC_ALL, "");
	map<string, Episode> episodes;

	ifstream input;
	input.open("Lost_Staffel_1.txt", ios::in);

	string tmp;
	//Erste Zeile ignorieren
	getline(input, tmp);

	//Episoden einlesen

	string episodennummer;
	string titelDeutsch;
	string titelEnglisch;
	string inhalt;

	while (getline(input, tmp, ' ').good()) {
		getline(input, episodennummer);
		getline(input, titelDeutsch, '(');
		getline(input, titelEnglisch, ')');
		getline(input, inhalt, '*');
		getline(input, tmp);

		Episode episode(episodennummer, titelDeutsch, titelEnglisch, inhalt);
		episodes.emplace(episodennummer, episode);
	}
	input.close();


	string episodenauswahl;
	char menuinput = '1';


	do {
		printMenu();
		cin >> menuinput;
		switch (menuinput) {
		case '1': {
			cout << left << setw(14) << "Episodennr." << setw(25) << "Engl. Episodentitel" << endl;
			for (auto &titel : episodes) {
				cout << setw(14) << titel.second.returnNr() << setw(25) << titel.second.returntitleEn() << endl;
			}

			cout << endl << "Inhalt von welcher Episode ausgeben:";
			cin >> episodenauswahl;
			cout << "Episode Nummer: " << episodes[episodenauswahl].returnNr() << endl
				<< "Deutscher Titel: " << episodes[episodenauswahl].returntitleGer() << endl
				<< "Englischer Titel: " << episodes[episodenauswahl].returntitleEn() << endl
				<< "Inhalt:" << episodes[episodenauswahl].returnContent() << endl << endl;
		}
				  break;


		case '2': {
			cout << "Von welcher Episode sollen die Rückblicke ausgegeben werden: ";
			cin >> episodenauswahl;
			cout << endl;
			int fbn = 1;
			//suchen von flashbacks
			Episode episode = episodes[episodenauswahl];
			for (const auto& fb : episode.getFlashbacks()) {
				cout << fbn++ << ". Flashback: " << fb << endl << endl;
			}
		}
				  break;


		case '3': {
			cout << left << "Von welcher Episode sollen die 15 häufigsten Wörter ausgegeben werden: ";
			cin >> episodenauswahl;
			Episode episode = episodes[episodenauswahl];

			for (auto i = 0; i < 15; i++) {
				cout << setw(4) << episode.getFlashbackWords()[i].second << setw(30) << episode.getFlashbackWords()[i].first << endl;
			}
		}
				  break;


		case '4': {

			cout << internal << "Episode" << setw(10) << "Titel" << setw(38) << "Hauptperson(en)" << endl;
			for (double i = 1.01; i < 1.25; i += 0.01) {
				string it = to_string(i);
				it.erase(4, string::npos);
				cout << left << setw(2) << it << "\t    " << internal << episodes[it].returntitleGer() << setw((43 - episodes[it].returntitleGer().size())) << internal << episodes[it].getActors() << endl;

			}
		}
				  break;


		case '9':
			break;


		default:
			cout << "Invalid Input!" << endl;
			break;
		}
	} while (menuinput != '9');
}