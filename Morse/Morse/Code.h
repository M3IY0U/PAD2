#pragma once
#include <vector>

class Code
{
public:
	Code();
	Code(char c, std::vector<char> mc);
	std::string toString();

	char getCharacter() const { return character; }
	std::vector<char> getMorsecode() const { return morsecode; }
	unsigned getCodeLength() const { return codeLength; }
	std::string getCode();
private:
	char character;
	std::vector<char> morsecode;
	unsigned codeLength;

};
