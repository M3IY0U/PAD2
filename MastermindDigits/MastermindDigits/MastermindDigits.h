#pragma once
#include <string>

class MastermindDigits
{
public:
	MastermindDigits();//default constructor
	MastermindDigits(MastermindDigits& orig); //copy constructor
	MastermindDigits(int origDigits);//cast/convert constructor
	~MastermindDigits();//destructor
	void makeDigitsToGuess();
	unsigned locationRight(MastermindDigits);
	unsigned locationWrong(MastermindDigits);
	operator unsigned int() const;
	MastermindDigits& operator=(const MastermindDigits& orig);// overloaded assignment operator
	std::string showNumber();
private:
	unsigned int* digits;
	unsigned int show[4];
};
