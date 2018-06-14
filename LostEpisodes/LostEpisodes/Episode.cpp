#include "Episode.h"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>


Episode::Episode()
{
}

Episode::Episode(string nr, string titleGer, string titleEn, string content) :episodeNr(nr), titleGer(titleGer), titleEn(titleEn), content(content)
{
	map<string, int> wordCount;

	auto start = 0;
	auto end = 0;

	while ((start = content.find("<FLASHBACK>", end)) != string::npos) {
		end = content.find("</FLASHBACK>", start);
		string flashback = content.substr(start + 11, end - start - 12);
		flashbacks.push_back(flashback);
		stringstream flashbackStream(flashback);
		string word;
		while ((flashbackStream >> word).good()) {
			wordCount[word]++;
		}
	}

	auto cmp = [](pair<string, int> const & a, pair<string, int> const & b) {
		return a.second > b.second;
	};

	flashbackWords = vector<pair<string, int>>(wordCount.begin(), wordCount.end());

	std::sort(flashbackWords.begin(), flashbackWords.end(), cmp);

}

string Episode::getActors() {
	stringstream out;
	vector<string> actors;
	vector<int> actorMentions;
	ifstream actorfile("Hauptpersonen.txt", ios::in);
	string d;
	while (actorfile >> d) {
		actors.push_back(d);
		actorMentions.push_back(0);
	}

	for (auto i = 0; i < actors.size(); i++) {
		for (auto j = 0; j < flashbackWords.size();j++) {
			if(flashbackWords[j].first ==actors[i]) {
				actorMentions[i]+=flashbackWords[j].second;
				//actors.find(word) != actors.end()
			}
		}
	}
	bool moreThanOne =false;
	for (auto i = 0; i < actors.size();i++) {
		if(actorMentions[i]>4 && moreThanOne==false) {
			out << actors[i];
			moreThanOne = true;
		}else if(actorMentions[i]>4 && moreThanOne==true){
			out << ", " << actors[i];
		}
	}

	if(out.str().empty()) {
		return "keine spezielle";
	}
	return out.str();
}
