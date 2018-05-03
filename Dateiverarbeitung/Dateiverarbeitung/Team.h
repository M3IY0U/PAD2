#pragma once
#include <fstream>
#include <string>

using namespace std;

class Team
{
public:
	Team();
	~Team();
	string toString();
	ifstream& read(ifstream& file);
	bool operator<(Team comp) const;

private:
	char teamName[20];
	int matchesPlayed;
	int gamesWon;
	int gamesLost;
	int pointsWon;
	int pointsLost;
};