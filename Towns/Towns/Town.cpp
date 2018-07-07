#include "Town.h"
#include <sstream>
#include <iomanip>

Town::Town(string l, string n, int p, string c):land(l),name(n),population(p),continent(c)
{
}

string Town::toString()
{
	stringstream result;
	result << setfill('.') << land << setw(45-land.length()) << name << setw(30) << population << endl;
	return result.str();
}
