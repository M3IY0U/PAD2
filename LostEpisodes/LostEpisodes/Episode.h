#pragma once
#include <string>
#include <vector>

using namespace std;

class Episode
{
public:
	Episode();
	Episode(string nr, string titleGer, string titleEn, string content);
	string returnContent() const { return content; }
	string returntitleGer() const { return titleGer; }
	string returntitleEn() const { return titleEn; }
	string returnNr() const { return episodeNr; }
	vector<string> getFlashbacks() const { return flashbacks; }
	vector<pair<string,int>> getFlashbackWords() const { return flashbackWords; }
	string getActors();
private:
	string episodeNr;
	string titleGer;
	string titleEn;
	string content;
	vector<string> flashbacks;
	vector<pair<string, int>> flashbackWords;
};
