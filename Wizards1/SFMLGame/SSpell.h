#pragma once

#include <SFML/Graphics.hpp>

#include "Spell.h"

class SSPELL : public SPELL
{
public:
	SSPELL();

	void checkSpellState();

private:
	char mKey[5];
};

SSPELL::SSPELL() : SPELL()
{
	//S,S,W,A,A

	mKey[0] = 'S';
	mKey[1] = 'S';
	mKey[2] = 'W';
	mKey[3] = 'A';
	mKey[4] = 'A';
}

void SSPELL::checkSpellState()
{
	std::cout << "Count: " << getCount() << std::endl;
	std::cout << "Value: " << getValue() << std::endl;
	std::cout << "Key: " << mKey[getCount()] << std::endl;

	setSuccess(false);
	setFailure(false);

	if (getSpellState() == true)
	{
		if (mKey[getCount()] == getValue())
		{
			setCount(getCount() + 1);

			if (getCount() < 5)
			{
				std::cout << "yup" << std::endl;
			}

			else
			{
				std::cout << "yay" << std::endl;
				setSuccess(true);
				setCount(0);
			}
		}

		else
		{
			std::cout << "nope" << std::endl;
			setFailure(true);
			setCount(0);
			setSpellState(false);
		}
	}
}