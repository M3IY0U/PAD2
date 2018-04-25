#include "MastermindDigits.h"
#include <exception>
#include <stdexcept>
#include <vector>

//default
MastermindDigits::MastermindDigits() :digits(nullptr)
{
}
//copy
MastermindDigits::MastermindDigits(MastermindDigits& orig) {
	if (orig.digits == nullptr) {
		throw std::invalid_argument("Trying to copy from an object that has no digits set!\n");
	}
	digits = new unsigned int[4];
	for (auto i = 0; i < 4; i++) {
		digits[i] = orig.digits[i];
	}
}

//cast/convert
MastermindDigits::MastermindDigits(int origDigits) :digits(new unsigned int[4]{})
{
	unsigned tmp = origDigits;
	for (auto i = 4; i > 0; i--) {
		digits[i - 1] = tmp % 10;
		tmp /= 10;
	}
}
//dest
MastermindDigits::~MastermindDigits()
{
	if (digits != nullptr) {
		delete[] digits;
		digits = nullptr;
	}
}

void MastermindDigits::makeDigitsToGuess()
{
	if (digits == nullptr) {
		digits = new unsigned int[4];
	}
	unsigned int tmp;
	for (auto i = 0; i < 4; i++) {
		tmp = rand() % 6 + 1;
		digits[i] = tmp;
		show[i] = tmp;
	}
}

unsigned MastermindDigits::locationRight(MastermindDigits compare)
{
	auto result = 0;
	for (auto i = 0; i < 4; i++) {
		if (digits[i] == compare.digits[i]) {
			result++;
		}
	}
	return result;
}

unsigned MastermindDigits::locationWrong(MastermindDigits compare)
{
	if (locationRight(compare) == 4) { //check if locationWrong is even necessary
		return 0;
	}

	bool used[4] = { false,false,false,false };

	auto result = 0;
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			if (compare.digits[i] == digits[j] && !used[j]) {
				used[j] = true;
				result++;
				break;
			}
		}
	}
	return result - locationRight(compare);
}

MastermindDigits::operator unsigned int() const {
	if (digits == nullptr) { return 0; }
	int number = 0, factor = 1;
	for (int i = 3; i >= 0; i--) {
		number += digits[i] * factor;
		factor *= 10;
	}
	return number;
}

MastermindDigits& MastermindDigits::operator=(const MastermindDigits& orig)
{
	if (orig.digits == nullptr) {
		if (digits != nullptr) {
			delete[] digits;
			digits = nullptr;
		}
	}
	else {
		if (digits == nullptr) {
			digits = new unsigned int[4];
		}
		for (auto i = 0; i < 4; i++) {
			digits[i] = orig.digits[i];
		}
	}

	return *this;
}

std::string MastermindDigits::showNumber()
{
	std::string result = "----\n";
	for (auto i = 0; i < 4; i++) {
		result += std::to_string(digits[i]);
	}
	return result + "\n----\n";
}
