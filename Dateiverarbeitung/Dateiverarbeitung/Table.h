#pragma once
#include "Team.h"
#include <vector>

class Table
{
public:
	Table();
	~Table();
	void read(ifstream& file);
	string toString() const;
	void sort();
private:
	vector<Team> teams;
};