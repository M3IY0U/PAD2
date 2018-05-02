#pragma once
class Team
{
public:
	Team();
private:
	char teamName[20];
	int matchesPlayed;
	int gamesWon;
	int gamesLost;
	int pointsWon;
	int pointsLost;
};