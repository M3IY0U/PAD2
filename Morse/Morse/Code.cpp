#include "Code.h"
#include <sstream>
#include <iomanip>

Code::Code()
{
}

Code::Code(char c, std::vector<char> mc) :character(c), morsecode(mc), codeLength(0)
{
	for (auto i = 0; i < morsecode.size(); i++) {
		switch (morsecode[i]) {
		case ' ':
			codeLength++;
			break;
		case '.':
			codeLength++;
			break;
		case '-':
			codeLength += 3;
			break;
		}
	}
}

std::string Code::toString()
{
	std::stringstream result;
	result << codeLength << " \t";
	for (auto i = 0; i < morsecode.size(); i++) {
		result << morsecode[i];
	}
	result << std::setw(15 - morsecode.size()) << character << std::endl;
	return result.str();
}

std::string Code::getCode() {
	std::string result;
	for (auto i = 0; i < morsecode.size(); i++) {
		result += morsecode[i];
	}
	return result;
}
