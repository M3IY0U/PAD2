#include "Team.h"
#include <sstream>
#include <iomanip>

Team::Team()
{
}

Team::~Team()
{
}

string Team::toString()
{
	stringstream result;

	result << setw(24) << teamName << setw(15) << matchesPlayed << setw(15) << gamesWon << setw(15) << gamesLost << setw(15) << pointsWon << setw(15) << pointsLost << endl;

	return result.str();
}

ifstream & Team::read(ifstream & file)
{
	file.read(reinterpret_cast<char*>(this),sizeof(Team));
	return file;
}
