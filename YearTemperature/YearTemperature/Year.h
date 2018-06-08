#pragma once
#include <map>
#include <string>
using namespace std;
class Year
{
public:
	explicit Year(int);
	void readTemp(string, double);
	string printAverage();
	void calcTemps();
	double getAverage() const { return averageTemp; }
	pair<string, double> getHighest() const { return highestMonth; }
	pair<string, double> getLowest() const { return lowestMonth; }
	int getYear() const { return yearName; }
	pair<int, double> getFruehling() const { return fruehling; }
	pair<int, double> getSommer() const { return sommer; }
	pair<int, double> getHerbst() const { return herbst; }
	pair<int, double> getWinter() const { return winter; }

private:
	void calcLowestHighest();
	double calculateAverage();
	int yearName;
	map<string, double> months;
	double averageTemp;
	pair<string, double> highestMonth;
	pair<string, double> lowestMonth;
	pair<int, double> fruehling;
	pair<int, double> sommer;
	pair<int, double> herbst;
	pair<int, double> winter;
};