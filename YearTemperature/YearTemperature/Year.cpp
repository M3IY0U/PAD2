#include "Year.h"
#include <vector>

Year::Year(int yn) :yearName(yn), averageTemp(calculateAverage())
{
	months["Januar"] = 0;
	months["Februar"] = 0;
	months["März"] = 0;
	months["April"] = 0;
	months["Mai"] = 0;
	months["Juni"] = 0;
	months["Juli"] = 0;
	months["August"] = 0;
	months["September"] = 0;
	months["Oktober"] = 0;
	months["November"] = 0;
	months["Dezember"] = 0;
}

void Year::readTemp(string month, double temp)
{
	months[month] = temp;
}

string Year::printAverage()
{
	return to_string(yearName) + ": " + to_string(calculateAverage()) + "\n";
}


void Year::calcLowestHighest() {
	vector<string> stringMonths = { "Januar","Februar","März","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember" };
	highestMonth.first = "Januar";
	highestMonth.second = months["Januar"];
	lowestMonth.first = "Januar";
	lowestMonth.second = months["Januar"];
	for (auto i = 0; i < 12; i++) {
		if (highestMonth.second < months[stringMonths[i]]) {
			highestMonth.first = stringMonths[i];
			highestMonth.second = months[stringMonths[i]];
		}
		if (lowestMonth.second > months[stringMonths[i]]) {
			lowestMonth.first = stringMonths[i];
			lowestMonth.second = months[stringMonths[i]];
		}
	}
}



double Year::calculateAverage() {

	vector<string> stringMonths = { "Januar","Februar","März","April","Mai","Juni","Juli","August","September","Oktober","November","Dezember" };
	averageTemp = 0.0;
	for (auto i = 0; i < 12; i++) {
		averageTemp += months[stringMonths[i]];
	}
	averageTemp /= 12;
	return averageTemp;
}


void Year::calcTemps() {

	calculateAverage();
	calcLowestHighest();

	fruehling.first = yearName;
	sommer.first = yearName;
	herbst.first = yearName;
	winter.first = yearName;
	winter.second = (months["Januar"] + months["Februar"] + months["Dezember"]) / 3.0;
	fruehling.second = (months["März"] + months["April"] + months["Mai"]) / 3.0;
	sommer.second = (months["Juni"] + months["Juli"] + months["August"]) / 3.0;
	herbst.second = (months["September"] + months["Oktober"] + months["November"]) / 3.0;



}