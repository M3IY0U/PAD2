#include "Code.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

void printMenu() {
	cout << "[1] Zeichen - Code - Paare nach Codelaenge sortiert ausgeben" << endl
		<< "[2] 'AT.txt' einlesen, codieren und Morsecode in Datei abspeichern" << endl
		<< "[3] 'ATCoded.txt' einlesen, decodieren und Text ausgeben" << endl
		<< "[4] Uebertragungsdauer berechnen" << endl
		<< "[9] Programm beenden" << endl
		<< "Ihre Wahl :";
}

bool einscmp(Code& a, Code& b) { return a.getCodeLength() < b.getCodeLength(); }



int main() {
	setlocale(LC_ALL, "");
	map<char, Code> cMap;
	vector<Code> characters;
	ifstream infile("Morse.txt", ios::in);
	string zeichen, code;
	//START READING IN///////
	while (!infile.eof()) {
		vector<char> choppedcode;
		getline(infile, zeichen, '\t');
		getline(infile, code);
		for (auto i = 0; i < code.length(); i++) {
			choppedcode.push_back(code[i]);
		}
		characters.emplace_back(zeichen[0], choppedcode);
		Code c(zeichen[0], choppedcode);
		pair<char, Code> toIns = make_pair(zeichen[0], c);
		cMap.insert(toIns);
	}
	//FINISHED READING IN///////
	char input;
	do {
		printMenu();
		cin >> input;
		switch (input) {
		case '1': {
			vector<Code> sortedCode = characters;
			cout << "Länge\t" << "Code\t" << "Zeichen" << endl;
			sort(sortedCode.begin(), sortedCode.end(), einscmp);
			for (Code c : sortedCode) {
				cout << c.toString();
			}
		}break;
		case '2': {
			ifstream at("AT.txt", ios::in);
			char c;
			vector<char> text;
			while (at.get(c)) {
				cout << c;
				text.push_back(c);
			}
			ofstream outfile("ATCoded.txt", ios::out);
			for (auto i = 0; i < text.size(); i++) {
				if (text[i] == ' ') {
					outfile << "    ";
					continue;
				}
				outfile << cMap[text[i]].getCode();
				if (i == text.size() - 2) { break; } //you didn't see anything
				outfile << "   ";
			}
			outfile.close();


		}break;
		case '3': {
			bool space = false;
			ifstream atcoded("ATCoded.txt", ios::in);
			if (!atcoded) {
				cout << "Datei wurde nicht gefunden!" << endl;
			}
			char c;
			string text;
			while (atcoded.get(c)) {
				text.append(1, c);
			}
			text.append(3, ' ');
			for (auto i = 0; i < text.length(); i++) {
				if (text[i] == ' ') {
					if (text[i + 1] == ' ') {
						if (text[i + 2] == ' ' && text[i + 3] == ' ' && text[i + 4] == ' ') {
							space = true;
						}

						string textsub = text.substr(0, i);
						vector<char> toDec(textsub.begin(), textsub.end());
						text.erase(0, text.find_first_not_of(" ", i));
						i = 0;
						for (auto j = 0; j < characters.size(); j++) {
							if (characters[j].getMorsecode() == toDec) {
								cout << characters[j].getCharacter();
								if (space) {
									cout << " ";
									space = false;
								}
							}

						}
					}
				}
			}
			cout << endl;

		}break;
		case '4': {

		}break;
		}
	} while (input != '9');

}