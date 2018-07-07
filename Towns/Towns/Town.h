#pragma once
#include <string>
using namespace std;

class Town
{
public:
	Town(string, string, int, string);
	string getLand() const { return land; }
	string getName() const { return name; }
	int getPopulation() const { return population; }
	string getContinent() const { return continent; }
	string toString();
private:
	string land;
	string name;
	int population;
	string continent;
};