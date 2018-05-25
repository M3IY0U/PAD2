#include "Table.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

Table::Table()
{
}

Table::~Table()
{
}

void Table::read(ifstream & file)
{
	Team team;
	while (team.read(file)) {
		teams.push_back(team);
	}
}

void Table::write(ofstream & file)
{
	for (Team team : teams) {
		team.write(file);
	}
}

string Table::toString() const
{
	stringstream result;

	result << setw(24) << "Name" << setw(15) << "Gesp. Matches" << setw(15) << "Gew. Spiele" << setw(15) << "Verl. Spiele" << setw(15) << "Gew. Punkte" << setw(15) << "Verl. Punkte" << endl;

	for (Team team : teams) {
		result << team.toString();
	}

	return result.str();
}

void Table::sort()
{
	std::sort(teams.rbegin(), teams.rend());
}
